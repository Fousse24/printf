/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gettype.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 16:24:18 by sfournie          #+#    #+#             */
/*   Updated: 2021/06/23 16:51:15 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

void	ft_gettype_num(va_list alist, t_flags *fl, long long int *n)
{
	if (!fl->mod)
		*n = va_arg(alist, int);
	return ;
}

void	ft_gettype_usnum(va_list alist, t_flags *fl, unsigned long long int *n)
{
	if (!fl->mod)
		*n = va_arg(alist, unsigned int);
	return ;
}
