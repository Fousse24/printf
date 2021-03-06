/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:36:42 by sfournie          #+#    #+#             */
/*   Updated: 2021/06/30 12:42:48 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../includes/ft_printf.h"

int	ft_printall(va_list alist, const char *format)
{	
	int	bytes;
	int	written;
	int	i;

	bytes = 0;
	written = 0;
	i = -1;
	while (format[++i] && i <= INT_MAX)
	{
		if (format[i] != '%')
		{
			ft_putchar_fd(format[i], 1);
			bytes++;
		}
		else
		{
			written = ft_getstrconv(alist, format, &i, bytes);
			if (written == -1)
				return (-1);
			bytes += written;
		}
	}
	return (bytes);
}

int	ft_printf(const char *format, ...)
{
	va_list		arg_list;
	int			bytes;

	bytes = 0;
	va_start (arg_list, format);
	if (*format)
	{
		bytes = ft_printall(arg_list, format);
		if (bytes == -1)
		{
			va_end(arg_list);
			return (-1);
		}
	}
	va_end(arg_list);
	return (bytes);
}
