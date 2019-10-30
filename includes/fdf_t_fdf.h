#ifndef FDF_FDF_H
#define FDF_FDF_H

typedef struct s_fdf
{
    t_application *app;
    t_map *map;
}               t_fdf;

//Pour creer
t_fdf create_t_fdf(char *path);
t_fdf *malloc_t_fdf(char *path);

//Pour supprimer
void delete_t_fdf();
void free_t_fdf();

#endif
