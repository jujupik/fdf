#include "fdf.h"

void draw_point(t_application *app, t_vector2i pos, t_color color, int size)
{
    t_vector2i pixel;
    int i;
    int j;

    i = -size / 2;
    while (i <= size / 2)
    {
        j = -size / 2;
        while (j <= size / 2)
        {
            pixel.x = pos.x + i;
            pixel.y = pos.y + j;

            put_pixel(app, pixel, color);
            j++;
        }
        i++;
    }
}
