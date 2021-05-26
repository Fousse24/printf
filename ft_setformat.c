/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setformat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 10:24:53 by sfournie          #+#    #+#             */
/*   Updated: 2021/05/26 17:15:17 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libftprintf.h"

int		ft_checkoptions(const char *format)
{
	int	last;
	int	i;
	int	count;
	int	pos;
	int size;

	size = (int)ft_strlen(FLAGSET);
	i = -1;
	last = -1;
	count = 0;
	while (++i < size)
	{
		pos = ft_strpchr(FLAGSET, format[i]);
		if (pos >= 0)
		{
			if (pos <= last)
				return (-1);
			last = pos;
			count++;
		}
		else
			return (count);
	}
	return (count);
}

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

int	ft_setwidth(const char *format, t_flags *flags, size_t *pos)
{
	int	width;

	width = ft_atoi(format);
	flags->width = width;
	while ((width / 10) != 0 && (width % 10) != 0)
	{
		width = (width / 10) + (width % 10);
		*pos = *pos + 1;
	}
	if (width != 0)
		*pos = *pos + 1;
	return (1);
}

int	ft_setprecision(const char *format, t_flags *flags, size_t *pos)
{
	int	prec;
	
	prec = ft_atoi(format);
	flags->precision = prec;
	while ((prec / 10) != 0 && (prec % 10) != 0)
	{
		prec = (prec / 10) + (prec % 10);
		*pos = *pos + 1;
	}
	if (prec != 0)
		*pos = *pos + 1;
	return (1);
}


int		ft_checkconvert(const char c)
{
	if (ft_strchr(CONVERTSET, c) < 0)
		return (0);
	return (1);
}