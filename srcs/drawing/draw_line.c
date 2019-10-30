#include "fdf.h"

void draw_line(t_application *app, t_vector2i start,
                t_vector2i end, t_color color)
{
    int index;
    t_vector2i pixel;
    t_vector2i_list pixels;

    pixels = calc_line_2d(start, end);
    index = 0;
    while (index < pixels.len)
    {
        pixel = t_vector2i_list_at(&pixels, index);
        put_pixel(app, pixel, color);
        index++;
    }
}

void draw_line_fade(t_application *app, t_vector2i start,
                t_vector2i end, t_color cstart, t_color cend)
{
    int index;
    t_vector2i pixel;
    t_vector2i_list pixels;
    t_color pixel_color;
    t_color delta;

    pixel_color = cstart;
    pixels = calc_line_2d(start, end);
    if (is_t_vector2i_equal(t_vector2i_list_at(&pixels, 0), start) == FALSE)
        swap_t_color(&cstart, &cend);
    delta = t_color_divide_by_int(t_color_substract(cend, cstart), pixels.len);
    index = 0;
    while (index < pixels.len)
    {
        pixel = t_vector2i_list_at(&pixels, index);
        put_pixel(app, pixel, pixel_color);
        pixel_color = t_color_add(pixel_color, delta);
        index++;
    }
}
