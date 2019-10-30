#include "fdf.h"

void put_pixel(t_application *app, t_vector2i pos, t_color color)
{
    if (pos.x < 0 || pos.y < 0 || pos.x >= app->size.x || pos.y >= app->size.y)
        return ;

    int nb;
    // calcul bizarre du nb = a + c * b
    nb = (pos.x + pos.y * app->size.x) * 4;

    if (nb < 0 || nb >= app->size.x * app->size.y * 4)
        return ;

    app->pixels[nb] = color.b;
    app->pixels[nb + 1] = color.g;
    app->pixels[nb + 2] = color.r;
}
