NAME = cub3D

UTIL_DIR	=	utils
UTIL		=	ft_realloc.c \
				is_overflow.c \
				open.c \
				print_error.c \
				rgb.c
UTILS		=	$(addprefix $(UTIL_DIR)/, $(UTIL))

PARSER_DIR	=	parser
PARSER		=	file_name.c \
				line_operations.c \
				map.c \
				open_file.c \
				parser.c \
				rgb_handling.c \
				room_color.c \
				texture_path.c
PARSERS		=	$(addprefix $(PARSER_DIR)/, $(PARSER))

SRC_DIR		=	srcs
SRC			=	main.c \
				$(PARSERS) \
				$(UTILS)
SRCS		=	$(addprefix $(SRC_DIR)/, $(SRC))

OBJ_DIR = objs
OBJS := $(subst $(SRC_DIR), $(OBJ_DIR), $(SRCS:.c=.o))
DEPS = $(OBJS:.o=.d)

CFLAGS = -Wall -Wextra -Werror -MP -MMD -O3
RM = rm -rf

INC = -I ./includes -I ./libft/includes -I ./mlx

LIBFT = libft/libft.a

ifeq ($(MAKECMDGOALS), debug)
	CFLAGS += -DDEBUG
endif

ifeq ($(MAKECMDGOALS), address)
	CFLAGS += -g3 -fsanitize=address
endif

CHECK		= \033[32m[✔]\033[0m
REMOVE		= \033[31m[✘]\033[0m
GENERATE	= \033[33m[➤]\033[0m
BLUE		= \033[1;34m
YELLOW		= \033[1;33m
RESET		= \033[0m

TOTAL_FILES := $(shell echo $(words $(SRCS)))
CURRENT_FILE = 1

define progress
	@printf "$(GENERATE) $(YELLOW)Cub3d obj file gen Progress: %3d%% (%d/%d)$(RESET)\r" $$(($(CURRENT_FILE)*100/$(TOTAL_FILES))) $(CURRENT_FILE) $(TOTAL_FILES)
	@$(eval CURRENT_FILE=$(shell echo $$(($(CURRENT_FILE)+1))))
	@if [ $(CURRENT_FILE) -gt $(TOTAL_FILES) ]; then \
		printf "$(GENERATE) $(YELLOW)Finish Generating CUB3D Object files !%-50.50s\n$(RESET)"; \
	fi
endef

all : $(NAME)

$(NAME): $(OBJS)
	@ $(MAKE) -C ./libft
	@ $(MAKE) -C ./mlx
	@ $(CC) $(CFLAGS) -o $@ $^ $(LIBFT) -Lmlx -lmlx -framework OpenGL -framework AppKit
	@ printf "$(CHECK) $(BLUE)Compiling cub3D...%-50.50s\n$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@ mkdir -p $(dir $@)
	@ $(CC) $(CFLAGS) $(INC) -o $@ -c $<
	$(call progress)

clean :
	@ $(MAKE) -C ./libft clean
	@ $(MAKE) -C ./mlx clean
	@ $(RM) $(OBJ_DIR)
	@ echo "$(REMOVE) $(BLUE)Remove cub3D object files. $(RESET)"

fclean :
	@ $(MAKE) -C ./libft fclean
	@ $(MAKE) -C ./mlx fclean
	@ $(RM) $(OBJ_DIR) $(NAME)
	@ echo "$(REMOVE) $(BLUE)Remove cub3D object files and $(NAME). $(RESET)"

re : fclean all

debug : re

address : re

norm :
	norminette srcs includes libft

.PHONY : all clean fclean re debug norm address
