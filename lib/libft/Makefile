NAME=		libft.a

##
##		RESSOURCES
##

##List every folder where he will find header
INC_DIR = 	$(shell find includes -type d)
##List every folder where he will find source file
SRC_DIR = 	$(shell find srcs -type d)
##Folder where he will store the .o
OBJ_DIR	=	obj
##Folder where you can find libraries
LIB_DIR = ~/.brew/lib


##Add to the vpath the folder find in SRC_DIR
vpath %.c $(foreach dir, $(SRC_DIR), $(dir):)

##Set the download program to brew
DWL =		brew

##List every .c found inside SRC_DIR
SRC = 		ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
	  ft_isdigit.c ft_isprint.c ft_itoa.c ft_memalloc.c ft_memccpy.c \
	  ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c \
	  ft_memset.c ft_putchar.c ft_putchar_fd.c ft_putendl.c \
	  ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c \
	  ft_putstr_fd.c ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c \
	  ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c \
	  ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c \
	  ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c \
	  ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strsplit.c ft_strstr.c \
	  ft_strsub.c ft_strtrim.c ft_tolower.c ft_toupper.c \
	  ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c \
	  ft_lstmap.c get_next_line.c error_exit.c ft_tab_len.c \
	  ft_intstr_new.c ft_inttab_new.c ft_tab_free.c ft_intparse_tab.c \
	  ft_inttab_cpy.c ft_puttab.c ft_putinttab.c ft_abs.c ft_swap_int.c \
	  ft_min.c ft_max.c ft_swap_float.c ft_get_leaks.c

##Transform and place every .o from SRC
OBJ=		$(addprefix $(OBJ_DIR)/, $(SRC:%.c=%.o))

##List of libraries to download and install using the function defined in DWL
LIB_DWN =
##List of libraries to link while compiling
LIB =

##
##		COMPILER FLAGS
##

##Basics flags
CFLAGS=		-Werror -Wextra -Wall

##Create the flags to includes every .h needed by this program
IFLAGS =	$(foreach dir, $(INC_DIR), -I$(dir))

##Create the flags to link every libraries needed by this program (-L and -l)
LFLAGS = $(foreach lib_path, $(LIB_DIR), -L $(lib_path)) $(foreach lib, $(LIB), -l$(lib))

##Define the compiler to use
CC=			gcc

all:
				make $(NAME)

install:
				make -C lib/minilibx


$(NAME):		$(OBJ)
				@echo "Compiling $(NAME) ...\c"
				@ar rc $(NAME) $(OBJ)
				@ranlib $(NAME)
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
