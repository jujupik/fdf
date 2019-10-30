#include "fdf.h"

static void yolo(t_application *app, t_vector2i start,
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
    delete_t_vector2i_list(pixels);
}

void draw_line(t_application *ptr_app, t_vector2i start,
                t_vector2i end, t_color color)
{
    draw_line_fade(ptr_app, start, end, color, color);
}

void draw_line_fade(t_application *ptr_app, t_vector2i start,
                t_vector2i end, t_color cstart, t_color cend)
{
    if (
        is_point_on_screen(ptr_app, start) == TRUE ||
        is_point_on_screen(ptr_app, end) == TRUE ||
        (start.x < 0 && end.x > 0 && ((start.y > 0 && start.y < ptr_app->size.x) || (end.y > 0 && end.y < ptr_app->size.y))) ||
        (start.x > 0 && end.x < 0 && ((start.y > 0 && start.y < ptr_app->size.x) || (end.y > 0 && end.y < ptr_app->size.y))) ||
        (start.y < 0 && end.x > 0 && ((start.x > 0 && start.x < ptr_app->size.x) || (end.x > 0 && end.x < ptr_app->size.x))) ||
        (start.y > 0 && end.x < 0 && ((start.x > 0 && start.x < ptr_app->size.x) || (end.x > 0 && end.x < ptr_app->size.x)))
    )
    yolo(ptr_app, start, end, cstart, cend);
}
