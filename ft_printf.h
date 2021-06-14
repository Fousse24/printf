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

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include "./libft/libft.h"

static const char	*g_FLAGSET = "-+#0 ";
static const char	*g_CONVERTSET = "cspdiuxX%nfge";

typedef struct	s_flags
{
	int					left;
	char				padc;
	int					prec;
	int					w;
	char				sign;
	char				modifier;
	char				length;
	size_t				pads;
	size_t				ssize;
	int					padp;
	int					startpos;
}				t_flags;

int		ft_printf(const char *format, ...);
int		ft_printall(va_list alist, const char *format);
int		ft_getstrconv(va_list alist, const char *format, int *fi);
char	*setstrpad(t_flags *flags, const char c);
int		ft_getflags(const char *format, t_flags **flags);
int		ft_setflags(const char *format, t_flags *flags, int count, int *i);
int		ft_adjustnum(const char *str, char c, t_flags *flags);
int		ft_adjuststr(const char *str, char c, t_flags *flags);
void	ft_showflags(t_flags *flags);
int		ft_setpadding(const char *options, t_flags *flags);
int		ft_setwidth(const char *format, t_flags *flags, int *i);
int		ft_setprecision(const char *format, t_flags *flags, int *i);
int		ft_convertarg(va_list alist, const char c, t_flags *flags);
char	*ft_convertnumber(va_list alist, const char c);
char	*ft_convertstr(va_list alist, const char c);
int		ft_applyflags(const char *str, char c, t_flags *flags);
char	*ft_strcatuntil(char *dest, const char *src, int delim);
char	*ft_movetochar(char *str, char c);
size_t	ft_strlenuntil(const char *s, int delim);
void	ft_freearg(void *arg);
void	ft_printlist(void *arg);

#endif
