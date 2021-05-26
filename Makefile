# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/10 10:07:12 by sfournie          #+#    #+#              #
#    Updated: 2021/05/26 15:19:56 by sfournie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc
CFLAGS	= -Werror -Wall -Wextra

NAME	= libftprintf.a

MLIBFT	= cd ./libft/ && make

SRCS	= ft_printf.c ft_setformat.c ft_strmanip.c ft_manageflags.c\
		 ft_manageargs.c\

OBJS	= $(patsubst %.c,%.o,$(SRCS))

HEAD	= libftprintf.h

$(NAME) : $(HEAD) $(OBJS) libft
		ar crs $(NAME) $(OBJS)

all		: $(NAME)

libft	: 
		$(MLIBFT) all		

clean	:
		rm -rf $(OBJS)
		$(MLIBFT) clean

fclean	: clean
		rm -rf $(NAME)
		$(MLIBFT) fclean

re		: fclean all		

.PHONY	: clean all re fclean bonus libft