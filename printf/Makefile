# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gusujio <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/22 14:43:32 by gusujio           #+#    #+#              #
#    Updated: 2019/10/22 16:34:52 by gusujio          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

all: $(NAME)

$(NAME):
	make -C ./libft re
	gcc -c ft_printf.c -L ./libft -lft
	ar rc $(NAME) ft_printf.o ./libft/ft_atoi.o ./libft/ft_itoa.o ./libft/ft_memset.o ./libft/ft_putchar.o ./libft/ft_putstr.o ./libft/ft_strcmp.o ./libft/ft_strjoin.o ./libft/ft_strlen.o ./libft/ft_strsub.o ./libft/ft_mod.o ./libft/ft_strstr.o ./libft/ft_strchr.o ./libft/ft_strnew.o ./libft/ft_strdup.o ./libft/ft_strtrim.o ./libft/ft_strnstr.o
clean:
	make -C ./libft clean
	/bin/rm -f ft_printf.o

fclean: clean
	make -C ./libft fclean
	/bin/rm -f $(NAME)

re: fclean all
