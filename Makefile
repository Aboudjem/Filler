# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plisieck <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/01 17:15:40 by plisieck          #+#    #+#              #
#    Updated: 2017/04/01 17:15:41 by plisieck         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = players/plisieck.filler
GRAPH_NAME = graph
MATCHMAKER_NAME = matchmaker

SRC_PATH = src
OBJ_PATH = obj
INC_PATH = includes

SRC_NAME =  algo.c clean.c clean_utils.c filler.c get_pos.c place.c get.c \
			norme_get_pos.c get2.c init.c
OBJ_NAME = $(SRC_NAME:.c=.o)
INC_NAME =  filler.h matchmaker.h

CPPFLAGS = -I$(INC_PATH)
LDFLAGS = -Llibft
LDLIBS = -lft
CC = clang
CFLAGS = -Werror -Wall -Wextra


SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
INC = $(addprefix $(INC_PATH)/,$(INC_NAME))

all: $(NAME)

$(NAME): $(OBJ) $(INC)
	@printf "\033[1;36mCompiling [\033[1;33mlibft\033[1;36m]: \033[0m"
	@make -C libft
	@printf "\033[1;36mCompiling [\033[1;33m$(NAME)\033[1;36m]: \033[0m"
	@$(CC) $(LDFLAGS) $(LDLIBS) $(OBJ) -o $(NAME)
	@echo "\033[1;32mDone !\033[0;0m"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<
clean:
	@rm -rf $(OBJ_PATH)
	@make -C libft clean

fclean: clean
	@rm -f $(NAME)
	@rm -f $(GRAPH_NAME)
	@rm -f $(MATCHMAKER_NAME)
	@make -C libft fclean

re: fclean all

graph: graphics.c init_ncurse.c
	@printf "\033[1;36mCompiling [\033[1;33m$(GRAPH_NAME)\033[1;36m]: \033[0m"
	@$(CC) $(CFLAGS) graphics.c init_ncurse.c -o $(GRAPH_NAME) -lcurses $(LDFLAGS) $(LDLIBS)
	@echo "\033[1;32mDone !\033[0;0m"

matchmaker: matchmaker.c init_ncurse.c
	@printf "\033[1;36mCompiling [\033[1;33m$(MATCHMAKER_NAME)\033[1;36m]: \033[0m"
	@$(CC) $(CFLAGS) matchmaker.c init_ncurse.c -o $(MATCHMAKER_NAME) -lcurses $(LDFLAGS) $(LDLIBS)
	@echo "\033[1;32mDone !\033[0;0m"

.PHONY: all, clean, fclean, re

