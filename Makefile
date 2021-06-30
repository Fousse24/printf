# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/10 10:07:12 by sfournie          #+#    #+#              #
#    Updated: 2021/06/30 12:51:32 by sfournie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

NAME	= libftprintf.a
INC		= ./includes
SRCDIR	= ./srcs

LFTDIR	= $(INC)/libft
LFTA	= $(LFTDIR)/libft.a
MLIBFT	= cd $(LFTDIR) && make

SRCS	= ft_printf.c ft_strmanip.c  ft_getflags.c ft_setflags.c\
		ft_convertarg.c ft_convertstr.c ft_convertnum.c ft_nbrtobase.c\
		ft_convertptr.c ft_flags_utils.c ft_gettype.c ft_converthex.c\
		ft_convertchar.c

OBJS	= $(join $(addsuffix $(SRCDIR)/, $(dir $(SRCS))), $(notdir $(SRCS:.c=.o))) 


HEAD	= $(INC)/ft_printf.h

$(NAME) : $(LFTA) $(HEAD) $(OBJS)
		ar crs $(NAME) $(OBJS)

all		: $(NAME)

$(LFTA): 
		$(MLIBFT) all
		cp $(LFTA) $(NAME)	

clean	:
		rm -rf $(OBJS)
		$(MLIBFT) clean

fclean	: clean
		rm -rf $(NAME)
		$(MLIBFT) fclean

re		: fclean all	

bonus	: all

.PHONY	: clean all re fclean bonus libft
