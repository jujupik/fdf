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

    //
    nb_du_null = list->max_len / list->line_len;
    if (list->len == list->max_len - 1)
    {
        tmp = list->data;
        // creer un new
        list->data = new_t_vector2i_tab(nb_du_null);
        // copy
        copy_t_vector2i_tab(list->data, tmp);
        // ajoute la derniere ligne
        list->data[nb_du_null - 1] = new_t_vector2i_array(list->line_len);

        //on rajoute la longueur de la ligne au max len
        list->max_len += list->line_len;

        free(tmp);
    }

    nb_line = nb_du_null - 1;
    //Vis a vis de la ligne 00, les elements sont numerotes tel que :
    //Line 00 : [0] [1] [2] [3] [4]
    //Line 01 : [5] [6] [7] [8] [9]
    //Line 02 : [10][11][12][13][14]
    //
    //On cherche le numero par rapport a la ligne 02 de l'element 12.
    //Vis a vis de la ligne 02, les elements sont :
    //Line 02 : [0] [1] [2] [3] [4]
    //
    //Le numero 12 au total est donc le numero 2 vis a vis de la ligne 02
    //Pour calculer ce 2, on fait
    //1) on trouve son index vis a vis de la ligne 00 -> 12
    //2) on calcule le nombre d'element de toute les lignes au dessus de la 02
    //          ligne 2 = 2 ligne au dessus -> 2 * le nombre d'element (5 par ligne) = 10
    //3) on soustrait a l'index vis a vis de la ligne 00 notre nombre calcule au dessus
    //          12 - 10 = 2 -> c'est le numero de notre element dans la ligne 02

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
