/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gettype.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 16:24:18 by sfournie          #+#    #+#             */
/*   Updated: 2021/06/23 17:16:40 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

void	ft_gettype_num(va_list alist, t_flags *fl, long long int *n)
{
	if (fl->mod == 'l')
		*n = va_arg(alist, long int);
	else if (fl->mod == 'L')
		*n = va_arg(alist, long long int);
	else if (fl->mod == 'h')
		*n = (short int)va_arg(alist, int);
	else if (fl->mod == 'H')
		*n = (signed char)va_arg(alist, int);
	else
		*n = va_arg(alist, int);
	return ;
}

void	ft_gettype_usnum(va_list alist, t_flags *fl, unsigned long long int *n)
{
	if (fl->mod == 'l')
		*n = va_arg(alist, unsigned long int);
	else if (fl->mod == 'L')
		*n = va_arg(alist, unsigned long long int);
	else if (fl->mod == 'h')
		*n = (unsigned short int)va_arg(alist, unsigned int);
	else if (fl->mod == 'H')
		*n = (unsigned char)va_arg(alist, int);
	else
		*n = va_arg(alist, unsigned int);
	return ;
}

void	ft_gettype_str(va_list alist, t_flags *fl, char **s)
{	
	wchar_t *wstr;

	if (fl->mod == 'l')
	{
		wstr = (wchar_t *)va_arg(alist, char *);
		*s = ft_wstrtostr(wstr);
	}
	else
		*s = va_arg(alist, char *);
	return ;
}

void	ft_gettype_c(va_list alist, t_flags *fl, int *c)
{
	if (fl->mod == 'l')
		*c = va_arg(alist, wint_t);
	else
		*c = va_arg(alist, int);
	return ;
}
