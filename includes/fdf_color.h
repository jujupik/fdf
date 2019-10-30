#ifndef FDF_COLOR_H
#define FDF_COLOR_H

typedef struct s_color
{
    float r;
    float g;
    float b;
    float a;
}               t_color;

t_color create_t_color(float p_r, float p_g, float p_b, float p_a);
t_color *malloc_t_color(float p_r, float p_g, float p_b, float p_a);
void delete_t_color(t_color color);
void free_t_color(t_color *color);
void swap_t_color(t_color *a, t_color *b);
t_color t_color_add(t_color a, t_color b);
t_color t_color_substract(t_color a, t_color b);
t_color t_color_mult(t_color a, t_color b);
t_color t_color_divide(t_color a, t_color b);
t_color t_color_add_int(t_color a, int delta);
t_color t_color_substract_int(t_color a, int delta);
t_color t_color_mult_by_int(t_color a, int delta);
t_color t_color_divide_by_int(t_color a, int delta);

#endif
