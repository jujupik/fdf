#ifndef FDF_T_MAP_H
#define FDF_T_MAP_H

typedef struct  s_map
{
    char *path;
    t_vector2i nb_elem;
    int **height_tab;
    t_vector2i tile_size;
    float zoom;
    t_vector2i offset;
    float height_ratio;
    int view_mode;
}               t_map;

t_map create_t_map(char *p_path);
t_map *malloc_t_map(char *p_path);
void delete_t_map(t_map map);
void free_t_map(t_map *ptr_map);
void t_map_add_line(t_map *ptr_map, char *line);
void draw_t_map(t_application *ptr_app, t_map *ptr_map);
void t_map_calc_zoom(t_application *ptr_app, t_map *ptr_map);
void t_map_calc_offset(t_application *ptr_app, t_map *ptr_map);
t_vector2i convert_world_to_screen(t_map *ptr_map, int x, int y, int height);
void t_map_change_view_mode(t_map *ptr_map, int new_view_mode);
void t_map_calc_data(t_application *ptr_app, t_map *ptr_map);
#endif
