NAME=		fdf

##
##		RESSOURCES
##

##List every folder where he will find header
INC_DIR = 	$(shell find includes -type d) $(shell find ~/.brew/include -type d) \
			$(shell find lib/libft/includes -type d) \
			$(shell find lib/minilibx -type d)
##List every folder where he will find source files
SRC_DIR = 	$(shell find srcs -type d)
##Folder where he will store the .o
OBJ_DIR	=	obj
##Folder where you can find libraries
LIB_DIR = ~/.brew/lib ./lib/minilibx ./lib/libft


##Add to the vpath the folder find in SRC_DIR
vpath %.c $(foreach dir, $(SRC_DIR), $(dir):)

##Set the download program to brew
DWL =		brew

##List every .c found inside SRC_DIR
SRC =		handle_key.c \
			main.c \
			bresenham.c \
			generate_nbr.c \
			draw_line.c \
			draw_point.c \
			drawing_pixel.c \
			t_vector2i_list.c \
			t_vector2i_list_basics.c \
			t_application.c \
			t_application_basics.c \
			t_application_run.c \
			t_color.c \
			t_color_basics.c \
			t_color_calc.c \
			t_color_calc_int.c \
			t_map.c \
			t_map_basics.c \
			t_map_calc.c \
			t_map_calc_iso_ortho.c \
			t_map_change.c \
			t_map_color.c \
			t_map_draw.c \
			t_pixel.c \
			fdf_t_vector2f.c \
			fdf_t_vector2f_array.c \
			fdf_t_vector2i.c \
			fdf_t_vector2i_array.c

##Transform and place every .o from SRC
OBJ=		$(addprefix $(OBJ_DIR)/, $(SRC:%.c=%.o))

##List of libraries to download and install using the function defined in DWL
LIB_DWN =
##List of libraries to link while compiling
LIB = ft

##
##		COMPILER FLAGS
##

##Basics flags
CFLAGS=		-Werror -Wextra -Wall

##Create the flags to includes every .h needed by this program
IFLAGS =	$(foreach dir, $(INC_DIR), -I$(dir))

##Create the flags to link every libraries needed by this program (-L and -l)
LFLAGS = $(foreach lib_path, $(LIB_DIR),-L $(lib_path) ) $(foreach lib, $(LIB),-l$(lib) ) -framework OpenGL -framework AppKit -lmlx -L /usr/local/lib/

##Define the compiler to use
CC=			gcc

all:
				make $(NAME)

show:
	@echo "CFLAGS:\n$(CFLAGS)"
	@echo "IFLAGS:\n$(IFLAGS)"
	@echo "LFLAGS:\n$(LFLAGS)"
	@echo "INC_DIR:\n$(INC_DIR)"
	@echo "SRC_DIR:\n$(SRC_DIR)"
	@echo "LIB_DIR:\n$(LIB_DIR)"

install:
				make re -C lib/minilibx
				make re -C lib/libft

$(NAME):		$(OBJ)
				@echo "Compiling $(NAME) ...\c"
				@$(CC) $(CFLAGS) $(IFLAGS) $(LFLAGS) $(OBJ) -o $(NAME)
				@echo " DONE"

$(OBJ_DIR)/%.o : %.c
				@mkdir -p $(OBJ_DIR)
				@echo "Compiling $< ...\c"
				@$(CC) $(CFLAGS) $(IFLAGS) -o $@ -c $<
				@echo " DONE"

clean:
				@rm -rf $(OBJ_DIR)
				@echo "clean"

fclean:			clean
				@rm -f $(NAME)
				@echo "fclean"

re:				fclean all

.PHONY: all clean fclean re
