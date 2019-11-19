# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gusujio <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/22 14:43:32 by gusujio           #+#    #+#              #
#    Updated: 2019/11/10 21:47:46 by gusujio          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ./libft/ft_atoi.c         ./libft/ft_itoa.c       ./libft/ft_memset.c\
        ./libft/ft_putchar.c    ./libft/ft_putstr.c     ./libft/ft_strcmp.c\
        ./libft/ft_strjoin.c    ./libft/ft_strlen.c     ./libft/ft_strsub.c\
        ./libft/ft_mod.c        ./libft/ft_strstr.c     ./libft/ft_strchr.c\
        ./libft/ft_strnew.c     ./libft/ft_strdup.c     ./libft/ft_strtrim.c\
        ./libft/ft_strnstr.c    tip_f.c   tip_i_d.c     tip_o.c tip_p.c\
        tip_s_c.c tip_u.c       tip_x_X.c               ./libft/ft_isdigit.c\
        ./libft/ft_memchr.c     ./libft/ft_strlen2.c    ./libft/ft_bzero.c\
        ./libft/ft_strtrim.c    ./libft/ft_degree.c     ft_multi.c

OBJ =	ft_atoi.o		ft_itoa.o	ft_memset.o		ft_putchar.o\
		ft_putstr.o		ft_strcmp.o	ft_strjoin.o	ft_strlen.o\
		ft_strsub.o		ft_mod.o	ft_strstr.o		ft_strchr.o\
		ft_strnew.o		ft_strdup.o	ft_strtrim.o	ft_strnstr.o\
		tip_f.o			tip_i_d.o	tip_o.o			tip_p.o\
		tip_s_c.o		tip_u.o		tip_x_X.o       ft_isdigit.o\
		ft_memchr.o     ft_strlen2.o ft_bzero.o     ft_strtrim.o\
		ft_degree.o     ft_multi.o

all: $(NAME)

$(NAME):
	make -C ./libft re
	gcc -c ft_printf.c  $(SRC) -L ./libft -lft
	ar rc $(NAME) ft_printf.o  $(OBJ)
	ranlib $(NAME)

clean:
	make -C ./libft clean
	/bin/rm -f ft_printf.o $(OBJ)

fclean: clean
	make -C ./libft fclean
	/bin/rm -f $(NAME)

re: fclean all
