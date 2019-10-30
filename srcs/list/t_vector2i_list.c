#include "fdf.h"

t_vector2i_list   create_t_vector2i_list(int p_line_len)
{
    t_vector2i_list  result;

    result.line_len = p_line_len;
    result.data = new_t_vector2i_tab(1);
    result.data[0] = new_t_vector2i_array(result.line_len);
    result.len = 0;
    result.max_len = result.line_len;

    return (result);
}

t_vector2i_list   *malloc_t_vector2i_list(int p_line_len)
{
    t_vector2i_list *result;

    result = (t_vector2i_list *)malloc(sizeof(t_vector2i_list));
    if (result == NULL)
        error_exit(1, "Can't malloc t_vector2i_list");
    *result = create_t_vector2i_list(p_line_len);

    return (result);
}

void	             delete_t_vector2i_list(t_vector2i_list list)
{
    int i;

    i = 0;
    if (list.data == NULL)
        return ;
    while (list.data[i] != NULL)
    {
        free(list.data[i]);
        i++;
    }
    free(list.data);
}

void	             free_t_vector2i_list(t_vector2i_list *list)
{
    delete_t_vector2i_list(*list);
    free(list);
}

void	             t_vector2i_list_add(t_vector2i_list *list, t_vector2i to_add)
{
    t_vector2i **tmp;
    int nb_du_null;
    int nb_line;
    int nb_index;

    if (list->data == NULL)
        error_exit(1, "No data in t_vector2i_list");
    nb_du_null = list->max_len / list->line_len;
    if (list->len == list->max_len - 1)
    {
        tmp = list->data;
        list->data = new_t_vector2i_tab(nb_du_null);
        copy_t_vector2i_tab(list->data, tmp);
        list->data[nb_du_null] = new_t_vector2i_array(list->line_len);
        list->max_len += list->line_len;
        free(tmp);
    }
    nb_line = nb_du_null - 1;
    nb_index = list->len - (nb_line * list->line_len);
    list->data[nb_line][nb_index] = to_add;
    list->len++;
}

t_vector2i       t_vector2i_list_at(t_vector2i_list *list, size_t index)
{
    int nb_line;
    int elem;

    if ((int)index >= list->len)
        return(create_t_vector2i(-1, -1));
    nb_line = index / list->line_len;
    elem = index - (nb_line * list->line_len);

    return (list->data[nb_line][elem]);
}
