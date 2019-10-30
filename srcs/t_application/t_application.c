#include "fdf.h"

t_application   create_t_application(char *prog_name, int width, int height)
{
    t_application result;

    result.mlx_ptr = NULL;
    result.win_ptr = NULL;
    result.mlx_ptr = mlx_init();
    if (result.mlx_ptr == NULL)
        error_exit(1, "Can't create a window");

    result.win_ptr = mlx_new_window(result.mlx_ptr, width, height, prog_name);
    result.size = create_t_vector2i(width, height);
    result.img_ptr = mlx_new_image(result.mlx_ptr, width, height);
    result.pixels = (unsigned char *)(mlx_get_data_addr(result.img_ptr,
            &(result.bpp), &(result.line_size), &(result.endian)));

    return (result);
}

t_application   *malloc_t_application(char *prog_name, int width, int height)
{
    t_application   *result;

    result = (t_application *)malloc(sizeof(t_application));
    if (result == NULL)
        error_exit(1, "Error malloc_t_application");
    *result = create_t_application(prog_name, width, height);

    return (result);
}

void	delete_t_application(t_application app)
{
    if (mlx_destroy_image(app.mlx_ptr, app.img_ptr) == 0)
        error_exit(1, "Can't destroy image");
    if (mlx_destroy_window(app.mlx_ptr, app.win_ptr) == 0)
        error_exit(1, "Can't destroy a window");
    app.pixels = NULL;
    app.img_ptr = NULL;
    app.mlx_ptr = NULL;
    app.win_ptr = NULL;
}

void	free_t_application(t_application *app)
{
    delete_t_application(*app);
    free(app);
}

#define B_COMP 0
#define G_COMP 1
#define R_COMP 2
#define A_COMP 3

void clear_screen(t_application *app)
{
    t_color background;
    int nb_pixel;
    int i;

    i = 0;
    background = create_t_color(25, 25, 25, 255);
    nb_pixel = app->size.x * app->size.y;
    while (i < nb_pixel)
    {
        int pixel = i * 4;
        app->pixels[pixel + B_COMP] = background.b;
	    app->pixels[pixel + G_COMP] = background.g;
	    app->pixels[pixel + R_COMP] = background.r;
        i++;
    }
}

void render_screen(t_application *app)
{
    int ret;

    ret = mlx_put_image_to_window(app->mlx_ptr, app->win_ptr,
                app->img_ptr, 0, 0);
    if (ret == 0)
        error_exit(1, "Can't render screen");
}

BOOL is_point_on_screen(t_application *ptr_app, t_vector2i point)
{
    if (point.x < 0 || point.x >= ptr_app->size.x || point.y < 0 || point.y >= ptr_app->size.y)
        return (FALSE);
    return (TRUE);
}
