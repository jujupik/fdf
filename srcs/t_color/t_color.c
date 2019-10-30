#include "fdf.h"

t_color create_t_color(float p_r, float p_g, float p_b, float p_a)
{
    t_color result;

    result.r=p_r;
    result.g=p_g;
    result.b=p_b;
    result.a=p_a;
    return (result);
}
t_color *malloc_t_color(float p_r, float p_g, float p_b, float p_a)
{
    t_color *result;

    result=(t_color *)malloc(sizeof(t_color));
    if (result == NULL)
        error_exit(1, "Can't malloc t_color");
    *result= create_t_color(p_r, p_g, p_b, p_a);
    return (result);
}

void delete_t_color(t_color color)
{
    (void)color;
}

void free_t_color(t_color *color)
{
    delete_t_color(*color);
    free(color);
}

int convert_t_color(t_color color)
{
    int *tmp;

    tmp = (int *)(&color.r);
    return (*tmp);
}

void swap_t_color(t_color *a, t_color *b)
{
    t_color tmp_color;

    tmp_color = *a;
    *a = *b;
    *b = tmp_color;
}

t_color t_color_add(t_color a, t_color b)
{
    t_color result;

    result.r = a.r + b.r;
    result.g = a.g + b.g;
    result.b = a.b + b.b;
    result.a = (a.a + b.a) / 2;

    return (result);
}

t_color t_color_substract(t_color a, t_color b)
{
    t_color result;

    result.r = a.r - b.r;
    result.g = a.g - b.g;
    result.b = a.b - b.b;
    result.a = (a.a + b.a) / 2;
    return (result);
}

t_color t_color_mult(t_color a, t_color b)
{
    t_color result;

    result.r = a.r * b.r;
    result.g = a.g * b.g;
    result.b = a.b * b.b;
    result.a = (a.a + b.a) / 2;
    return (result);
}

t_color t_color_divide(t_color a, t_color b)
{
    t_color result;

    result.r = a.r / b.r;
    result.g = a.g / b.g;
    result.b = a.b / b.b;
    result.a = (a.a + b.a) / 2;
    return (result);
}

t_color t_color_add_int(t_color a, int delta)
{
    t_color result;

    result.r = a.r + delta;
    result.g = a.g + delta;
    result.b = a.b + delta;
    result.a = a.a;
    return (result);
}

t_color t_color_substract_int(t_color a, int delta)
{
    t_color result;

    result.r = a.r - delta;
    result.g = a.g - delta;
    result.b = a.b - delta;
    result.a = a.a;
    return (result);
}

t_color t_color_mult_by_int(t_color a, int delta)
{
    t_color result;

    result.r = a.r * delta;
    result.g = a.g * delta;
    result.b = a.b * delta;
    result.a = a.a;
    return (result);
}

t_color t_color_divide_by_int(t_color a, int delta)
{
    t_color result;

    result.r = a.r / delta;
    result.g = a.g / delta;
    result.b = a.b / delta;
    result.a = a.a;
    return (result);
}
