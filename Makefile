NAME = libftprintf.a
LIBFT = libft.a
LIBFT_DIR = ./libft
CC = gcc
SRC =		functions_0.c		functions_1.c		functions_2.c	functions_3.c \
			functions_4.c		functions_5.c		functions_6.c	functions_7.c

OBJ = $(patsubst %.c,%.o,$(SRC))
# OBJ_B = $(patsubst %.c,%.o,$(SRC_B))

D_FILES = $(patsubst %.c,%.d,$(SRC) $(SRC_B))

OPT_FLAGS =
FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJ)
	@$(MAKE) all -C $(LIBFT_DIR)
	@cp $(LIBFT_DIR)/$(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJ)

%.o : %.c
	gcc $(FLAGS) $(OPT_FLAGS) -c $< -o $@ -MD

include $(wildcard $(D_FILES))

# bonus :
#	@make OBJ="$(OBJ_B)" all

clean :
	@$(MAKE) clean -C $(LIBFT_DIR)
	@rm -f $(OBJ) $(D_FILES)

fclean : clean
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@rm -f $(NAME)

bonus: all

re : fclean all

.PHONY: all clean fclean re