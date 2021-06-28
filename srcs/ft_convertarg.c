/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertarg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 13:42:04 by sfournie          #+#    #+#             */
/*   Updated: 2021/06/28 10:54:16 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../includes/ft_printf.h"

static int	ft_checkconvert(const char c)
{
	if (ft_strpchr(g_CONVERTSET, c) >= 0)
		return (1);
	return (0);
}

int	ft_getstrconv(va_list alist, const char *format, int *fi, int b_wr)
{
	int		bytes;
	int		i;
	t_flags	*fl;

	i = *fi + 1;
	if (!ft_setflags(alist, format, &fl, &i))
	{
		free(fl);
		return (-1);
	}
	fl->b_wr = b_wr;
	bytes = ft_convertarg(alist, format[i], fl);
	free(fl);
	if (bytes == -1)
		return (-1);
	*fi = i;
	return (bytes);
}

static int	ft_convertn(va_list alist, t_flags *fl)
{
	if (fl->length == 'l')
		*va_arg(alist, long *) = fl->b_wr;
	else if (fl->length == 'L')
		*va_arg(alist, long long *) = fl->b_wr;
	else if (fl->length == 'h')
		*va_arg(alist, short *) = fl->b_wr;
	else if (fl->length == 'H')
		*va_arg(alist, signed char *) = fl->b_wr;
	else
		*va_arg(alist, int *) = fl->b_wr;
	return (0);
}

int	ft_convertarg(va_list alist, const char c, t_flags *fl)
{
	int		bytes;

	bytes = -1;
	if (!ft_checkconvert(c))
		return (bytes);
	if (c == 'd' || c == 'i' || c == 'u')
		bytes = ft_convertnum(alist, c, fl);
	else if (c == 'x' || c == 'X')
		bytes = ft_converthex(alist, c, fl);
	else if (c == 's')
		bytes = ft_convertstr(alist, c, fl);
	else if (c == 'c' || c == '%')
		bytes = ft_convertchar(alist, c, fl);
	else if (c == 'p')
		bytes = ft_convertptr(alist, fl);
	else if (c == 'n')
		bytes = ft_convertn(alist, fl);
	return (bytes);
}
