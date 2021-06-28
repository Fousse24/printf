# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/10 10:07:12 by sfournie          #+#    #+#              #
#    Updated: 2021/06/28 12:12:17 by sfournie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g

NAME	= libftprintf.a
INCDIR	= ./includes/
SRCDIR	= ./srcs/

LIBFT	= $(INCDIR)libft/
MLIBFT	= cd $(LIBFT) && make

_SRCS	= ft_printf.c ft_strmanip.c ft_getflags.c ft_setflags.c\
		ft_convertarg.c ft_convertstr.c ft_convertnum.c ft_nbrtobase.c\
		ft_convertptr.c ft_flags_utils.c ft_gettype.c ft_converthex.c\
		ft_convertchar.c
SRCS	= $(addprefix $(SRCDIR),$(_SRCS))

OBJS	= $(SRCS:.c=.o)

HEAD	= $(INCDIR)ft_printf.h

$(NAME) : $(HEAD) libft $(OBJS) 
		ar crs $(NAME) $(OBJS)

all		: $(NAME)

libft	: 
		$(MLIBFT) all
		cp $(LIBFT)libft.a libftprintf.a	

clean	:
		rm -rf $(OBJS)
		$(MLIBFT) clean

fclean	: clean
		rm -rf $(NAME)
		$(MLIBFT) fclean

re		: fclean all	

bonus	: all

.PHONY	: clean all re fclean bonus libft
