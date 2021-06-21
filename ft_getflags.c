/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getflags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 15:25:17 by sfournie          #+#    #+#             */
/*   Updated: 2021/06/14 11:53:57 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

// int		ft_checkpadding(char *flags, t_flag *flags)
// {
// 	return (0);
// }

static void	ft_initflags(t_flags *flags)
{
	flags->left = 0;
	flags->padc = ' ';
	flags->prec = -1;
	flags->w = 0;
	flags->sign = '\0';
	flags->modifier = '\0';
	flags->length = '\0';
	flags->pads = 0;
	flags->padp = 0;
	flags->startpos = 0;
	flags->ssize = 0;
	flags->signp = -1;
}

void	ft_showflags(t_flags *flags)
{
	ft_putstr_fd("\n Align : ", 1);
	ft_putnbr_fd(flags->left, 1);
	ft_putstr_fd("\n Padding : ", 1);
	ft_putchar_fd(flags->padc, 1);
	ft_putstr_fd("\n w : ", 1);
	ft_putnbr_fd(flags->w, 1);
	ft_putstr_fd("\n prec : ", 1);
	ft_putnbr_fd(flags->prec, 1);
	ft_putstr_fd("\n Sign or space : ", 1);
	ft_putchar_fd(flags->sign, 1);
	ft_putstr_fd("\n Modifier : ", 1);
	ft_putchar_fd(flags->modifier, 1);
	ft_putstr_fd("\n Length : ", 1);
	ft_putchar_fd(flags->length, 1);
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

int		ft_getflags(const char *format, t_flags **flags)
{
	int		count;
	
	count = ft_checkflags(format);
	if (count  < 0)
		return (-1);
	*flags = (t_flags *)malloc(sizeof(t_flags));
	if (*flags == NULL)
		return (-1);
	ft_initflags(*flags);
	return (count);
}
