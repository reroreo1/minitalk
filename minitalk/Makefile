# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rezzahra <rezzahra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/23 17:54:07 by rezzahra          #+#    #+#              #
#    Updated: 2022/01/04 15:53:32 by rezzahra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c ft_itoa_base.c ft_itoa.c specifier.c utils.c

OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)

%.o: %.c
	gcc -c $(FLAGS) $< -o $@
	ar rc $(NAME) $@
clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME) 

re:	fclean $(NAME)
