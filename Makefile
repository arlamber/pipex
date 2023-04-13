# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arlamber <arlamber@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/21 19:56:52 by arrlamber         #+#    #+#              #
#    Updated: 2023/04/05 17:11:45 by arlamber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = pipex.c \
	libft.c \
	ft_child.c \
	ft_free.c \
	libft2.c \
	cmd.c \
	chemin.c

OBJ	=	$(SRC:.c=.o)

CC	=	gcc $(CFLAGS)
RM	=	rm -f
CFLAGS	=	-g -Wall -Wextra -Werror

NAME	=	pipex

all	:	$(NAME)

$(NAME)	:	$(OBJ)
	$(CC) -o $(NAME) $(OBJ)

clean	:
	$(RM) $(OBJ)

fclean	:	clean
	$(RM) $(NAME)

re	:	fclean all

.PHONY	: all clean fclean re