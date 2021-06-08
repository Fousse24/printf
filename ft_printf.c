/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:36:42 by sfournie          #+#    #+#             */
/*   Updated: 2021/06/07 17:28:21 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

int		ft_printf(const char *format, ...)
{
	t_list		*toprint;
	va_list		arg_list;

	va_start (arg_list, format);
	while (*format)
	{
		ft_lstadd_front(&toprint, ft_initarg());
		if (!ft_readformat(arg_list, &format, toprint))
		{
			ft_putstr_fd("Invalid, clearing", 1);
			ft_lstclear(&toprint, &ft_freearg);
			return (0);
		}
	}
	ft_lstiter(toprint, &ft_printlist);
	ft_lstclear(&toprint, &ft_freearg);
	free(toprint);
	va_end(arg_list);
	return (0);
}