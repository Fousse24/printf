/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converttostr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 13:42:04 by sfournie          #+#    #+#             */
/*   Updated: 2021/05/27 19:12:40 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

char	*ft_convertnumber(va_list alist, const char c, t_flags *tflags)
{
	char			*str;
	int				ci;
	unsigned int	cui;

	ci = 0;
	cui = 0;
	if (c == 'd' || c == 'i')
	{
		ci = va_arg(alist, int);
		if (ci < 0)
		{
			tflags->signspace = '-';
			ci *= -1;
		}
		str = ft_itoa(ci);
	}
	else
	{
		cui = va_arg(alist, unsigned int);
		str = ft_uitoa(cui);
	}
	if (str == NULL)
		return (NULL);
	return (ft_applyflagsint(str, tflags));
}
