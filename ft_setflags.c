/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setflags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 10:24:53 by sfournie          #+#    #+#             */
/*   Updated: 2021/06/11 18:55:34 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

int		ft_setflags(const char *format, t_flags *flags, int count, int *i)
{
	char	*options;

	options = ft_substr(&format[*i], 0, count);
	if (options == NULL)
		return (0);
	if (!ft_setpadding(options, flags))
		return (0);
	*i = *i + count;
	if (ft_setwidth(format, flags, i) == -1)
		return (0);
	if (format[*i] == '.')
		if (ft_setprecision(format, flags, i) == -1)
			return (0);
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

int	ft_setwidth(const char *format, t_flags *flags, int *i)
{
	int	width;
	int count;

	count = 0;
	if (ft_isdigit(format[*i]))
		count++; 
	width = ft_atoi(&format[*i]);
	flags->w = width;
	while ((width / 10) != 0 && (width % 10) != 0)
	{
		width = (width / 10) + (width % 10);
		count++;
	}
	if (format[*i + count] && format[*i + count] == '0')
		count++;
	*i = *i + count;
	return (count);
}

int	ft_setprecision(const char *format, t_flags *flags, int *i)
{
	int	prec;
	int	count;

	count = 0;
	flags->prec = 0;
	*i = *i + 1;
	if (ft_isdigit(format[*i]))
		count++; 
	prec = ft_atoi(&format[*i]);
	if (prec >= 0)
		flags->prec = prec;
	while (format[*i] && format[*i] == '0' && ft_isdigit(format[*i + 1]))
		*i = *i + 1;
	while ((prec / 10) != 0 && (prec % 10) != 0)
	{
		prec = (prec / 10) + (prec % 10);
		count++;
	}
	if (format[*i + count] && format[*i + count] == '0')
		count++;
	
	*i = *i + count;
	
	return (count);
}

int	ft_checkconvert(const char c)
{
	if (ft_strchr(g_CONVERTSET, c) < 0)
		return (0);
	return (1);
}
