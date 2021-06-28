# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/10 10:07:12 by sfournie          #+#    #+#              #
#    Updated: 2021/06/28 12:33:31 by sfournie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g

NAME	= libftprintf.a
INCDIR	= ./libft/

MLIBFT	= cd ./libft/ && make

SRCS	= ft_printf.c ft_strmanip.c  ft_getflags.c ft_setflags.c\
		ft_convertarg.c ft_convertstr.c ft_convertnum.c ft_nbrtobase.c\
		ft_convertptr.c ft_flags_utils.c ft_gettype.c ft_converthex.c\
		ft_convertchar.c

OBJS	= $(patsubst %.c,%.o,$(SRCS))

HEAD	= ft_printf.h

$(NAME) : $(HEAD) $(OBJS) libft
		ar crs $(NAME) $(OBJS)

all		: $(NAME)

libft	: 
		$(MLIBFT) all
		cp ./libft/libft.a libftprintf.a	

clean	:
		rm -rf $(OBJS)
		$(MLIBFT) clean

fclean	: clean
		rm -rf $(NAME)
		$(MLIBFT) fclean

re		: fclean all	

bonus	: all

.PHONY	: clean all re fclean bonus libft
