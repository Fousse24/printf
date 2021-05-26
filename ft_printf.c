/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:36:42 by sfournie          #+#    #+#             */
/*   Updated: 2021/05/26 17:03:34 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libftprintf.h"

int		ft_printf(const char *format, ...)
{
	char 		*strprint;
	va_list		arg_list;
	size_t		pos;

	pos = -1;
	strprint = (char *)malloc(sizeof(char) * 1);
	if (strprint == NULL)
		return (0);
	va_start (arg_list, format);
	while (*format)
	{
		strprint = ft_strcatuntil(strprint, format, '%');
		format = ft_movetochar((char *)format, '%');
		if (format[1] && *format == '%')
		{
			strprint = ft_strcatuntil(strprint, ft_manageargs(arg_list, &format[1], &pos), '\0');
			if (strprint == NULL)
				return (0);
			ft_putendl_fd((char *)format, 1);
			format = &format[pos];
			ft_putendl_fd((char *)format, 1);
			ft_putendl_fd(strprint, 1);
		}
		else
			break;
	}
	ft_putendl_fd(strprint, 1);
	return (0);
}