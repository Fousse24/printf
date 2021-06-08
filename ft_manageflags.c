/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manageflags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 15:25:17 by sfournie          #+#    #+#             */
/*   Updated: 2021/06/07 19:15:58 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

// int		ft_checkpadding(char *flags, t_flag *flags)
// {
// 	return (0);
// }

static void	ft_initflags(t_flags *flags)
{
	flags->left_align = 0;
	flags->pad_with = ' ';
	flags->precision = 0;
	flags->width = 0;
	flags->signspace = '\0';
	flags->modifier = '\0';
	flags->length = '\0';
}

void	ft_showflags(t_flags *flags)
{
	ft_putstr_fd("\n Align : ", 1);
	ft_putnbr_fd(flags->left_align, 1);
	ft_putstr_fd("\n Padding : ", 1);
	ft_putchar_fd(flags->pad_with, 1);
	ft_putstr_fd("\n Width : ", 1);
	ft_putnbr_fd(flags->width, 1);
	ft_putstr_fd("\n Precision : ", 1);
	ft_putnbr_fd(flags->precision, 1);
	ft_putstr_fd("\n Sign or space : ", 1);
	ft_putchar_fd(flags->signspace, 1);
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

int		ft_getflags(const char **format, t_flags **flags)
{
	int		count;
	
	count = ft_checkflags(*format);
	if (count  < 0)
		return (-1);
	*flags = (t_flags *)malloc(sizeof(t_flags));
	if (*flags == NULL)
		return (-1);
	ft_initflags(*flags);
	return (count);
}

int		ft_setflags(const char **format, t_flags *flags, int count)
{
	char	*options;

	options = ft_substr(*format, 0, count);
	if (options == NULL)
		return (0);
	if (!ft_setpadding(options, flags))
		return (0);
	*format = *format + count;
	if (!ft_setwidth(format, flags))
		return (0);
	if (**format == '.')
		if (!ft_setprecision(format, flags))
			return (0);
	return (1);
}