# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/12 17:33:40 by ebouvier          #+#    #+#              #
#    Updated: 2018/05/14 13:51:55 by srequiem         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC				=	gcc
NAME			=	fillit
FLAGS			=	-Wall -Wextra -Werror

LIB_PATH		=	libft
LIB				=	$(LIB_PATH)/libft.a
LIB_LINK		=	-L $(LIB_PATH) -lft

SRCS			=	main.c			\
					parse.c			\
					error.c			\
					list_helpers.c	\
					solve.c			\
					map.c			\
					parse_helpers.c

OBJS			=	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(LIB) $(OBJS)
	@$(CC) -o $@ $^ $(LIB_LINK)
	@echo "Compiling" [ $(NAME) ]

%.o: %.c
	@$(CC) $(FLAGS) -c -o $@ $<

$(LIB):
	@make -C $(LIB_PATH)

clean:
	@rm -f $(OBJS)
	@make -C $(LIB_PATH) clean
	@echo "Cleaning" [ $(NAME) ] "..."

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIB_PATH) fclean
	@echo "Delete" [ $(NAME) ]

re: fclean all

.PHONY: clean all re fclean
