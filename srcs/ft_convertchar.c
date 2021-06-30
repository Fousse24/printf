/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertchar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 13:42:04 by sfournie          #+#    #+#             */
/*   Updated: 2021/06/30 12:42:48 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../includes/ft_printf.h"

static int	ft_adjustchar(char s, char c, t_flags *fl)
{
	if (c != '%')
		fl->padc = ' ';
	fl->sign = '\0';
	if (!s)
		fl->prec = 0;
	fl->ssize = 1;
	if (fl->w > fl->ssize)
		fl->pads = fl->w;
	else
		fl->pads = fl->ssize;
	if (!fl->left && fl->pads > fl->ssize)
		fl->startpos = fl->pads - fl->ssize;
	return (1);
}

static int	ft_char(const char c, t_flags *fl)
{
	int		i;
	int		count;

	count = 0;
	i = -1;
	while (++i < (int)fl->pads)
	{
		if (i < fl->startpos)
			ft_putchar_fd(fl->padc, 1);
		else if (fl->ssize > 0 && fl->ssize-- > 0)
			ft_putchar_fd(c, 1);
		else
			ft_putchar_fd(' ', 1);
		count++;
	}
	return (count);
}

static int	ft_wchar(wchar_t c, t_flags *fl)
{
	int		i;
	int		count;

	count = 0;
	i = -1;
	while (++i < (int)fl->pads)
	{
		if (i < fl->startpos)
			ft_putchar_fd(fl->padc, 1);
		else if (fl->ssize > 0 && fl->ssize-- > 0)
			ft_putwchar_fd(c, 1);
		else
			ft_putchar_fd(' ', 1);
		count++;
	}
	return (count);
}

int	ft_convertchar(va_list alist, const char c, t_flags *fl)
{
	wchar_t	wch;
	char	ch;
	int		bytes;

	if (c == 'c' && fl->length == 'l')
	{
		wch = va_arg(alist, long);
		ft_adjustchar((char)wch, c, fl);
		bytes = ft_wchar(wch, fl);
	}
	else
	{
		if (c == '%')
			ch = '%';
		else
			ch = (unsigned char)va_arg(alist, int);
		ft_adjustchar(ch, c, fl);
		bytes = ft_char(ch, fl);
	}
	return (bytes);
}
