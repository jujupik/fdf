#include "libft.h"

int		*ft_intparse_tab(char **tab)
{
    int i;
    int *result;
    int len;

    len = ft_tab_len(tab);
    result = ft_int_str_new(len);

    i = 0;
    while (tab[i] != NULL)
    {
        result[i] = ft_atoi(tab[i]);
        i++;
    }

    return (result);
}
