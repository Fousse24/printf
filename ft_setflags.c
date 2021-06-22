/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setflags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 10:24:53 by sfournie          #+#    #+#             */
/*   Updated: 2021/06/22 18:17:16 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

static int	ft_setandcount(const char *format, int *nbr)
{
	int	i;
	int count;
	int ncount;

	count = 0;
	i = 0;
	if (ft_isdigit(format[i]))
		count++;
	*nbr = ft_atoi(&format[i]);
	ncount = *nbr;
	while (format[i] && format[i] == '0' && ft_isdigit(format[i + 1]))
	{
		i++;
		count++;
	}
	while ((ncount / 10) != 0 && (ncount % 10) != 0)
	{
		ncount = (ncount / 10) + (ncount % 10);
		count++;
	}
	if (format[i + 1] && format[i + 1] == '0')
		count++;
	return (count);
}

int	ft_setflags(va_list alist, const char *format, t_flags *flags, int count, int *i)
{
	char	*options;

	options = ft_substr(&format[*i], 0, count);
	if (options == NULL)
		return (0);
	if (!ft_setpadding(options, flags))
		return (0);
	*i = *i + count;
	if (ft_setwidth(alist, format, flags, i) == -1)
		return (0);
	if (format[*i] == '.')
		if (ft_setprecision(alist, format, flags, i) == -1)
			return (0);
	free(options);
	return (1);
}

int	ft_setpadding(const char *options, t_flags *flags)
{
	if (ft_strpchr(options, '-') >= 0)
		flags->left = 1;
	else if (ft_strpchr(options, '0') >= 0)
		flags->padc = '0';
	if (ft_strpchr(options, '+') >= 0)
		flags->sign = '+';
	else if (ft_strpchr(options, ' ') >= 0)
		flags->sign = ' ';
	return (1);
}

int	ft_setwidth(va_list alist, const char *format, t_flags *flags, int *i)
{
	int count;

	count = 0;
	if (format[*i] == '*')
	{
		flags->w = va_arg(alist, int);
		if (flags->w < 0)
		{
			flags->w *= -1;
			flags->left = 1;
		}
		count++;
	}
	else if (format[*i] != '.')
		count += ft_setandcount(&format[*i], &flags->w);
	*i = *i + count;
	return (count);
}

int	ft_setprecision(va_list alist, const char *format, t_flags *flags, int *i)
{
	int	count;

	count = 0;
	flags->prec = 0;
	*i = *i + 1;
	if (format[*i] == '*')
	{
		flags->prec = va_arg(alist, int);
		if (flags->prec < 0)
			flags->prec = -1;
		count++;
	}
	else
	{
		count += ft_setandcount(&format[*i], &flags->prec);
		if (flags->prec < 0)
			flags->prec = 0;
	}	
	*i = *i + count;
	return (count);
}
