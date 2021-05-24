/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:36:42 by sfournie          #+#    #+#             */
/*   Updated: 2021/05/23 14:56:49 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libftprintf.h"

int	ft_printf(const char *format, ...)
{
	char		**formats;
	t_list		*arglist;
	va_list 	args;
	int			arg;

	formats = ft_split(format);
	if (formats == NULL)
		return (0);

	/*while (formats[i] != NULL)
	{
		ft_validateformat(formats[i]);
	}*/
	va_start (args, format);
	
	arg = va_arg(format, int);


	return (0);
}