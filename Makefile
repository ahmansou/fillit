# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahmansou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/17 18:43:33 by ahmansou          #+#    #+#              #
#    Updated: 2019/07/19 17:19:04 by ahmansou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

OBJS = main.o fillit.o\
	   assign_l.o\
	   get_tets.o\
	   get_xy_sf.o\
	   init_board.o\
	   misc.o\
	   validate.o\
	   ft_put.o\
	   ft_strnew.o\
	   ft_strdup.o\
	   ft_strsplit.o\
	   ft_strlen.o\
	   ft_putnbr.o

all : $(NAME)

FLG = -Wall -Werror -Wextra

$(NAME) : $(OBJS)
	gcc $(FLG) $(OBJS) -o $(NAME)

%.o : src/%.c
	gcc $(FLG) -c $< -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all
