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
# include <limits.h>
# include <stddef.h>
# include <wchar.h>
# include "./libft/libft.h"

static const char	*g_FLAGSET = "-+#0 ";
static const char	*g_CONVERTSET = "cspdiuxX%nfge";

typedef struct s_flags
{
	int		left;
	char	padc;
	int		prec;
	int		padp;
	int		w;
	char	sign;
	int		signp;
	char	mod;
	char	length;
	int		pads;
	int		ssize;
	int		startpos;
	int		b_wr;
}				t_flags;

int		ft_printf(const char *format, ...);
int		ft_printall(va_list alist, const char *format);
int		ft_getstrconv(va_list alist, const char *format, int *fi, int b_wr);
char	*setstrpad(t_flags *fl, const char c);
int		ft_getflags(const char *format, t_flags *fl);
int		ft_setflags(va_list alist, const char *format, t_flags *fl, int *i);
void	ft_showflags(t_flags *fl);
int		ft_setpadding(const char *options, t_flags *fl, int len);
void	ft_checklength(const char *format, t_flags *fl, int *i);
int		ft_setwidth(va_list alist, const char *format, t_flags *fl, int *i);
int		ft_setprecision(va_list alist, const char *format, t_flags *fl, int *i);
int		ft_convertarg(va_list alist, const char c, t_flags *fl);
int		ft_convertnum(va_list alist, const char c, t_flags *fl);
int		ft_convertstr(va_list alist, t_flags *fl);
int		ft_converthex(va_list alist, const char c, t_flags *fl);
int		ft_convertchar(va_list alist, const char c, t_flags *fl);
int		ft_convertptr(va_list alist, t_flags *fl);
char	*ft_nbrtobase(unsigned long nbr, char *base);
char	*ft_strcatuntil(char *dest, const char *src, int delim);
char	*ft_movetochar(char *str, char c);
char	*ft_setnull(void);
void	ft_putwchar_fd(wchar_t wc, int fd);
size_t	ft_strlenuntil(const char *s, int delim);
void	ft_freearg(void *arg);
void	ft_printlist(void *arg);
int		ft_sethighest(int n1, int n2, int n3);
int		ft_setprefix(char **src, char x);
void	ft_gettype_num(va_list alist, t_flags *fl, long long int *n);
void	ft_gettype_usnum(va_list alist, t_flags *fl, unsigned long long int *n);
void	ft_gettype_c(va_list alist, t_flags *fl, int *c);
void	ft_gettype_str(va_list alist, t_flags *fl, char **s);
char	*ft_wstrtostr(wchar_t *wstr);

#endif
