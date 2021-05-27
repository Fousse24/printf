/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 08:44:19 by sfournie          #+#    #+#             */
/*   Updated: 2021/05/27 17:05:56 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdarg.h>
# include "./libft/libft.h"

static const char	*FLAGSET = "-+#0 ";
static const char	*CONVERTSET = "cspdiuxX%nfge";

typedef struct	s_flags
{
	int					left_align;
	char				pad_with;
	unsigned int		precision;
	unsigned int		width;
	char				signspace;
	char				modifier;
	char				length;
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
char	*ft_manageargs(va_list alist, const char *format, size_t *pos);
void	ft_initflags(t_flags *tflag);
int		ft_checkoptions(const char *c);
int		ft_setpadding(const char *options, t_flags *flags);
int		ft_setwidth(const char *format, t_flags *flags, size_t *pos);
int		ft_setprecision(const char *format, t_flags *flags, size_t *pos);
int		ft_setflags(const char *format, t_flags *flags, int count);
char	*ft_manageconvert(va_list alist, const char c, t_flags *tflags);
char	*ft_convertnumber(va_list alist, const char c, t_flags *tflags);
char	*ft_applyflagsint(const char *str, t_flags *tflags);
// void	ft_freeform(t_form *form);
// void	ft_freesplit(char **array);
// void	ft_freeargs(t_arg **args);
// void	ft_freecontent(char *content);
// t_arg	**ft_initargs(const char *format);
char	*ft_strcatuntil(char *dest, const char *src, int delim);
char	*ft_movetochar(char *str, char c);

#endif
