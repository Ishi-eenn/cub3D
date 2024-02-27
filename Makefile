NAME = cub3D

SRC_DIR		=	srcs
SRC			=	main.c
SRCS		=	$(addprefix $(SRC_DIR)/, $(SRC))

OBJ_DIR = objs
OBJS := $(subst $(SRC_DIR), $(OBJ_DIR), $(SRCS:.c=.o))
DEPS = $(OBJS:.o=.d)

CFLAGS = -Wall -Wextra -Werror -MP -MMD -O3
RM = rm -rf
INCLUDES = -I ./includes -I ./libft/includes -I ./mlx
LIBFT = libft/libft.a

ifeq ($(MAKECMDGOALS), debug)
	CFLAGS += -DDEBUG
endif

ifeq ($(MAKECMDGOALS), address)
	CFLAGS += -g3 -fsanitize=address
endif

all : $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	$(MAKE) -C ./mlx
	$(CC) $(CFLAGS) -o $@ $^ $(LIBFT) -Lmlx -lmlx -framework OpenGL -framework AppKit

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

clean :
	make -C ./libft clean
	make -C ./mlx clean
	$(RM) $(OBJ_DIR)

fclean :
	make -C ./libft fclean
	make -C ./mlx clean
	$(RM) $(OBJ_DIR) $(NAME)

re : fclean all

debug : re

address : re

norm :
	norminette srcs includes libft

.PHONY : all clean fclean re debug norm address
