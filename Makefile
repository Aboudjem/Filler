# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aboudjem <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/06 05:24:16 by aboudjem          #+#    #+#              #
#    Updated: 2017/03/17 03:42:45 by plisieck         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#	Library output
NAME = players/aboudjem.filler

#	GCC flags
CFLAGS = -Werror
ALL_CFLAGS = -Wall -Wextra $(CFLAGS)
GCC = gcc
#	Ojects/Sources directories
INC_LIBFT = includes/
SRC_LIBFT = $(shell find . | grep "\.c$$" | sed "s/\.c$$//g")
INCLUDES += $(addprefix -iquote , $(INC_LIBFT))
SRCS += $(addsuffix .c, $(SRC_LIBFT))

#	Final OBJS
OBJS = $(SRCS:.c=.o)

#	Layout
VERBOSE = false

all: $(NAME)

header:
	@echo "\033[1;36m[\033[1m$(NAME)]\033[0m\033[1;33m Compile, link & archive\033[0m"

footer:
	@echo "\033[1;36m[\033[1m$(NAME)]\033[0m\033[1;32m Well Done\033[0m"

$(NAME): $(OBJS)
ifeq ($(VERBOSE),true)
	@echo "\033[1;36m. Archive .\033[0m $(NAME)"
else
	@printf "\033[1;31m.\033[0m\n"
endif
	@$(GCC) $(NAME) $(OBJS)

%.o: %.c
ifeq ($(VERBOSE),true)
	@echo "\033[1;36m. Compile .\033[0m $<"
else
	@printf "\033[1;31m.\033[0m"
endif
	@$(GCC) $(ALL_CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@echo "\033[1;36m[\033[1m$(NAME)]\033[0m\033[1;33m >>\033[0m \033[1;33mclean (*.o)\033[0m"
	@$(RM) $(OBJS)

fclean: clean
	@echo "\033[1;36m[\033[1m$(NAME)]\033[0m\033[1;33m >>\033[0m \033[1;33mfclean ($(NAME))\033[0m"
	@$(RM) $(NAME)

re: fclean all
