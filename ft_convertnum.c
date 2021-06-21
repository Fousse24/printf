/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertnum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 10:01:34 by sfournie          #+#    #+#             */
/*   Updated: 2021/06/21 09:19:36 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

static int	ft_adjustnum(const char *str, char c, t_flags *flags)
{
	c = '\0'; //to remove
	if (!str)
		return (0);
	if (flags->prec > 0)
		flags->padc = ' ';
	flags->ssize = ft_strlen(str);
	if (str[0] == '-')
	{
		flags->ssize--;
		flags->sign = '-';
	}
	if (flags->prec == 0)
		flags->ssize = 0;
	flags->pads = flags->ssize;
	if (flags->prec > (int)flags->pads)
		flags->pads = flags->prec;
	if (flags->w > (int)flags->pads)
		flags->pads = flags->w;
	flags->padp = flags->prec - flags->ssize;
	if (!flags->left && flags->pads > flags->ssize)
	{
		if ((int)flags->ssize >= flags->prec)
			flags->startpos = flags->pads - flags->ssize;
		else
			flags->startpos = (int)flags->pads - flags->prec;
		if (flags->startpos != 0 && flags->sign)
			flags->startpos--;
	}
	if (str[0] && flags->sign && (flags->ssize == flags->pads || flags->prec == (int)flags->pads))
		flags->pads++;
	return (1);
}

static int	ft_int(const char *str, t_flags *flags)
{
	int		i;
	int		count;

	count = 0;
	if (*str == '-')
		str++;
	i = -1;
	while (++i < (int)flags->pads)
	{
		if (flags->sign && i == flags->startpos)
			ft_putchar_fd(flags->sign, 1);
		else if (i < flags->startpos)
			ft_putchar_fd(flags->padc, 1);
		else if (flags->padp-- > 0)
			ft_putchar_fd('0', 1);
		else if (flags->ssize-- > 0)
			ft_putchar_fd(*(str++), 1);
		else
			ft_putchar_fd(' ', 1);
		count++;
	}
	return (count);	
}

static char	*ft_getnum(va_list alist, const char c)
{
	char			*str;
	int				ci;
	unsigned int	cui;

	ci = 0;
	cui = 0;
	if (c == 'd' || c == 'i')
	{
		ci = va_arg(alist, int);
		str = ft_itoa(ci);
	}
	else
	{
		cui = va_arg(alist, unsigned int);
		str = ft_itoa(cui);
	}
	if (str == NULL)
		return (NULL);
	return (str);
}

int	ft_convertnum(va_list alist, const char c, t_flags *flags)
{
	char	*str;
	int		bytes;

	str = ft_getnum(alist, c);
	if (str == NULL)
		return (-1);
	if (!ft_adjustnum(str, c, flags))
	{
		free(str);
		return (-1);
	}
	bytes = ft_int(str, flags);
	free(str);
	return (bytes);
}