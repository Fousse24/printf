/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:36:42 by sfournie          #+#    #+#             */
/*   Updated: 2021/05/27 18:30:51 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

int		ft_printf(const char *format, ...)
{
	char 		*strprint;
	char		*strcat;
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
			strcat = ft_manageargs(arg_list, &format[1], &pos);
			if (strcat == NULL)
				return (0);
			strprint = ft_strcatuntil(strprint, strcat, '\0');
			if (strprint == NULL)
				return (0);
			format = &format[pos];
		}
		else
			break;
	}
	ft_putstr_fd(strprint, 1);
	free(strprint);
	return (0);
}