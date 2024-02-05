# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbento-a <bbento-a@student.42lisboa.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/23 10:47:24 by bbento-a          #+#    #+#              #
#    Updated: 2023/12/20 11:56:26 by paugonca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c ft_printf_c.c ft_printf_percent.c ft_printf_s.c ft_putnbr_base.c

OBJECTS = $(SRC:.c=.o)

CC = cc
CCFLAGS = -Wall -Wextra -Werror

all: $(NAME)
$(NAME) : $(OBJECTS)
	ar rc $(NAME) $(OBJECTS)

clean:
	$(RM) $(SRC=.o)
fclean: clean
	$(RM) $(NAME)
re: fclean $(NAME)

.PHONY: all bonus clean fclean re
