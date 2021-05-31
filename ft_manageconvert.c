/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manageconvert.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 13:42:04 by sfournie          #+#    #+#             */
/*   Updated: 2021/05/30 19:48:03 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

static int	ft_checkconvert(const char c)
{
	if (ft_strpchr(g_CONVERTSET, c) >= 0)
		return (1);
	return (0);
}

int	ft_convertarg(va_list alist, const char c, t_arg *arg, t_flags *tflags)
{
	if (!ft_checkconvert(c))
	{
		return (0);
	}
	if (c == 'd' || c == 'i' || c == 'u')
	{
		return (ft_convertnumber(alist, c, arg, tflags));
	}
	if (c == 'c' || c == 's')
	{
		return (ft_convertstr(alist, c, arg, tflags));
	}
	return (1);
}