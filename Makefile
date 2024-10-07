# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ctechy <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/01 19:22:38 by ctechy            #+#    #+#              #
#    Updated: 2022/06/02 03:14:54 by ctechy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = pipex
RM = rm -f
SRC =	src/parsing_path.c \
		src/pipex.c


OBJS = ${SRC:.c=.o}
LIBFT = make -C libft/
HEADER = -Iinclude -I./libft.h

.c.o :
		@$(CC) $(CFLAGS) $(HEADER) -c $< -o $(<:.c=.o)

all : $(NAME)

$(NAME) : ${OBJS}
		@$(LIBFT)
		@$(CC) $(OBJS) ./libft/libft.a -o $(NAME)
clean :
		@${RM} ${OBJS} libft/*.o
		@echo "clean all files *.o"

fclean : clean
		@${RM} ${NAME} libft/*.o libft/*.a
		@echo "clean libft.a"

re : fclean all

.PHONY : all clean fclean re