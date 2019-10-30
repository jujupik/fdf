#ifndef FDF_T_MAP_H
#define FDF_T_MAP_H

typedef struct  s_map
{
    //Le chemin d'acces au fichier de map
    char *path;

    //La taille de la carte en x et y (Le nombre de tile sur x et sur y)
    t_vector2i nb_elem;
    //Les differentes hauteur des points en x et y
    int **height_tab;

    //La taille d'une tile
    t_vector2i tile_size;

    //Le zoom de la map
    float zoom;

    //L'offset de notre map
    t_vector2i offset;

    float   height_ratio;

    int view_mode;
}               t_map;

//Pour creer
t_map create_t_map(char *p_path);
t_map *malloc_t_map(char *p_path);

//Pour supprimer
void delete_t_map(t_map map);
void free_t_map(t_map *ptr_map);

void t_map_add_line(t_map *ptr_map, char *line);
void draw_t_map(t_application *ptr_app, t_map *ptr_map);

void t_map_calc_zoom(t_application *ptr_app, t_map *ptr_map);
t_vector2i convert_world_to_screen(t_map *ptr_map, int x, int y, int height);
void t_map_change_view_mode(t_map *ptr_map, int new_view_mode);

#endif
