#ifndef FDF_DRAWING_H
#define FDF_DRAWING_H

void put_pixel(t_application *application, t_vector2i pos, t_color color);
void draw_line(t_application *application, t_vector2i point_debut_line, t_vector2i point_fin_line, t_color color);
void draw_point(t_application *application, t_vector2i pos, t_color color, int size);
void draw_line_fade(t_application *app, t_vector2i point_debut_line, t_vector2i point_fin_line, t_color color_start, t_color color_end);
#endif
