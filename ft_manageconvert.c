/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manageconvert.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 13:42:04 by sfournie          #+#    #+#             */
/*   Updated: 2021/05/27 18:30:30 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

static int	ft_checkconvert(const char c)
{
	if (ft_strpchr(CONVERTSET, c) > 0)
		return (1);
	return (0);
}

char	*ft_manageconvert(va_list alist, const char c, t_flags *tflags)
{
	if (!ft_checkconvert(c))
		return (NULL);
	if (c == 'd' || c == 'i' || c == 'u')
		return (ft_convertnumber(alist, c, tflags));
	return ("\0");
}