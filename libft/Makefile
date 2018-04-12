# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/23 18:49:32 by ebouvier          #+#    #+#              #
#    Updated: 2018/04/12 20:26:10 by ebouvier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
INCLUDES=	./includes
SRCS		=	ft_strlen.c			\
				ft_atoi.c 			\
				ft_putstr.c 		\
				ft_putchar.c		\
				ft_itoa.c 			\
				ft_putnbr.c 		\
				ft_memset.c 		\
				ft_strdup.c 		\
				ft_bzero.c 			\
				ft_memcpy.c 		\
				ft_memccpy.c 		\
				ft_memmove.c 		\
				ft_memchr.c 		\
				ft_memcmp.c 		\
				ft_strcpy.c 		\
				ft_strncpy.c 		\
				ft_strcat.c 		\
				ft_strncat.c		\
				ft_strlcat.c 		\
				ft_strchr.c 		\
				ft_strrchr.c 		\
				ft_strstr.c 		\
				ft_strnstr.c		\
				ft_toupper.c 		\
				ft_tolower.c 		\
				ft_strcmp.c			\
				ft_strncmp.c		\
				ft_nbrlen.c			\
				ft_isalpha.c		\
				ft_isdigit.c		\
				ft_isalnum.c		\
				ft_isascii.c		\
				ft_isprint.c		\
				ft_putchar_fd.c 	\
				ft_putstr_fd.c		\
				ft_putendl.c		\
				ft_putendl_fd.c		\
				ft_putnbr_fd.c		\
				ft_memalloc.c		\
				ft_memdel.c			\
				ft_strnew.c			\
				ft_strdel.c			\
				ft_strclr.c			\
				ft_striter.c		\
				ft_striteri.c		\
				ft_strmap.c			\
				ft_strmapi.c		\
				ft_strequ.c			\
				ft_strnequ.c		\
				ft_strsub.c			\
				ft_strjoin.c		\
				ft_strtrim.c		\
				ft_strsplit.c		\
				ft_isws.c			\
				ft_lstnew.c			\
				ft_lstdelone.c		\
				ft_lstdel.c			\
				ft_lstadd.c			\
				ft_lstiter.c		\
				ft_lstmap.c			\
				ft_strtoupper.c		\
				ft_strtolower.c		\
				ft_abs.c			\
				ft_sort_integer_table.c	\
				ft_swap.c			\
				ft_strrev.c			\
				ft_pow.c
OBJS		= $(SRCS:.c=.o)

C_NO		=	"\033[00m"
C_OK		=	"\033[35m"
C_GOOD		=	"\033[32m"
C_ERROR		=	"\033[31m"
C_WARN		=	"\033[33m"
SUCCESS		=	$(C_GOOD)SUCCESS$(C_NO)
OK			=	$(C_OK)OK$(C_NO)

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $@ $^
	@ranlib $@
	@echo "Compiling & indexing" [ $(NAME) ] $(SUCCESS)

%.o: %.c $(INCLUDES)/libft.h
	@$(CC) -c -o $@ $< -I $(INCLUDES)
	@echo "Linking" [ $< ] $(OK)
	
clean:
	@rm -f $(OBJS)
	@echo "Cleaning" [ $(NAME) ] "..." $(OK)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
