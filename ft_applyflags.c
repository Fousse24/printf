/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_applyflags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 16:39:58 by sfournie          #+#    #+#             */
/*   Updated: 2021/06/07 20:46:43 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_int(const char *str, char c, char **arg, t_flags *flags)
{
	char	*fstr;
	size_t	padsize;
	size_t	strsize;
	int		i;

	strsize = ft_strlen(str);
	padsize = ft_getmallocsize(flags, strsize, c);
	fstr = (char *)malloc(sizeof(char) * (padsize + 1));
	if (fstr == NULL)
		return (0);
	i = 0;
	if (!flags->left_align)
	{
		while ((i < (int)strsize && flags->precision <= 0) ||
				(flags->precision != 0 && i < (int)padsize - (int)flags->precision))
			fstr[i++] = flags->pad_with;
	}
	if (flags->signspace)
		fstr[i++] = flags->signspace;
	while (i < (int)padsize)
	{
		if (flags->precision > 0 && flags->precision-- > strsize)
			fstr[i++] = '0';
		else if (*str)
		{
			fstr[i++] = *str;
			str++;
		}
		else
			fstr[i++] = ' ';
	}
	fstr[i] = '\0';
	*arg = fstr;
	return (1);	
}

static int	ft_str(const char *str, char c, char **arg, t_flags *flags)
{
	char	*fstr;
	size_t	padsize;
	size_t	strsize;
	int		i;

	strsize = ft_strlen(str);
	padsize = ft_getmallocsize(flags, strsize, c);
	fstr = (char *)malloc(sizeof(char) * (padsize + 1));
	if (fstr == NULL)
		return (0);
	i = 0;
	if (!flags->left_align)
	{
		while (i < (int)strsize)
			fstr[i++] = flags->pad_with;
	}
	if ((flags->signspace && flags->signspace != '-') && (c == 'd' || c == 'i' || c == 'u'))
		fstr[i++] = flags->signspace;
	while (i < (int)padsize)
	{
		fstr[i++] = *str;
		str++;
	}
	fstr[i] = '\0';
	*arg = fstr;
	return (1);	
}

int	ft_applyflags(const char *str, char c, char **arg, t_flags *flags)
{
	if (c == 'd' || c == 'i' || c == 'u')
	{
		if (!ft_int(str, c, arg, flags))
			return (0);
	}
	else if (c == 'c' || c == 's')
	{
		if (!ft_str(str, c, arg, flags))
			return (0);
	}
	return (1);	
}
