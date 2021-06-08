# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/10 10:07:12 by sfournie          #+#    #+#              #
#    Updated: 2021/06/07 19:17:05 by sfournie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc
CFLAGS	= -Wall -Wextra

NAME	= libftprintf.a
INCDIR	= ./libft/

MLIBFT	= cd ./libft/ && make

SRCS	= ft_printf.c ft_strmanip.c ft_manageformat.c ft_managelist.c\
		ft_manageflags.c ft_manageconvert.c ft_setformat.c ft_converttostr.c\
		ft_applyflags.c\

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