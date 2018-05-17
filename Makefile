# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: inazarin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/22 16:46:57 by inazarin          #+#    #+#              #
#    Updated: 2018/03/22 16:47:04 by inazarin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c \
		ft_parser.c \
		ft_handle_func.c \
		ft_d_write.c \
		ft_h_write.c \
		ft_handlers.c \
		ft_width.c \
		ft_hh_write.c \
		ft_itoas.c \
		ft_itoas2.c \
		ft_itoas3.c \
		ft_l_write.c \
		ft_ll_write.c \
		ft_sc_write.c \
		ft_uni_write.c \
		ft_z_write.c \
		ft_long_handlers.c \
		ft_precision.c \
		ft_h_big_write.c \
		ft_x_o_write.c \
		ft_unistr.c \
		ft_itoa4.c \
		write_helpers.c \



OBJ =	$(SRCS:%.c=%.o)

FLAGS = -g -Wall -Wextra -Werror

HEADER = ft_printf.h

all: $(NAME)

%.o:%.c
	gcc -I. $(FLAGS)  -c $< -o $@ 

$(NAME): $(OBJ) $(HEADER)
	make -C libft
	cp ./libft/libft.a ./$(NAME)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	make clean -C libft/
	rm -f $(OBJ)

fclean: clean
	make fclean -C libft/
	rm -f libft.a
	rm -f $(NAME)

re: fclean all
