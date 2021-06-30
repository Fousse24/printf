/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converthex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 10:01:34 by sfournie          #+#    #+#             */
/*   Updated: 2021/06/30 12:45:02 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../includes/ft_printf.h"

static void	ft_hexalign(t_flags *fl)
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
	return ;
}

static int	ft_adjusthex(const char *str, t_flags *fl)
{
	if (!str)
		return (0);
	if (fl->prec >= 0)
		fl->padc = ' ';
	fl->ssize = ft_strlen(str);
	if (fl->mod)
		fl->w -= 2;
	if (fl->prec == 0 && str[0] == '0' && !str[1])
		fl->ssize = 0;
	fl->pads = ft_sethighest(fl->ssize, fl->prec, fl->w);
	fl->padp = fl->prec - fl->ssize;
	ft_hexalign(fl);
	if (fl->mod != '\0' && fl->padc == '0' && fl->ssize < fl->pads)
	{
		fl->padp = fl->pads - fl->ssize;
		fl->startpos = 0;
	}
	return (1);
}

static int	ft_hex(const char *str, t_flags *fl)
{
	int		i;
	int		count;

	count = 0;
	i = -1;
	while (++i < (int)fl->pads)
	{
		if (i == fl->startpos && fl->mod)
		{
			ft_putchar_fd('0', 1);
			ft_putchar_fd(fl->mod, 1);
			count += 2;
		}
		if (i < fl->startpos)
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

static char	*ft_gethex(va_list alist, const char c, t_flags *fl)
{
	char						*str;
	long long int				ci;
	unsigned long long int		cui;

	ci = 0;
	cui = 0;
	ft_gettype_usnum(alist, fl, &cui);
	if (c == 'x')
		str = ft_nbrtobase(cui, "0123456789abcdef");
	else if (c == 'X')
		str = ft_nbrtobase(cui, "0123456789ABCDEF");
	else
		str = ft_uitoa(cui);
	if (str == NULL)
		return (NULL);
	return (str);
}

int	ft_converthex(va_list alist, const char c, t_flags *fl)
{
	char	*str;
	int		bytes;

	str = ft_gethex(alist, c, fl);
	if (str == NULL)
		return (-1);
	if (fl->mod && str[0] && !(str[0] == '0' && ft_strlen(str) == 1))
		fl->mod = c;
	else
		fl->mod = '\0';
	if (!ft_adjusthex(str, fl))
	{
		free(str);
		return (-1);
	}
	bytes = ft_hex(str, fl);
	free(str);
	return (bytes);
}
