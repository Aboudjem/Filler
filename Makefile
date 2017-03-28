# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plisieck <plisieck@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/20 14:08:06 by plisieck          #+#    #+#              #
#    Updated: 2017/03/27 14:35:02 by plisieck         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = players/plisieck.filler

SRC_PATH = src/
OBJ_PATH = obj/
INC_PATH = includes/

SRC_NAME =  algo.c clean.c clean_utils.c filler.c get_pos.c place.c utils.c norme_get_pos.c
OBJ_NAME = $(SRC_NAME:.c=.o)
INC_NAME =  filler.h 

CPPFLAGS = -I$(INC_PATH)
LDFLAGS = -Llibft
LDLIBS = -lft
CC = clang
CFLAGS = -Werror -Wall -Wextra


SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix $(INC_PATH),$(INC_NAME))

all: $(NAME)

$(NAME): $(OBJ) $(INC)
	@$(CC) $(LDFLAGS) $(LDLIBS) $(OBJ) -o $(NAME)
	@echo "\033[33;32mCompilation Done !\033[0;0m"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<
clean:
	@rm -fv $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
fclean: clean
	@rm -fv $(NAME)

re: fclean all

graph: graphiK.c
	@$(CC) $(CFLAGS) graphiK.c -o graph -lcurses $(LDFLAGS) $(LDLIBS)
	@echo "\033[33;32mGraph created !\033[0;0m"

.PHONY: all, clean, fclean, re

