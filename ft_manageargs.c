/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manageargs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 14:43:50 by sfournie          #+#    #+#             */
/*   Updated: 2021/05/30 20:33:15 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"
#include	<stdio.h>

static void	ft_showflags(t_flags *tflags)
{
	ft_putstr_fd("\n Align : ", 1);
	ft_putnbr_fd(tflags->left_align, 1);
	ft_putstr_fd("\n Padding : ", 1);
	ft_putchar_fd(tflags->pad_with, 1);
	ft_putstr_fd("\n Width : ", 1);
	ft_putnbr_fd(tflags->width, 1);
	ft_putstr_fd("\n Precision : ", 1);
	ft_putnbr_fd(tflags->precision, 1);
	ft_putstr_fd("\n Sign or space : ", 1);
	ft_putchar_fd(tflags->signspace, 1);
	ft_putstr_fd("\n Modifier : ", 1);
	ft_putchar_fd(tflags->modifier, 1);
	ft_putstr_fd("\n Length : ", 1);
	ft_putchar_fd(tflags->length, 1);
	ft_putstr_fd("\n", 1);
	return ;
}

int		ft_managearg(va_list alist, const char **format, t_list *arg)
{	
	// ft_putstr_fd("format received : ", 1);
	// ft_putendl_fd(*format, 1);
	if (**format != '%')
	{
		if (!ft_managestr(format, (t_arg *)(arg->content)))
			return (0);
	}
	if (**format == '%')
	{
		*format = *format + 1;
		if (!ft_manageconv(alist, format, (t_arg *)(arg->content)))
			return (0);
	}
	
	return (1);
}

int		ft_manageconv(va_list alist, const char **format, t_arg *arg)
{
	int		i;
	int		count;
	t_flags	*tflags;

	i = -1;
	count = ft_checkoptions(*format);
	if (count  < 0)
		return (0);
	tflags = (t_flags *)malloc(sizeof(t_flags));
	if (tflags == NULL)
		return (0);
	ft_initflags(tflags);
	if (!ft_setflags(format, tflags, count))
	{
		free(tflags);
		return (0);
	}
	ft_showflags(tflags);
	if (!ft_convertarg(alist, **format, arg, tflags))
	{
		free(tflags);
		return (0);
	}
	free(tflags);
	*format = *format + 1;
	return (1);
} 

int		ft_managestr(const char **format, t_arg *arg)
{
	char	*str;

	str = ft_substruntil(*format, '%');
	if (str == NULL)
		return (0);
	free(arg->str);
	arg->str = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	ft_strlcpy(arg->str, str, (ft_strlen(str) + 1));
	*format = *format + ft_strlen(str);
	free(str);
	return (1);
}
