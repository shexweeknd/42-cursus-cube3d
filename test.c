#include "mlx.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

// $ cc -I./modules/minilibx-linux test.c -g -L./modules/minilibx-linux -lmlx -lX11 -lXext -lm 

#define WIN_WIDTH 800
#define WIN_HEIGHT 600
#define MAP_WIDTH 8
#define MAP_HEIGHT 8
#define TILE_SIZE 64
#define FOV M_PI / 3  // 60° de champ de vision
#define NUM_RAYS 120  // Nombre de rayons à tracer
#define PLAYER_SPEED 5
#define ROTATION_SPEED 0.1

typedef struct s_player {
    double x, y;
    double angle;
} t_player;

typedef struct s_data {
    void *mlx;
    void *win;
    t_player player;
} t_data;

// Carte du monde (1 = mur, 0 = espace vide)
int world_map[MAP_HEIGHT][MAP_WIDTH] = {
    {1,1,1,1,1,1,1,1},
    {1,0,0,0,0,0,0,1},
    {1,0,1,0,0,1,0,1},
    {1,0,0,0,0,0,0,1},
    {1,0,1,0,0,1,0,1},
    {1,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1}
};

// Fonction pour détecter une collision avec un mur
int is_wall(double x, double y) {
    int grid_x = (int)(x / TILE_SIZE);
    int grid_y = (int)(y / TILE_SIZE);
    if (grid_x < 0 || grid_x >= MAP_WIDTH || grid_y < 0 || grid_y >= MAP_HEIGHT)
        return 1;
    return world_map[grid_y][grid_x];
}

// Tracer une ligne pour représenter un rayon
void draw_line(void *mlx, void *win, int x0, int y0, int x1, int y1, int color) {
    int dx = abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
    int dy = -abs(y1 - y0), sy = y0 < y1 ? 1 : -1;
    int err = dx + dy, e2;
    
    while (1) {
        mlx_pixel_put(mlx, win, x0, y0, color);
        if (x0 == x1 && y0 == y1) break;
        e2 = 2 * err;
        if (e2 >= dy) { err += dy; x0 += sx; }
        if (e2 <= dx) { err += dx; y0 += sy; }
    }
}

// Fonction de raycasting
void cast_rays(t_data *data) {
    double ray_angle, ray_x, ray_y, dx, dy;
    int hit, wall_height, wall_top, wall_bottom;
    
    for (int i = 0; i < NUM_RAYS; i++) {
        ray_angle = data->player.angle - (FOV / 2) + (i * FOV / NUM_RAYS);
        ray_x = data->player.x;
        ray_y = data->player.y;
        
        dx = cos(ray_angle) * 5;
        dy = sin(ray_angle) * 5;
        
        hit = 0;
        while (!hit) {
            ray_x += dx;
            ray_y += dy;
            if (is_wall(ray_x, ray_y)) hit = 1;
        }
        
        // Calcul de la distance corrigée (évite l'effet fish-eye)
        double distance = sqrt((ray_x - data->player.x) * (ray_x - data->player.x) + 
                               (ray_y - data->player.y) * (ray_y - data->player.y));
        distance *= cos(ray_angle - data->player.angle); 

        // Calcul de la hauteur du mur
        wall_height = (TILE_SIZE * WIN_HEIGHT) / distance;
        wall_top = (WIN_HEIGHT / 2) - (wall_height / 2);
        wall_bottom = (WIN_HEIGHT / 2) + (wall_height / 2);

        // Dessiner la colonne du mur
        for (int y = wall_top; y < wall_bottom; y++) {
            if (y >= 0 && y < WIN_HEIGHT)
                mlx_pixel_put(data->mlx, data->win, i * (WIN_WIDTH / NUM_RAYS), y, 0xFFFFFF);
        }
    }
}

// Gestion des touches clavier
int key_hook(int keycode, t_data *data) {
    if (keycode == 65307) // ESC
        exit(0);
    if (keycode == 119) { // W (avancer)
        double new_x = data->player.x + cos(data->player.angle) * PLAYER_SPEED;
        double new_y = data->player.y + sin(data->player.angle) * PLAYER_SPEED;
        if (!is_wall(new_x, new_y)) {
            data->player.x = new_x;
            data->player.y = new_y;
        }
    }
    if (keycode == 115) { // S (reculer)
        double new_x = data->player.x - cos(data->player.angle) * PLAYER_SPEED;
        double new_y = data->player.y - sin(data->player.angle) * PLAYER_SPEED;
        if (!is_wall(new_x, new_y)) {
            data->player.x = new_x;
            data->player.y = new_y;
        }
    }
    if (keycode == 97) // A (tourner à gauche)
        data->player.angle -= ROTATION_SPEED;
    if (keycode == 100) // D (tourner à droite)
        data->player.angle += ROTATION_SPEED;

    mlx_clear_window(data->mlx, data->win);
    cast_rays(data);
    return 0;
}

int main() {
    t_data data;
    
    data.mlx = mlx_init();
    data.win = mlx_new_window(data.mlx, WIN_WIDTH, WIN_HEIGHT, "Raycasting 3D");
    data.player.x = TILE_SIZE * 3;
    data.player.y = TILE_SIZE * 3;
    data.player.angle = M_PI / 4;
    
    cast_rays(&data);
    mlx_key_hook(data.win, key_hook, &data);
    mlx_loop(data.mlx);
    return 0;
}
