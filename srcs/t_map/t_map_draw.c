#include "fdf.h"

static t_vector2i calc_iso(t_map *ptr_map, int x, int y, int height)
{
    t_vector2i result;

    result.x = ((x - ptr_map->tile_offset.x) - (y - ptr_map->tile_offset.y))
                * ptr_map->scaled_tile_size.x + ptr_map->offset.x;
    result.y = ((x - ptr_map->tile_offset.x) + (y - ptr_map->tile_offset.y))
                * ptr_map->scaled_tile_size.y + ptr_map->offset.y
                - height * ptr_map->scaled_height_ratio;

    return (result);
}

static t_vector2i calc_ortho(t_map *ptr_map, int x, int y, int height)
{
    t_vector2i result;

    result.x = (x - ptr_map->tile_offset.x) * ptr_map->scaled_tile_size.x
                        + ptr_map->offset.x;
    result.y = (y - ptr_map->tile_offset.y) * ptr_map->scaled_tile_size.y
                        + ptr_map->offset.y
                        - height * ptr_map->scaled_height_ratio;

    return (result);
}

t_vector2i convert_world_to_screen(t_map *ptr_map, int x, int y, int height)
{
    if (x < 0 || y < 0 || x >= ptr_map->nb_elem.x || y >= ptr_map->nb_elem.y)
    {
        if (ptr_map->view_mode == ORTHOGONAL)
            return (calc_ortho(ptr_map, x, y, height));
        else if(ptr_map->view_mode == ISOMETRIC)
            return (calc_iso(ptr_map, x, y, height));
    }
    if (is_t_vector2i_equal(ptr_map->point_on_screen[x][y], create_t_vector2i(-1, -1)) == TRUE)
    {
        if (ptr_map->view_mode == ORTHOGONAL)
            ptr_map->point_on_screen[x][y] = calc_ortho(ptr_map, x, y, height);
        else if(ptr_map->view_mode == ISOMETRIC)
            ptr_map->point_on_screen[x][y] = calc_iso(ptr_map, x, y, height);
    }

    return (ptr_map->point_on_screen[x][y]);
}

static void draw_map_tile(t_application *ptr_app, t_map *ptr_map, t_vector2i pos)
{
    t_vector2i actual;
    t_color colors[2];
    int height[2];

    colors[0] = create_t_color(255, 0, 0, 255);
    colors[1] = create_t_color(0, 255, 255, 255);
    height[0] = ptr_map->height_tab[pos.y][pos.x];
    actual = convert_world_to_screen(ptr_map, pos.x, pos.y, height[0]);
    if (pos.x + 1 < ptr_map->nb_elem.x)
    {
        height[1] = ptr_map->height_tab[pos.y][pos.x + 1];
        draw_line_fade(ptr_app, actual, convert_world_to_screen(ptr_map,
            pos.x + 1, pos.y, height[1]),
            (height[0] == 0 ? colors[0] : colors[1]),
            (height[1] == 0 ? colors[0] : colors[1]));
    }
    if (pos.y + 1 < ptr_map->nb_elem.y)
    {
        height[1] = ptr_map->height_tab[pos.y + 1][pos.x];
        draw_line_fade(ptr_app, actual, convert_world_to_screen(ptr_map,
            pos.x, pos.y + 1, height[1]),
            (height[0] == 0 ? colors[0] : colors[1]),
            (height[1] == 0 ? colors[0] : colors[1]));
    }
}

void draw_t_map(t_application *ptr_app, t_map *ptr_map)
{
    t_vector2i pos;

    reset_point_on_screen(ptr_map);
    t_map_calc_data(ptr_app, ptr_map);
    pos.x = 0;
    while (pos.x < ptr_map->nb_elem.x)
    {
        pos.y = 0;
        while (pos.y < ptr_map->nb_elem.y)
        {
            draw_map_tile(ptr_app, ptr_map, pos);
            pos.y++;
        }
        pos.x++;
    }
}
