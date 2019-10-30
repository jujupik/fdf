#include "fdf.h"

t_vector2i   create_t_vector2i(int p_x, int p_y)
{
    t_vector2i result;

    result.x = p_x;
    result.y = p_y;
    return (result);
}

t_vector2i   *malloc_t_vector2i(int p_x, int p_y)
{
    t_vector2i   *result;

    result = (t_vector2i *)malloc(sizeof(t_vector2i));
    if (result == NULL)
        error_exit(32, "Can't malloc a t_vector2i");
    *result = create_t_vector2i(p_x, p_y);
    return (result);
}

void swap_t_vector2i(t_vector2i *a, t_vector2i *b)
{
    ft_swap_int(&(a->x), &(b->x));
    ft_swap_int(&(a->y), &(b->y));
}

BOOL is_t_vector2i_equal(t_vector2i a, t_vector2i b)
{
    if (a.x == b.x && a.y == b.y)
        return (TRUE);
    else
        return (FALSE);
}
