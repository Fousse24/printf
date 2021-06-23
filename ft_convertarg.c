/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertarg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 13:42:04 by sfournie          #+#    #+#             */
/*   Updated: 2021/06/22 18:35:44 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

static int	ft_checkconvert(const char c)
{
	if (ft_strpchr(g_CONVERTSET, c) >= 0)
		return (1);
	return (0);
}

int	ft_getstrconv(va_list alist, const char *format, int *fi)
{
	int		count;
	int		bytes;
	int		i;
	t_flags	*fl;

	i = *fi + 1;
	count = ft_getflags(&format[i], &fl);
	if (count < 0)
		return (-1);
	if (!ft_setflags(alist, format, fl, count, &i))
	{
		free(fl);
		return (-1);
	}
	bytes = ft_convertarg(alist, format[i], fl);
	free(fl);
	if (bytes == -1)
		return (-1);
	*fi = i;
	return (bytes);
}

int	ft_convertarg(va_list alist, const char c, t_flags *fl)
{
	int		bytes;

	bytes = -1;
	if (!ft_checkconvert(c))
		return (bytes);
	if (c == 'd' || c == 'i' || c == 'u')
		bytes = ft_convertnum(alist, c, fl);
	else if (c == 'c' || c == 's' || c == '%')
		bytes = ft_convertstr(alist, c, fl);
	else if (c == 'p')
		bytes = ft_convertptr(alist, fl);
	return (bytes);
}
