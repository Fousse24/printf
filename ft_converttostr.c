/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converttostr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 13:42:04 by sfournie          #+#    #+#             */
/*   Updated: 2021/05/30 20:38:08 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

int	ft_convertnumber(va_list alist, const char c, t_arg *arg, t_flags *tflags)
{
	char			*str;
	int				ci;
	unsigned int	cui;

	ci = 0;
	cui = 0;
	if (c == 'd' || c == 'i')
	{
		ci = va_arg(alist, int);
		if (ci < 0)
		{
			tflags->signspace = '-';
			ci *= -1;
		}
		str = ft_itoa(ci);
	}
	else
	{
		cui = va_arg(alist, unsigned int);
		str = ft_uitoa(cui);
	}
	if (str == NULL)
		return (0);
	return (ft_applyflagsint(str, arg, tflags));
}

int	ft_convertstr(va_list alist, const char c, t_arg *arg, t_flags *tflags)
{
	char	*str;
	size_t	size;
	ft_putnbr_fd(tflags->width, 1);
	size = 1;
	if (c == 'c')
	{
		str = (char *)malloc(sizeof(char) * 2);
		if (str == NULL)
			return (0);
		str[0] = va_arg(alist, int);
		str[1] = '\0';
	}
	else
		str = va_arg(alist, char *);
	size = ft_strlen(str);
	if (size < tflags->width)
	{
		arg->str = (char *)malloc(sizeof(char) * (tflags->width + 1));
		arg->str = ft_memset(arg->str, ' ', (tflags->width - size + 1));
		arg->str[tflags->width - size + 1] = '\0';
	}
	else
		arg->str = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	
	ft_strlcat(arg->str, str, ft_strlen(arg->str) + size + 1);
	return (1);
}
