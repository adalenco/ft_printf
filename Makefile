# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adalenco <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/27 21:24:43 by adalenco          #+#    #+#              #
#    Updated: 2017/09/08 05:34:34 by adalenco         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libftprintf.a

SRC = $(addprefix $(SRCPATH)/,$(FC))

SRCPATH = 	./srcs

FC =	ft_printf.c \
		ft_parse_flags.c \
		ft_print_char.c \
		ft_print_int.c \
		ft_print_int_wid.c \
		ft_print_wstr.c

FCO =	$(FC:.c=.o)

COMP = gcc -Wall -Wextra -Werror

INC = ./includes

LIBFT = ./libft

all: $(NAME)

$(NAME): $(FCO)
		ar rc printf.a $(FCO)
		ranlib printf.a
		@libtool -static -o $(NAME) printf.a ./libft/libft.a
		@rm -rf printf.a
		@echo "\033[33;32mlibrary ft_printf created"

$(FCO): libmake
		@$(COMP) -c $(SRC) -I $(INC)/ -I $(LIBFT)/includes
		@echo "\033[33;32mobjects created"

libmake:
		@cd $(LIBFT) && $(MAKE)

clean:
		@cd $(LIBFT) && make clean
		@rm -rf $(FCO)
		@echo "\033[33;31m Files .o deleted"

fclean: clean
		@cd $(LIBFT) && make fclean
		@cd ../
		@rm -rf $(NAME)
		@echo "\033[33;31m $(NAME) deleted"

re: fclean all

.PHONY: clean fclean all re
