NAME	= players/aboudjem.filler

SRC		= algo.c filler.c clean.c get_pos.c place.c

OBJ		= $(SRC:.c=.o)

CFLAGS	= -Wall -Wextra -Werror -g -I includes/

$(NAME): $(OBJ)
	@make -C libft
	@gcc $(OBJ) -o $(NAME) -L libft/ -lft -I libft/includes/

all: $(NAME)

clean:
	@make -C libft/ clean
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME) $(OBJ)
	@make -C libft/ fclean

re: fclean $(NAME)

norme:
	norminette $(SRC)
	norminette $(INC_PATH)*.h

