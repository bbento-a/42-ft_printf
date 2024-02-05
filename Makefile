# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbento-a <bbento-a@student.42lisboa.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/23 10:47:24 by bbento-a          #+#    #+#              #
#    Updated: 2023/11/23 16:52:15 by bbento-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c ft_printf_c.c ft_printf_percent.c

OBJECTS = $(SRC:.c=.o)

CC = cc
CCFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS)
	@$(MAKE) -C ./libft
	cp ./libft/libft.a ./$(NAME)
	ar rcs $(NAME) $(OBJECTS)

clean:
	rm -f **/*.o

fclean: clean
	rm -f $(NAME)
	rm -f **/libft.a

re: fclean all

.PHONY: all bonus clean fclean libft re
