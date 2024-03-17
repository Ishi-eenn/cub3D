NAME = cub3D
CFLAGS = -Wall -Wextra -Werror -MP -MMD -O3
RM = rm -rf
INCLUDES = -I ./includes -I ./libft/includes -I ./mlx
LIBFT = libft/libft.a
CC = cc

HOOK_DIR	=	hook
HOOK		=	closed_window.c \
				key_press.c \
				move.c
HOOKS		=	$(addprefix $(HOOK_DIR)/, $(HOOK))

RAY_DIR		=	ray
RAY			=	init.c
RAYS		=	$(addprefix $(RAY_DIR)/, $(RAY))

DRAW_DIR	=	draw
DRAW		=	$(HOOKS) \
				$(RAYS) \
				draw.c \
				floor_ceiling.c \
				init_mlx.c \
				minimap.c \
				my_mlx_pixel_put.c \
				xpm_file_to_img.c
DRAWS		=	$(addprefix $(DRAW_DIR)/, $(DRAW))

MAP_DIR		=	map
MAP			=	create_map_data.c \
				list_operations.c \
				parser.c \
				size.c \
				string_operations.c \
				validation.c
MAPS		=	$(addprefix $(MAP_DIR)/, $(MAP))

CHECKER_DIR	=	checker
CHECKER		=	check_closed.c \
				check_map.c \
				check_player.c
CHECKERS	=	$(addprefix $(CHECKER_DIR)/, $(CHECKER))

PARSER_DIR	=	parser
PARSER		=	$(CHECKERS) \
				$(MAPS) \
				file_name.c \
				init_vector.c \
				open_file.c \
				parser.c \
				rgb_handling.c \
				room_color.c \
				texture_path.c
PARSERS		=	$(addprefix $(PARSER_DIR)/, $(PARSER))

UTIL_DIR	=	utils
UTIL		=	cub_free.c \
				find_occurrence.c \
				is_overflow.c \
				open.c \
				print_error.c \
				rgb.c
UTILS		=	$(addprefix $(UTIL_DIR)/, $(UTIL))

SRC_DIR		=	srcs
SRC			=	main.c \
				$(DRAWS) \
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
