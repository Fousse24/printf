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




static const char	*g_FLAGSET = "-+#0 ";
static const char	*g_CONVERTSET = "cspdiuxX%nfge";

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

typedef struct	s_arg
{
	char	*convert;
	char	*str;
}				t_arg;

int		ft_printf(const char *format, ...);
t_list	*ft_initarg();
t_arg	*ft_createarg(const char *format, va_list *arg);
int		ft_convertarg(va_list alist, const char c, t_arg *arg, t_flags *flags);
char	*ft_manageargs(va_list alist, const char *format, size_t *pos);
int		ft_managearg(va_list alist, const char **format, t_list *arg);
int		ft_managestr(const char **format, t_arg *arg);
void	ft_initflags(t_flags *tflag);
int		ft_checkoptions(const char *c);
int		ft_setpadding(const char *options, t_flags *flags);
int		ft_setwidth(const char **format, t_flags *flags);
int		ft_setprecision(const char **format, t_flags *flags);
int		ft_setflags(const char **format, t_flags *flags, int count);
char	*ft_manageconvert(va_list alist, const char c, t_arg *arg, t_flags *tflags);
int		ft_manageconv(va_list alist, const char **format, t_arg *arg);
int		ft_convertnumber(va_list alist, const char c, t_arg *arg, t_flags *tflags);
int		ft_convertstr(va_list alist, const char c, t_arg *arg, t_flags *tflags);
int		ft_applyflagsint(const char *str, t_arg *arg, t_flags *tflags);
// void	ft_freeform(t_form *form);
// void	ft_freesplit(char **array);
// void	ft_freeargs(t_arg **args);
// void	ft_freecontent(char *content);
// t_arg	**ft_initargs(const char *format);
char	*ft_strcatuntil(char *dest, const char *src, int delim);
char	*ft_movetochar(char *str, char c);
char	*ft_substruntil(const char *src, int delim);
size_t	ft_strlenuntil(const char *s, int delim);
void	ft_freearg(void *arg);
void	ft_printlist(void *arg);

#endif
