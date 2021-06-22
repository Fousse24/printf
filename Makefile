# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/10 10:07:12 by sfournie          #+#    #+#              #
#    Updated: 2021/06/22 16:40:52 by sfournie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

NAME	= libftprintf.a
INCDIR	= ./libft/

MLIBFT	= cd ./libft/ && make

SRCS	= ft_printf.c ft_strmanip.c  ft_getflags.c ft_setflags.c\
		ft_convertarg.c ft_convertstr.c ft_convertnum.c ft_nbrtohex.c\
		ft_convertptr.c ft_flags_utils.c

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

.PHONY	: clean all re fclean bonus libft