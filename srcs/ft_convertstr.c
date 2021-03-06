/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 13:42:04 by sfournie          #+#    #+#             */
/*   Updated: 2021/06/30 12:42:48 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../includes/ft_printf.h"

static int	ft_adjuststr(const char *str, t_flags *fl)
{
	if (!str)
		return (0);
	fl->padc = ' ';
	fl->sign = '\0';
	if (!*str)
		fl->prec = 0;
	fl->ssize = ft_strlen(str);
	if (fl->prec < fl->ssize && fl->prec >= 0)
		fl->ssize = fl->prec;
	if (fl->w > fl->ssize)
		fl->pads = fl->w;
	else
		fl->pads = fl->ssize;
	if (!fl->left && fl->pads > fl->ssize)
		fl->startpos = fl->pads - fl->ssize;
	return (1);
}

static int	ft_str(const char *str, t_flags *fl)
{
	int		i;
	int		count;

	count = 0;
	i = -1;
	while (++i < (int)fl->pads)
	{
		if (i < fl->startpos)
			ft_putchar_fd(fl->padc, 1);
		else if (fl->ssize > 0 && *str && fl->ssize-- > 0)
			ft_putchar_fd(*(str++), 1);
		else
			ft_putchar_fd(' ', 1);
		count++;
	}
	return (count);
}

static char	*ft_getstr(va_list alist, t_flags *fl)
{
	char	*varg;

	ft_gettype_str(alist, fl, &varg);
	if (varg == NULL)
		varg = "(null)";
	return (varg);
}

int	ft_convertstr(va_list alist, t_flags *fl)
{
	char	*str;
	int		bytes;

	str = ft_getstr(alist, fl);
	if (str == NULL)
		return (-1);
	if (!ft_adjuststr(str, fl))
		return (-1);
	bytes = ft_str(str, fl);
	return (bytes);
}
