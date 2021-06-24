/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertnum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 10:01:34 by sfournie          #+#    #+#             */
/*   Updated: 2021/06/23 18:59:55 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

static void	ft_numalign(t_flags *fl)
{
	if (!fl->left && fl->pads > fl->ssize)
	{
		if ((int)fl->ssize >= fl->prec)
			fl->startpos = fl->pads - fl->ssize;
		else
			fl->startpos = (int)fl->pads - fl->prec;
		if (fl->startpos != 0 && fl->sign)
			fl->signp = fl->startpos - 1;
	}
	if ((fl->padc == '0' || fl->prec == fl->pads) && fl->sign)
		fl->signp = 0;
	if (fl->sign && (fl->ssize == fl->pads || fl->prec == (int)fl->pads))
		fl->pads++;
	return ;
}

static int	ft_adjustnum(const char *str, t_flags *fl)
{
	if (!str)
		return (0);
	if (fl->prec >= 0)
		fl->padc = ' ';
	fl->ssize = ft_strlen(str);
	if (str[0] == '-')
	{
		fl->ssize--;
		fl->sign = '-';
	}
	if (fl->prec == 0 && str[0] == '0' && !str[1])
		fl->ssize = 0;
	fl->pads = ft_sethighest(fl->ssize, fl->prec, fl->w);
	fl->padp = fl->prec - fl->ssize;
	ft_numalign(fl);
	return (1);
}

static int	ft_int(const char *str, t_flags *fl)
{
	int		i;
	int		count;

	count = 0;
	if (*str == '-')
		str++;
	i = -1;
	while (++i < (int)fl->pads)
	{
		if (fl->sign && i == fl->signp)
			ft_putchar_fd(fl->sign, 1);
		else if (i < fl->startpos)
			ft_putchar_fd(fl->padc, 1);
		else if (fl->padp-- > 0)
			ft_putchar_fd('0', 1);
		else if (fl->ssize-- > 0)
			ft_putchar_fd(*(str++), 1);
		else
			ft_putchar_fd(' ', 1);
		count++;
	}
	return (count);
}

static char	*ft_getnum(va_list alist, const char c, t_flags *fl)
{
	char						*str;
	long long int				ci;
	unsigned long long int		cui;

	ci = 0;
	cui = 0;
	if (c == 'd' || c == 'i')
	{
		ft_gettype_num(alist, fl, &ci);
		str = ft_llitoa(ci);
	}
	else
	{
		ft_gettype_usnum(alist, fl, &cui);
		if (c == 'x')
			str = ft_nbrtobase(cui, "0123456789abcdef");
		else if (c == 'X')
			str = ft_nbrtobase(cui, "0123456789ABCDEF");
		else
			str = ft_uitoa(cui);
	}
	if (str == NULL)
		return (NULL);
	return (str);
}

int	ft_convertnum(va_list alist, const char c, t_flags *fl)
{
	char	*str;
	int		bytes;

	str = ft_getnum(alist, c, fl);
	if (str != NULL && (c == 'x' || c == 'X') && fl->mod && str[0] != '0')
		ft_setprefix(&str, c);
	if (str == NULL)
		return (-1);
	if (!ft_adjustnum(str, fl))
	{
		free(str);
		return (-1);
	}
	bytes = ft_int(str, fl);
	free(str);
	return (bytes);
}
