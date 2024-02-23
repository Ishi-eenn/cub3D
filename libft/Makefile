NAME		=	libft.a
AR			=	ar rc
CC			=	cc
INCLUDE		=	-I includes
FLAGS		=	-Wall -Wextra -Werror
RM			=	rm -rf

CTYPE_DIR	=	ctype
CTYPE_SRC	=	ft_isalnum.c \
				ft_isalpha.c \
				ft_isascii.c \
				ft_isdigit.c \
				ft_isprint.c \
				ft_tolower.c \
				ft_toupper.c
CTYPE		=	$(addprefix $(CTYPE_DIR)/, $(CTYPE_SRC))

LIST_DIR	=	list
LIST_SRC	=	ft_lstadd_back.c \
				ft_lstadd_front.c \
				ft_lstclear.c \
				ft_lstdelone.c \
				ft_lstiter.c \
				ft_lstlast.c \
				ft_lstmap.c \
				ft_lstnew.c \
				ft_lstsize.c
LIST		=	$(addprefix $(LIST_DIR)/, $(LIST_SRC))

GNL_DIR		=	get_next_line
GNL_SRC		=	get_next_line.c
GNL			=	$(addprefix $(GNL_DIR)/, $(GNL_SRC))

STDIO_DIR	=	stdio
STDIO_SRC	=	$(GNL) \
				ft_putchar_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \
				ft_putstr_fd.c
STDIO		=	$(addprefix $(STDIO_DIR)/, $(STDIO_SRC))

STDLIB_DIR	=	stdlib
STDLIB_SRC	=	ft_atoi.c \
				ft_calloc.c \
				ft_itoa.c \
				ft_strtol.c
STDLIB		=	$(addprefix $(STDLIB_DIR)/, $(STDLIB_SRC))

STRING_DIR	=	string
STRING_SRC	=	ft_memchr.c \
				ft_memcmp.c \
				ft_memcpy.c \
				ft_memmove.c \
				ft_memset.c \
				ft_split.c \
				ft_strchr.c \
				ft_strcmp.c \
				ft_strdup.c \
				ft_strjoin.c \
				ft_strlcat.c \
				ft_strlcpy.c \
				ft_strlen.c \
				ft_strmapi.c \
				ft_strncmp.c \
				ft_strnstr.c \
				ft_strrchr.c \
				ft_strtrim.c \
				ft_substr.c
STRING		=	$(addprefix $(STRING_DIR)/, $(STRING_SRC))

STRINGS_DIR	=	strings
STRINGS_SRC	=	ft_bzero.c
STRINGS		=	$(addprefix $(STRINGS_DIR)/, $(STRINGS_SRC))

SRCS		=	$(CTYPE) \
				$(LIST) \
				$(STDIO) \
				$(STDLIB) \
				$(STRING) \
				$(STRINGS)

OBJS_DIR	=	objs
OBJS_SRC	=	$(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJS_SRC)
	$(AR) $(NAME) $(OBJS_SRC)

$(OBJS_DIR)/%.o: %.c
	@ mkdir -p $(@D)
	$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@

clean:
	$(RM) $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all
