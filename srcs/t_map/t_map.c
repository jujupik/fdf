#include "fdf.h"

void create_point_on_screen(t_map *ptr_map)
{
    int i;

    ptr_map->point_on_screen = new_t_vector2i_tab(ptr_map->nb_elem.x);
    i = 0;
    while (i < ptr_map->nb_elem.x)
    {
        ptr_map->point_on_screen[i] = new_t_vector2i_array(ptr_map->nb_elem.y);
        i++;
    }
}

void reset_point_on_screen(t_map *ptr_map)
{
    int i;
    int j;

    i = 0;
    while (i < ptr_map->nb_elem.x)
    {
        j = 0;
        while (j < ptr_map->nb_elem.y)
        {
            ptr_map->point_on_screen[i][j] = create_t_vector2i(-1, -1);
            j++;
        }
        i++;
    }
}

t_map create_t_map(char *p_path)
{
    t_map result;
    int fd;
    char *line;

    result.path = p_path;
    result.nb_elem = create_t_vector2i(0, 0);
    result.tile_size = create_t_vector2i(50, 50);
    result.scaled_tile_size = create_t_vector2f(
            (float)(result.tile_size.x),
            (float)(result.tile_size.y));
    result.offset = create_t_vector2i(0, 0);
    result.zoom = -1.0f;
    result.height_ratio = 5.5f;
    result.view_mode = ORTHOGONAL;
    result.height_tab = NULL;
    fd = open(result.path, O_RDONLY);
    if (fd < 0)
        error_exit(1, "Can't open a file");
    while (get_next_line(fd, &line) > 0)
    {
        t_map_add_line(&result, line);
        free(line);
        line = NULL;
    }
    free(line);
    result.tile_offset = create_t_vector2f(((float)(result.nb_elem.x)
        - 1.0f) / 2.0f, ((float)(result.nb_elem.y) - 1.0f) / 2.0f);
    create_point_on_screen(&result);
    return(result);
}

t_map *malloc_t_map(char *p_path)
{
    t_map *result;

    result = (t_map *)malloc(sizeof(t_map));
    if (result == NULL)
        error_exit(34, "error malloc t_map");
    *result = create_t_map(p_path);
    return(result);
}

void delete_t_map(t_map map)
{
    (void)map;
}

void free_t_map(t_map *map)
{
    delete_t_map(*map);
    free(map);
}

void t_map_add_line(t_map *ptr_map, char *line)
{
    char **tab;
    int len;
    int **tmp;

    if (ptr_map == NULL && line == NULL)
        error_exit(24, "Error in t_map_add_line");
    tab = ft_strsplit(line, ' ');
    len = ft_tab_len(tab);
    if (ptr_map->nb_elem.x == 0)
        ptr_map->nb_elem.x = len;
    if (ptr_map->nb_elem.x != len)
        error_exit(1, "Bad line in ptr_map");
    ptr_map->nb_elem.y++;
    tmp = ft_inttab_new(ptr_map->nb_elem.y);
    if (ptr_map->height_tab != NULL)
    {
        ft_inttab_cpy(tmp, ptr_map->height_tab);
        free(ptr_map->height_tab);
    }
    ptr_map->height_tab = tmp;
    ptr_map->height_tab[ptr_map->nb_elem.y - 1] = ft_intparse_tab(tab);
    ft_tab_free(tab);
}

void t_map_change_view_mode(t_map *ptr_map, int new_view_mode)
{
    ptr_map->view_mode = new_view_mode;

    ptr_map->scaled_tile_size = create_t_vector2f(
            (float)(ptr_map->tile_size.x),
            (float)(ptr_map->tile_size.y)
        );
    ptr_map->zoom = -1.0f;
    ptr_map->offset = create_t_vector2i(0, 0);
    ptr_map->height_ratio = 5.5f;
}

void t_map_calc_zoom(t_application *ptr_app, t_map *ptr_map)
{
    t_vector2i points[4];
    int value[4];
    t_vector2i screen_size;
    float ratio[2];

    ptr_map->zoom = 1.0f;
    points[0] = convert_world_to_screen(ptr_map, -1, -1, 0);
    points[1] = convert_world_to_screen(ptr_map, ptr_map->nb_elem.x, -1, 0);
    points[2] = convert_world_to_screen(ptr_map, -1, ptr_map->nb_elem.y, 0);
    points[3] = convert_world_to_screen(ptr_map, ptr_map->nb_elem.x,
                ptr_map->nb_elem.y, 0);
    value[0] = ft_min(4, points[0].x, points[1].x, points[2].x, points[3].x);
    value[1] = ft_max(4, points[0].x, points[1].x, points[2].x, points[3].x);
    value[2] = ft_min(4, points[0].y, points[1].y, points[2].y, points[3].y);
    value[3] = ft_max(4, points[0].y, points[1].y, points[2].y, points[3].y);
    screen_size.x = value[1] - value[0];
    screen_size.y = value[3] - value[2];
    ratio[0] = ptr_app->size.x / (float)(screen_size.x);
    ratio[1] = ptr_app->size.y / (float)(screen_size.y);
    ptr_map->zoom = (ratio[0] < ratio[1] ? ratio[0] : ratio[1]);
    ptr_map->scaled_tile_size.x = ptr_map->zoom * ptr_map->tile_size.x;
    ptr_map->scaled_tile_size.y = ptr_map->zoom * ptr_map->tile_size.y
                        / (ptr_map->view_mode == ISOMETRIC ? 2 : 1);
    ptr_map->scaled_height_ratio = ptr_map->height_ratio * ptr_map->zoom;
}

void	t_map_calc_offset(t_application *ptr_app, t_map *ptr_map)
{
    int value[2];
    t_vector2i points[4];
    int reste_x;
    int reste_y;

    value[0] = ptr_map->nb_elem.x - 1;
    value[1] = ptr_map->nb_elem.y - 1;
    points[0] = convert_world_to_screen(ptr_map, 0, 0, 0);
    points[1] = convert_world_to_screen(ptr_map, value[0], 0, 0);
    points[2] = convert_world_to_screen(ptr_map, 0, value[1], 0);
    points[3] = convert_world_to_screen(ptr_map, value[0], value[1], 0);
    reste_x = ptr_app->size.x - points[1].x - points[2].x;
    reste_y = ptr_app->size.y - points[3].y - points[0].y;
    ptr_map->offset.x = reste_x / 2;
    ptr_map->offset.y = reste_y / 2;
    ptr_map->point_on_screen[0][0] = create_t_vector2i(-1, -1);

    ptr_map->point_on_screen[value[0]][0] = create_t_vector2i(-1, -1);
    ptr_map->point_on_screen[0][value[1]] = create_t_vector2i(-1, -1);
    ptr_map->point_on_screen[value[0]][value[1]] = create_t_vector2i(-1, -1);
}

void t_map_calc_data(t_application *ptr_app, t_map *ptr_map)
{
    if (ptr_map->zoom == -1)
    {
        t_map_calc_zoom(ptr_app, ptr_map);
        t_map_calc_offset(ptr_app, ptr_map);
    }
}

void t_map_change_height_ratio(t_map *ptr_map, float delta)
{
    ptr_map->height_ratio += delta;
    ptr_map->scaled_height_ratio = ptr_map->height_ratio * ptr_map->zoom;
}

void t_map_change_zoom(t_map *ptr_map, float delta)
{
    if (ptr_map->zoom + delta >= 0.25f)
    {
        ptr_map->zoom *= delta;
        ptr_map->scaled_height_ratio = ptr_map->height_ratio * ptr_map->zoom;
        ptr_map->scaled_tile_size.x = ptr_map->zoom * ptr_map->tile_size.x;
        ptr_map->scaled_tile_size.y = ptr_map->zoom * ptr_map->tile_size.y
                        / (ptr_map->view_mode == ISOMETRIC ? 2 : 1);
    }
}

void t_map_change_tile_offset(t_map *ptr_map, float delta_x, float delta_y)
{
    ptr_map->tile_offset.x += delta_x;
    ptr_map->tile_offset.y += delta_y;
}
