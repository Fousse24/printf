/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertarg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 13:42:04 by sfournie          #+#    #+#             */
/*   Updated: 2021/06/11 18:22:51 by sfournie         ###   ########.fr       */
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
	t_flags	*flags;

	i = *fi + 1;
	
	count = ft_getflags(&format[i], &flags);
	if (count < 0)
		return (-1);
	if (!ft_setflags(format, flags, count, &i))
	{
		free(flags);
		return (-1);
	}
	bytes = ft_convertarg(alist, format[i], flags);
	free(flags);
	if (bytes == -1)
		return (-1);
	*fi = i;
	return (bytes);
} 

int		ft_convertarg(va_list alist, const char c, t_flags *flags)
{
	char	*str;
	int		bytes;

	if (!ft_checkconvert(c))
		return (-1);
	if (c == 'd' || c == 'i' || c == 'u')
		str = ft_convertnumber(alist, c);
	if (c == 'c' || c == 's')
		str = ft_convertstr(alist, c);
	if (str == NULL)
		return (-1);
	bytes = ft_applyflags(str, c, flags);
	free(str);
	return (bytes);
}
