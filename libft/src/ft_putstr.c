#include "libft.h"

void ft_putstr(const char *s)
{
    while (*s)
        write(1, s++, 1);
}