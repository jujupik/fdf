#include "fdf.h"

t_map create_t_map(char *p_path)
{
    t_map result;
    int fd;
    char *line;

    result.path = p_path;

    result.nb_elem = create_t_vector2i(0, 0);
    result.tile_size = create_t_vector2i(50, 50);
    result.offset = create_t_vector2i(0, 0);
    result.zoom = -1.0f;
    result.height_ratio = 5.5f;
    result.view_mode = ORTHOGONAL;

    //Open(Le chemin d'acces au fichier voulu, les flags d'ouvertures)
    fd = open(result.path, O_RDONLY);
    if (fd < 0)
        error_exit(1, "Can't open a file");

    while (get_next_line(fd, &line) > 0)
        t_map_add_line(&result, line);

    return(result);
}

t_map *malloc_t_map(char *p_path)
{
    t_map *result;

    //la destination = (le type de la destinatione)malloc(sizeof(la destination - 1*) * le nombre de truc a malloc)
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
    tmp[ptr_map->nb_elem.y - 1] = ft_intparse_tab(tab);
    ptr_map->height_tab = tmp;
    ft_tab_free(tab);
}

void t_map_change_view_mode(t_map *ptr_map, int new_view_mode)
{
    ptr_map->view_mode = new_view_mode;

    ptr_map->zoom = -1.0f;
    ptr_map->offset = create_t_vector2i(0, 0);
    ptr_map->height_ratio = 5.5f;
}
