#ifndef FDF_VECTOR_H
#define FDF_VECTOR_H

typedef struct	s_vector2_int
{
    int			x;
    int			y;
}				t_vector2i;

t_vector2i   create_t_vector2i(int p_x, int p_y);
t_vector2i   *malloc_t_vector2i(int p_x, int p_y);

void print_t_vector2i(t_vector2i vector);
void swap_t_vector2i(t_vector2i *a, t_vector2i *b);

t_vector2i **new_t_vector2i_tab(size_t size);
t_vector2i *new_t_vector2i_array(size_t size);
void copy_t_vector2i_tab(t_vector2i **dest, t_vector2i **src);
BOOL is_t_vector2i_equal(t_vector2i a, t_vector2i b);

#endif
