/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:02:40 by hramaros          #+#    #+#             */
/*   Updated: 2025/01/28 13:02:41 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
char	*ft_strrchr(const char *str, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *s);
char	*ft_strndup(const char *s, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strnew(size_t size, char c);

#endif