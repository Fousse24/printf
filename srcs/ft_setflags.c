/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setflags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 10:24:53 by sfournie          #+#    #+#             */
/*   Updated: 2021/07/05 10:32:12 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../includes/ft_printf.h"

static int	ft_setandcount(const char *format, int *nbr)
{
	int	i;
	int	count;
	int	ncount;

	count = 0;
	i = 0;
	*nbr = ft_atoi(&format[i]);
	ncount = *nbr;
	while (ft_isdigit(format[i]))
	{
		count++;
		i++;
	}
	return (count);
}

int	ft_setflags(va_list alist, const char *format, t_flags *fl, int *i)
{
	int		count;

	count = ft_getflags(&format[*i], fl);
	if (count < 0)
		return (0);
	ft_setpadding(&format[*i], fl, count);
	*i = *i + count;
	ft_setwidth(alist, format, fl, i);
	if (format[*i] == '.')
		ft_setprecision(alist, format, fl, i);
	if (format[*i] == 'l' || format[*i] == 'h')
		ft_checklength(format, fl, i);
	return (1);
}

// int	ft_setflags(va_list alist, const char *format, t_flags *fl, int *i)
// {
// 	char	*options;
// 	int		count;

// 	count = ft_getflags(&format[*i], fl);
// 	if (count < 0)
// 		return (0);
// 	options = ft_substr(&format[*i], 0, count);
// 	ft_setpadding(options, fl);
// 	*i = *i + count;
// 	ft_setwidth(alist, format, fl, i);
// 	if (format[*i] == '.')
// 		ft_setprecision(alist, format, fl, i);
// 	free(options);
// 	if (format[*i] == 'l' || format[*i] == 'h')
// 	{
// 		ft_checklength(format, fl, i);
// 	}
// 	return (1);
// }

int	ft_setpadding(const char *options, t_flags *fl, int len)
{
	if (ft_strnstr(options, "-", len))
		fl->left = 1;
	else if (ft_strnstr(options, "0", len))
		fl->padc = '0';
	if (ft_strnstr(options, "+", len))
		fl->sign = '+';
	else if (ft_strnstr(options, " ", len))
		fl->sign = ' ';
	if (ft_strnstr(options, "#", len))
		fl->mod = 'x';
	return (1);
}

int	ft_setwidth(va_list alist, const char *format, t_flags *fl, int *i)
{
	int	count;

	count = 0;
	if (format[*i] == '*')
	{
		fl->w = va_arg(alist, int);
		if (fl->w < 0)
		{
			fl->w *= -1;
			fl->left = 1;
		}
		count++;
	}
	else if (format[*i] != '.')
		count += ft_setandcount(&format[*i], &fl->w);
	*i = *i + count;
	return (count);
}

int	ft_setprecision(va_list alist, const char *format, t_flags *fl, int *i)
{
	int	count;

	count = 0;
	fl->prec = 0;
	*i = *i + 1;
	if (format[*i] == '*')
	{
		fl->prec = va_arg(alist, int);
		if (fl->prec < 0)
			fl->prec = -1;
		count++;
	}
	else
	{
		count += ft_setandcount(&format[*i], &fl->prec);
		if (fl->prec < 0)
			fl->prec = 0;
	}	
	*i = *i + count;
	return (count);
}
