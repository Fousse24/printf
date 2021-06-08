/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setformat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 10:24:53 by sfournie          #+#    #+#             */
/*   Updated: 2021/05/31 14:56:23 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

int	ft_setpadding(const char *options, t_flags *flags)
{
	if (ft_strpchr(options, '-') >= 0)
		flags->left_align = 1;
	else if (ft_strpchr(options, '0') >= 0)
		flags->pad_with = '0';
	if (ft_strpchr(options, '+') >= 0)
		flags->signspace = '+';
	else if (ft_strpchr(options, ' ') >= 0)
		flags->signspace = ' ';
	return (1);
}

int	ft_setwidth(const char **format, t_flags *flags)
{
	int	width;

	width = ft_atoi(*format);
	flags->width = width;
	while ((width / 10) != 0 && (width % 10) != 0)
	{
		width = (width / 10) + (width % 10);
		*format = *format + 1;
	}
	if (width != 0)
		*format = *format + 1;
	return (1);
}

int	ft_setprecision(const char **format, t_flags *flags)
{
	int	prec;

	*format = *format + 1;
	prec = ft_atoi(*format);
	flags->precision = prec;
	while ((prec / 10) != 0 && (prec % 10) != 0)
	{
		prec = (prec / 10) + (prec % 10);
		*format = *format + 1;
	}
	if (prec != 0)
		*format = *format + 1;
	return (1);
}

int	ft_checkconvert(const char c)
{
	if (ft_strchr(g_CONVERTSET, c) < 0)
		return (0);
	return (1);
}
