#include "fdf.h"

t_vector2i convert_world_to_screen(t_map *ptr_map, int x, int y, int height)
{
    t_vector2i result;

    if (ptr_map->view_mode == ORTHOGONAL)
    {
        result.x = x * ptr_map->tile_size.x * ptr_map->zoom + ptr_map->offset.x;
        result.y = y * ptr_map->tile_size.y * ptr_map->zoom + ptr_map->offset.y - height * ptr_map->height_ratio * ptr_map->zoom;
    }
    else if(ptr_map->view_mode == ISOMETRIC)
    {
        result.x = (x - y) * ptr_map->tile_size.x * ptr_map->zoom + ptr_map->offset.x;
        result.y = (x + y) * ptr_map->tile_size.y / 2 * ptr_map->zoom + ptr_map->offset.y - height * ptr_map->height_ratio * ptr_map->zoom;
    }
    else
    {
        result.x = -1;
        result.y = -1;
    }

    return (result);
}

void t_map_calc_zoom(t_application *ptr_app, t_map *ptr_map)
{
    t_vector2i haut_gauche;
    t_vector2i haut_droite;
    t_vector2i bas_gauche;
    t_vector2i bas_droite;

    int x_min;
    int x_max;
    int y_min;
    int y_max;

    int map_size_on_screen_x;
    int map_size_on_screen_y;

    float map_ratio_on_screen_x;
    float map_ratio_on_screen_y;

    ptr_map->zoom = 1.0f;

    haut_gauche = convert_world_to_screen(ptr_map, -1, -1, 0);//x = 0 / y = 0
    haut_droite = convert_world_to_screen(ptr_map, ptr_map->nb_elem.x, -1, 0);//x = 10 / y = 0
    bas_gauche = convert_world_to_screen(ptr_map, -1, ptr_map->nb_elem.y, 0);//x = 0 / y = 10
    bas_droite = convert_world_to_screen(ptr_map, ptr_map->nb_elem.x, ptr_map->nb_elem.y, 0);//x = 10 / y = 10

    x_min = ft_min(4, haut_gauche.x, haut_droite.x, bas_gauche.x, bas_droite.x);
    x_max = ft_max(4, haut_gauche.x, haut_droite.x, bas_gauche.x, bas_droite.x);

    y_min = ft_min(4, haut_gauche.y, haut_droite.y, bas_gauche.y, bas_droite.y);
    y_max = ft_max(4, haut_gauche.y, haut_droite.y, bas_gauche.y, bas_droite.y);

    map_size_on_screen_x = x_max - x_min;
    map_size_on_screen_y = y_max - y_min;

    map_ratio_on_screen_x = ptr_app->size.x / (float)(map_size_on_screen_x);
    map_ratio_on_screen_y = ptr_app->size.y / (float)(map_size_on_screen_y);

    ptr_map->zoom = map_ratio_on_screen_x;
    if (ptr_map->zoom > map_ratio_on_screen_y)
        ptr_map->zoom = map_ratio_on_screen_y;
}

void	t_map_calc_offset(t_application *ptr_app, t_map *ptr_map)
{
    t_vector2i haut_gauche;
    t_vector2i haut_droite;
    t_vector2i bas_gauche;
    t_vector2i bas_droite;
    int reste_x;
    int reste_y;
    //
    haut_gauche = convert_world_to_screen(ptr_map, 0, 0, 0);//x = 0 / y = 0
    haut_droite = convert_world_to_screen(ptr_map, ptr_map->nb_elem.x - 1, 0, 0);//x = 10 / y = 0
    bas_gauche = convert_world_to_screen(ptr_map, 0, ptr_map->nb_elem.y - 1, 0);//x = 0 / y = 10
    bas_droite = convert_world_to_screen(ptr_map, ptr_map->nb_elem.x - 1, ptr_map->nb_elem.y - 1, 0);//x = 10 / y = 10

    reste_x = ptr_app->size.x - haut_droite.x - bas_gauche.x;
    reste_y = ptr_app->size.y - bas_droite.y - haut_gauche.y;
    // ptr_map->offset = reste_x / 2 et reste_y / 2
    ptr_map->offset.x = reste_x / 2;
    ptr_map->offset.y = reste_y / 2;
}

//convert_world_to_screen(ptr_map, i + 1 , y, ptr_map->height_tab[j][i + 1])
void draw_t_map(t_application *ptr_app, t_map *ptr_map)
{
    t_vector2i actual_point_on_screen;
    t_vector2i target_point_on_screen;
    t_color flat;
    t_color not_flat;
    t_color color_start;
    t_color color_end;
    int height;
    int target_height;
    int x;
    int y;

    flat = create_t_color(255, 0, 0, 255);
    not_flat = create_t_color(0, 255, 255, 255);
    if (ptr_map->zoom == -1)
    {
        t_map_calc_zoom(ptr_app, ptr_map);
        t_map_calc_offset(ptr_app, ptr_map);
    }
    x = 0;
    while (x < ptr_map->nb_elem.x)
    {
        y = 0;
        while (y < ptr_map->nb_elem.y)
        {
            height = ptr_map->height_tab[y][x];
            actual_point_on_screen = convert_world_to_screen(ptr_map, x, y, height);
            //draw_point(ptr_app, actual_point_on_screen, create_t_color(255, 0, 0, 255), 5);
            if (x + 1 < ptr_map->nb_elem.x)
            {
                target_height = ptr_map->height_tab[y][x + 1];
                target_point_on_screen = convert_world_to_screen(ptr_map, x + 1, y, target_height);
                color_start = (height == 0 ? flat : not_flat);
                color_end = (target_height == 0 ? flat : not_flat);
                draw_line_fade(ptr_app, actual_point_on_screen, target_point_on_screen, color_start, color_end);
            }
            if (y + 1 < ptr_map->nb_elem.y)
            {
                target_height = ptr_map->height_tab[y + 1][x];
                target_point_on_screen = convert_world_to_screen(ptr_map, x, y + 1, target_height);
                color_start = (height == 0 ? flat : not_flat);
                color_end = (target_height == 0 ? flat : not_flat);
                draw_line_fade(ptr_app, actual_point_on_screen, target_point_on_screen, color_start, color_end);
            }

            y++;
        }
        x++;
    }
}
