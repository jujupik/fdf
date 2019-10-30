#include "fdf.h"

t_vector2f **new_t_vector2f_tab(size_t size)
{
    t_vector2f **result;
    size_t i;

    result = (t_vector2f **)malloc(sizeof(t_vector2f *) * (size + 1));
    if (result == NULL)
        error_exit(1, "Can't malloc a t_vector2f **");
    i = 0;
    while (i < size + 1)
    {
        result[i] = NULL;
        i++;
    }
    return (result);
}

t_vector2f *new_t_vector2f_array(size_t size)
{
    t_vector2f *result;
    size_t i;

    result = (t_vector2f *)malloc(sizeof(t_vector2f) * size);
    if (result == NULL)
        error_exit(1, "Can't malloc a t_vector2f *");
    i = 0;
    while (i < size)
    {
        result[i] = create_t_vector2f(0, 0);
        i++;
    }
    return (result);
}

void copy_t_vector2f_tab(t_vector2f **dest, t_vector2f **src)
{
    int i;

    i = 0;
    while (src[i] != NULL)
    {
        dest[i] = src[i];
        i++;
    }
}
