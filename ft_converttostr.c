/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converttostr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 13:42:04 by sfournie          #+#    #+#             */
/*   Updated: 2021/05/27 15:52:47 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libftprintf.h"



char	*ft_convertnumber(va_list *alist, const char c, t_flags *tflags)
{
	char			*str;
	int				ci;
	unsigned int	cui;

	ci = 0;
	cui = 0;
	if (c == 'd' || c == 'i')
	{
		ft_putendl_fd("before va_arg", 1);
		ci = va_arg(*alist, int);
		ft_putendl_fd("before itoa", 1);
		str = ft_itoa(ci);
		ft_putendl_fd("after itoa", 1);
	}
	else
	{
		cui = va_arg(*alist, unsigned int);
		str = ft_uitoa(cui);
	}
	if (str == NULL)
		return (NULL);
	return (ft_applyflagsint(str, c, tflags));

}