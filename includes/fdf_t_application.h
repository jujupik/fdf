#ifndef FDF_T_APPLICATION_H
#define FDF_T_APPLICATION_H

//C'est le programme
typedef struct  s_application
{
    void *mlx_ptr;
    void *win_ptr;
    t_vector2i size;
    void *img_ptr;
    unsigned char *pixels;
    int bpp;
    int line_size;
    int endian;

}               t_application;

t_application   create_t_application(char *prog_name, int width, int height);
t_application   *malloc_t_application(char *prog_name, int width, int height);
void	delete_t_application(t_application application);
void	free_t_application(t_application *application);
void clear_screen(t_application *application);
void render_screen(t_application *application);
int	run_t_application(t_application *application, int funct_ptr(int, void *), void *param);
#endif
