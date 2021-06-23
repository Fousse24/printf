/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getflags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 15:25:17 by sfournie          #+#    #+#             */
/*   Updated: 2021/06/23 16:18:33 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

static void	ft_initflags(t_flags *fl)
{
	fl->left = 0;
	fl->padc = ' ';
	fl->prec = -1;
	fl->w = 0;
	fl->sign = '\0';
	fl->mod = 0;
	fl->length = '\0';
	fl->pads = 0;
	fl->padp = 0;
	fl->startpos = 0;
	fl->ssize = 0;
	fl->signp = 0;
}

void	ft_showflags(t_flags *fl)
{
	ft_putstr_fd("\n Align : ", 1);
	ft_putnbr_fd(fl->left, 1);
	ft_putstr_fd("\n Padding : ", 1);
	ft_putchar_fd(fl->padc, 1);
	ft_putstr_fd("\n w : ", 1);
	ft_putnbr_fd(fl->w, 1);
	ft_putstr_fd("\n prec : ", 1);
	ft_putnbr_fd(fl->prec, 1);
	ft_putstr_fd("\n Sign or space : ", 1);
	ft_putchar_fd(fl->sign, 1);
	ft_putstr_fd("\n Modifier : ", 1);
	ft_putchar_fd(fl->mod, 1);
	ft_putstr_fd("\n Length : ", 1);
	ft_putchar_fd(fl->length, 1);
	ft_putstr_fd("\n", 1);
	return ;
}

static int	ft_checkflags(const char *format)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (format[++i] && (int)ft_strpchr(g_FLAGSET, format[i]) != -1)
		count++;
	return (count);
}

int	ft_getflags(const char *format, t_flags **fl)
{
	int		count;

	count = ft_checkflags(format);
	if (count < 0)
		return (-1);
	*fl = (t_flags *)malloc(sizeof(t_flags));
	if (*fl == NULL)
		return (-1);
	ft_initflags(*fl);
	return (count);
}
