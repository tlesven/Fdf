NAME = fdf
CFLAGS = cc -Wall -Wextra -Werror
OFLAGS = -I libft/includes/. -I ./includes/.
LFLAGS = -L libft -lft
LIB = libft/libft.a
MLIBX = -L/usr/X11/lib -lmlx -lXext -lX11
MKLIB = make -C
PATH_SRC = src
PATH_OBJ = obj
SRC = main.c\
	  list.c\
	  find_down_point.c\
	  draw.c\
	  ft_rainbow_line_draw.c\
	  color_lvl.c\
	  ft_init_mlx.c\
	  link_down.c\
	  pixel_on_img.c\
	  ft_line_draw_img.c\
	  singleton.c

OBJ = $(patsubst %.c, $(PATH_OBJ)/%.o, $(SRC))
INCLUDES = includes/fdf.h

all : $(NAME)

$(PATH_OBJ)/%.o : $(addprefix $(PATH_SRC)/, %.c) $(INCLUDES)
	@mkdir -p $(PATH_OBJ)
	@$(CFLAGS) $(OFLAGS) -o $@ -c $<

$(LIB) :
	@$(MKLIB) libft

$(NAME) : $(LIB) $(OBJ)
	@echo "\033[32m[ $(NAME) objects done ]\033[00m"
	@$(CFLAGS) -o $(NAME) $(OBJ) $(LFLAGS) $(MLIBX)
	@echo "\033[32m[ $(NAME) compiled ]\033[00m"

lib : $(LIB) $(NAME)
	@echo "\033[32m[ Library done && $(NAME) compiled ]\033[00m"

clean :
	@rm -f $(OBJ)
	@echo "\033[31m[ $(NAME) : objects deleted ]\033[00m"

fclean : clean
	@rm -f $(NAME)
	@echo "\033[31m[ $(NAME) : ./$(NAME) deleted ]\033[00m"

re : fclean all

.PHONY : fclean re clean all
