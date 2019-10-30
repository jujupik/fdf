#include "fdf.h"

int	run_t_application(t_application *app, int funct_ptr(int, void *), void *param)
{
    void *ptr_strange[2];

    ptr_strange[0] = app;
    ptr_strange[1] = param;
    if (funct_ptr != NULL)
        mlx_hook(app->win_ptr, KEYPRESS, KEYPRESSMASK, funct_ptr, ptr_strange);
    mlx_loop(app->mlx_ptr);

    return (0);
}
