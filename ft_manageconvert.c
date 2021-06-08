/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manageconvert.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 13:42:04 by sfournie          #+#    #+#             */
/*   Updated: 2021/06/07 20:27:37 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

static int	ft_checkconvert(const char c)
{
	if (ft_strpchr(g_CONVERTSET, c) >= 0)
		return (1);
	return (0);
}

size_t	ft_getmallocsize(t_flags *flags, size_t strsize, const char c)
{
	size_t	size;

	size = strsize;
	if (flags->width > size)
		size = flags->width;
	if (flags->precision > size && (c == 'd' || c == 'i' || c == 'u'))
		size = flags->precision;
	if (flags->signspace && strsize == size)
		size++;
	return (size);
}

int		ft_convertarg(va_list alist, const char c, char **arg, t_flags *flags)
{
	char	*str;

	if (!ft_checkconvert(c))
		return (0);
	if (c == 'd' || c == 'i' || c == 'u')
		str = ft_convertnumber(alist, c, flags);
	if (c == 'c' || c == 's')
		str = ft_convertstr(alist, c, flags);
	if (str == NULL)
		return (0);
	if (!ft_applyflags(str, c, arg, flags))
	{
		free(str);
		return (0);
	}
	free(str);
	return (1);
}