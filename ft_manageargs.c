/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manageargs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 14:43:50 by sfournie          #+#    #+#             */
/*   Updated: 2021/05/27 19:18:10 by sfournie         ###   ########.fr       */
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

char	*ft_manageargs(va_list alist, const char *format, size_t *pos)
{
	int		i;
	int		count;
	t_flags	*tflags;
	char	*strprint;

	i = -1;
	count = ft_checkoptions(format);
	if (count  < 0)
		return (NULL);
	tflags = (t_flags *)malloc(sizeof(t_flags));
	if (tflags == NULL)
		return (NULL);
	ft_initflags(tflags);
	count = ft_setflags(format, tflags, count);
	if (count < 0)
	{
		free(tflags);
		return (NULL);
	}
	//ft_showflags(tflags);
	*pos = count;
	strprint = ft_manageconvert(alist, format[*pos], tflags);
	free(tflags);
	if (strprint == NULL)
		return (NULL);
	*pos = *pos + 2;
	return (strprint);
}
