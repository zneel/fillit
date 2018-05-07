# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/12 17:33:40 by ebouvier          #+#    #+#              #
#    Updated: 2018/05/07 16:57:42 by ebouvier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC				=	gcc
NAME			=	fillit
FLAGS			=	-Wall -Wextra -Werror

LIB_PATH		=	libft
LIB				=	$(LIB_PATH)/libft.a
LIB_LINK		=	-L $(LIB_PATH) -lft

SRC_BASE		=	main.c			\
					parse.c			\
					error.c			\
					list_helpers.c	\
					solve.c			\
					map.c			\
					parse_helpers.c

SRCS			=	$(SRC_BASE)
OBJS			=	$(SRC_BASE:.c=.o)

C_NO			=	"\033[00m"
C_OK			=	"\033[35m"
C_GOOD			=	"\033[32m"
C_ERROR			=	"\033[31m"
C_WARN			=	"\033[33m"

SUCCESS			=	$(C_GOOD)SUCCESS$(C_NO)
OK				=	$(C_OK)OK$(C_NO)

all: $(NAME)

$(NAME): $(LIB) $(OBJS)
	@$(CC) $(FLAGS) -o $@ $^ $(LIB_LINK)
	@echo "Compiling" [ $(NAME) ] $(SUCCESS)

$(LIB):
	@make -C $(LIB_PATH)

clean:
	@rm -f $(OBJS)
	@make -C $(LIB_PATH) clean
	@echo "Cleaning" [ $(NAME) ] "..." $(OK)

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIB_PATH) fclean
	@echo "Delete" [ $(NAME) ] $(OK)

re: fclean all

.PHONY: clean all re fclean
