#include "libft.h"

int	ft_tab_len(char **tab)
{
    int i;

    i = 0;
    while (tab[i] != NULL)
    {
        i++;
    }
    return (i);
}
