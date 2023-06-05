# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acalin-b <acalin-b@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/12 15:26:57 by acalin-b          #+#    #+#              #
#    Updated: 2023/06/05 13:25:16 by aalamino         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a
CFLAG	= -Wall -Werror -Wextra

FILES = ft_printf.c printf_string_utils.c calc_hex.c

OBJS	= $(FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(OBJS): $(FILES)
	gcc -c $(CFLAG) $(FILES)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY : clean, fclean, re
