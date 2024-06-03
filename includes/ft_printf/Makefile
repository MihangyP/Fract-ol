# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmihangy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/22 08:30:20 by pmihangy          #+#    #+#              #
#    Updated: 2024/06/01 14:57:02 by pmihangy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRCS = ft_printf.c ft_printf_utils.c ft_printf_utils2.c 
OBJS = ft_printf.o ft_printf_utils.o ft_printf_utils2.o
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar -r

all : $(NAME)

$(NAME) : $(OBJS)
	make -C ./libft 
	cp ./libft/libft.a .
	mv libft.a $(NAME)
	$(AR) $(NAME) $(OBJS) ./libft/libft.a

%.o : %.c 
	$(CC) $(CFLAGS) -c $< -o $@
 
clean : 
	make -C ./libft clean
	rm -f *.o

fclean : clean
	make -C ./libft fclean
	rm -f *.a

re : fclean all

run : 
	 cc main.c -L. libftprintf.a

.PHONY : all clean fclean re
