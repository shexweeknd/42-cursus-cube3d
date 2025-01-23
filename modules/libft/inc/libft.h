#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

/*GNL*/
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

size_t	ft_strlen(const char *s);
void	ft_putstr(const char *s);
char	*get_next_line(int fd);
void	ft_bzero(void *s, size_t n);
int		ft_atoi(const char *str);

#endif