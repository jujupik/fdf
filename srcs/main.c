#include "fdf.h"

/*

[int] -> [int *] = &int
[int *] -> [int] = *int | int[x]
[int **] -> [int] = int[x][y]
[int **] -> [int *] = int[x]

struct avec un x dedans -> struct.x
struct * avec un x dedans -> struct->x | (*struct).x

struct ** avec un x dedans -> (*struct)->x

*/

static void draw_fdf(t_application *ptr_app, t_map *ptr_map)
{
    clear_screen(ptr_app);
    draw_t_map(ptr_app, ptr_map);
    render_screen(ptr_app);
}

int test(int key, void *param)
{
    t_application *ptr_app;
    t_map *ptr_map;

    ptr_app = ((void **)param)[0];
    ptr_map = ((void **)param)[1];
    if (key == K1_KEY)
        t_map_change_view_mode(ptr_map, ORTHOGONAL);
    else if (key == K2_KEY)
        t_map_change_view_mode(ptr_map, ISOMETRIC);
    else if (key == ESC_KEY)
        exit(0);
    else if (key == NKMN_KEY)
        t_map_change_height_ratio(ptr_map, -0.25f);
    else if (key == NKPL_KEY)
        t_map_change_height_ratio(ptr_map, +0.25f);
    else if (key == W_KEY)
        t_map_change_tile_offset(ptr_map, 0, -0.25f);
    else if (key == S_KEY)
        t_map_change_tile_offset(ptr_map, 0, +0.25f);
    else if (key == A_KEY)
        t_map_change_tile_offset(ptr_map, -0.25f, 0);
    else if (key == D_KEY)
        t_map_change_tile_offset(ptr_map, +0.25f, 0);
    else if (key == Q_KEY)
        t_map_change_zoom(ptr_map, 0.8f);
    else if (key == E_KEY)
        t_map_change_zoom(ptr_map, 1.2f);
    draw_fdf(ptr_app, ptr_map);
    return (0);
}

int main(int argc, char **argv)
{
    if (argc != 2)
        error_exit(1, "Bad number of argument -> try ./fdf [MAP_NAME]");

    t_application app = create_t_application("fdf", 840, 680);
    t_map map = create_t_map(argv[1]);
    draw_fdf(&app, &map);
    run_t_application(&app, test, &map);

    return (0);
}
