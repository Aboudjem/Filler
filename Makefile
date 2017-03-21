# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plisieck <plisieck@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/20 14:08:06 by plisieck          #+#    #+#              #
#    Updated: 2017/03/20 22:25:57 by plisieck         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = players/aboudjem.filler
SRC = Srcs/*.c
OBJ = *.o
FLAGS = -Wall -Wextra -Werror -I includes/

all: $(NAME)

$(NAME):
	@gcc -c $(FLAGS) $(SRC)
	@make -C libft/
	@gcc -o $(NAME) $(FLAGS) $(OBJ) libft/libft.a
	@


clean:
	@make clean -C libft
	@rm -rf $(OBJ)

fclean: clean
	@make fclean -C libft
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
