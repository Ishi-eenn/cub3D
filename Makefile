NAME = cub3D
CFLAGS = -Wall -Wextra -Werror -MP -MMD -O3
RM = rm -rf
INCLUDES = -I ./includes -I ./libft/includes -I ./mlx
LIBFT = libft/libft.a

PARSER_DIR	=	parser
PARSER			= parser.c
PARSERS		=	$(addprefix $(PARSER_DIR)/, $(PARSER))

UTIL_DIR	=	utils
UTIL			= print_error.c
UTILS		=	$(addprefix $(UTIL_DIR)/, $(UTIL))

SRC_DIR		=	srcs
SRC			=	main.c \
					$(PARSERS) \
					$(UTILS)
SRCS		=	$(addprefix $(SRC_DIR)/, $(SRC))

OBJ_DIR = objs
OBJS := $(subst $(SRC_DIR), $(OBJ_DIR), $(SRCS:.c=.o))
DEPS = $(OBJS:.o=.d)

ifeq ($(MAKECMDGOALS), debug)
	CFLAGS += -DDEBUG
endif

ifeq ($(MAKECMDGOALS), address)
	CFLAGS += -g3 -fsanitize=address
endif

all : $(NAME)

bonus : all

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
