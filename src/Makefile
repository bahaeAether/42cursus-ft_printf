# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: baboulou <baboulou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/29 12:10:02 by baboulou          #+#    #+#              #
#    Updated: 2022/10/30 19:44:15 by baboulou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
SRCS	= ft_printf.c ft_printf_utils.c
OBJS	= $(patsubst %.c, %.o, $(SRCS))		#*    ${SRCS:.c=.o}    *

all:	$(NAME)

$(NAME):	$(OBJS)
		ar -rcs $@ $^

%.o:	%.c
		$(CC) $(CFLAGS) -c $^ -o $@

clean:
		rm -rf $(OBJS)

fclean:	clean
		rm -rf $(NAME)

re:		fclean all
