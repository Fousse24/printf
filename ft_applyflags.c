/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_applyflags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 16:39:58 by sfournie          #+#    #+#             */
/*   Updated: 2021/06/11 19:06:23 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_int(const char *str, t_flags *flags)
{
	char	*fstr;
	int		i;
	int		count;

	count = 0;
	if (*str == '-')
		str++;
	fstr = (char *)malloc(sizeof(char) * (flags->pads + 1));
	if (fstr == NULL)
		return (-1);
	i = -1;
	while (++i < (int)flags->pads)
	{
		if (flags->sign && i == flags->startpos)
			fstr[i] = flags->sign;
		else if (i < flags->startpos)
			fstr[i] = flags->padc;
		else if (flags->padp-- > 0)
			fstr[i] = '0';
		else if (flags->ssize-- > 0)
			fstr[i] = *(str++);
		else
			fstr[i] = ' ';
		count++;
	}
	fstr[i] = '\0';
	ft_putstr_fd(fstr, 1);
	free(fstr);
	return (count);	
}

static int	ft_str(const char *str, t_flags *flags)
{
	char	*fstr;
	int		i;
	int		count;

	count = 0;
	fstr = (char *)malloc(sizeof(char) * (flags->pads + 1));
	if (fstr == NULL)
		return (-1);
	i = -1;
	while (++i < (int)flags->pads)
	{
		if (i < flags->startpos)
			fstr[i] = flags->padc;
		else if (flags->ssize > 0 && flags->ssize-- > 0)
			fstr[i] = *(str++);
		else
			fstr[i] = ' ';
		count++;
	}
	fstr[i] = '\0';
	ft_putstr_fd(fstr, 1);
	free(fstr);
	return (count);	
}

int	ft_applyflags(const char *str, char c, t_flags *flags)
{
	int bytes;

	bytes = -1;
	if (c == 'd' || c == 'i' || c == 'u')
	{
		
		if (!ft_adjustnum(str, c, flags))
			return (-1);
		bytes = ft_int(str, flags);
	}
	else if (c == 'c' || c == 's')
	{
		if (!ft_adjuststr(str, c, flags))
			return (-1);
		bytes = ft_str(str, flags);
	}
	else if (c == '%')
	{
		ft_putchar_fd(c, 1);
		bytes = 2;
	}
	return (bytes);	
}
