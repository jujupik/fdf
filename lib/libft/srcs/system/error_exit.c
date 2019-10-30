#include "libft.h"

void	error_exit(int nb, char *str)
{
    ft_putstr("Error [");
    ft_putnbr(nb);
    ft_putstr("] : ");
    ft_putstr(str);
    ft_putstr("\n");
    exit(nb);
}
