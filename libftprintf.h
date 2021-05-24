/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 08:44:19 by sfournie          #+#    #+#             */
/*   Updated: 2021/05/24 13:57:50 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdarg.h>
# include "./libft/libft.h"

static const char	*FLAGSET = "-+ #0*.";
static const char	*CONVERTSET = "cspdiuxX%nfge";

typedef struct	s_flags
{
	char	left_align;
	char	pad_zero;
	char	precision;
	size_t	width;


	char	pad_space;
	char	force_sign;
	char	modifier;
	char	length;


}				t_flags;

typedef struct	s_form
{
	char	convert;
	char	*flags;
	char	*str;
}				t_form;

typedef struct	s_arg
{
	char	*content;
	t_form	*form;
}				t_arg;

int		ft_printf(const char *format, ...);
t_form	*ft_setformat(const char *format);
t_arg	*ft_createarg(const char *format, va_list *arg); //return a filled s_arg struct
void	*ft_convertarg(t_arg *arg); //convert the argument into a printable string
void	ft_freeform(t_form *form);
char	**ft_splitf(const char *s, char c);

#endif
