NAME		=	cub3D
CC			=	cc
INCLUDE 	=	-I ./includes -I./libft/includes
CFLAGS		=	-Wall -Wextra -Werror
# CFLAGS		=	-Wall -Wextra -Werror -fsanitize=address -g -I$(INCLUDE)
RM			=	rm -rf

LIBFT_DIR	=	./libft
LIBS		=	-L./libft -lft

GNL_DIR		=	get_next_line
GNL			=	get_next_line.c \
				get_next_line_utils.c
GNLS		=	$(addprefix $(GNL_DIR)/, $(GNL))

PARSER_DIR	=	parser
PARSER		=	file_name.c
PARSERS		=	$(addprefix $(PARSER_DIR)/, $(PARSER))

UTIL_DIR	=	utils
UTIL		=	open.c \
				print_error.c
UTILS		=	$(addprefix $(UTIL_DIR)/, $(UTIL))

SRC_DIR		=	srcs
SRC			=	main.c \
				$(GNLS) \
				$(PARSERS) \
				$(UTILS)
SRCS		=	$(addprefix $(SRC_DIR)/, $(SRC))

OBJ_DIR		=	objs
OBJS		=	$(subst $(SRC_DIR), $(OBJ_DIR), $(SRCS:.c=.o))

all:	$(NAME)

$(NAME): $(OBJS) $(LIBS)
	$(CC) $(CFLAGS) $(INCLUDE) $(SRCS) -o $(NAME) $(LIBS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@ mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ -c $<

$(LIBS):
	$(MAKE) -s -C $(LIBFT_DIR)

.c.o:
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $(<:.c=.o)

clean:
	$(RM) $(OBJ_DIR)
	$(MAKE) clean -s -C $(LIBFT_DIR)

fclean:
	$(RM) $(OBJ_DIR)
	$(MAKE) fclean -s -C $(LIBFT_DIR)
	$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re bonus
