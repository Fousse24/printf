/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 13:42:04 by sfournie          #+#    #+#             */
/*   Updated: 2021/06/22 18:21:23 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

static int	ft_adjuststr(const char *str, char c, t_flags *flags) //Need to be done
{
	if (!str)
		return (0);
	if (c != '%')
		flags->padc = ' ';
	flags->sign = '\0';
	if (!str)
		flags->prec = 0;
	flags->ssize = ft_strlen(str);
	if (c == 'c' && str[0] == 0)
		flags->ssize = 1;
	if (flags->prec < flags->ssize && flags->prec >= 0 && c != 'c')
		flags->ssize = flags->prec;
	if (flags->w > flags->ssize)
		flags->pads = flags->w;
	else
		flags->pads = flags->ssize;
	if (!flags->left && flags->pads > flags->ssize)
			flags->startpos = flags->pads - flags->ssize;
	return (1);
}

static int	ft_str(const char *str, t_flags *flags)
{
	int		i;
	int		count;

	count = 0;
	i = -1;
	while (++i < (int)flags->pads)
	{
		if (i < flags->startpos)
			ft_putchar_fd(flags->padc, 1);
		else if (flags->ssize > 0 && flags->ssize-- > 0)
			ft_putchar_fd(*(str++), 1);
		else
			ft_putchar_fd(' ', 1);
		count++;
	}
	return (count);	
}

static char	*ft_getstr(va_list alist)
{
	char	*str;
	char	*varg;

	varg = va_arg(alist, char *);
	if (varg != NULL)
	{
		str = (char *)malloc(sizeof(char) * 1);
		if (str == NULL)
			return (NULL);
		ft_strlcpy(str, varg, (ft_strlen(varg) + 1));
	}
	else
		str = ft_setnull();
	if (str == NULL)
		return (NULL);		
	return (str);
}

static char	*ft_getchar(va_list alist, const char c)
{
	char	*str;
	int		code;

	code = -1;
	if (c == 'c')
		code = (unsigned char)va_arg(alist, int);
	str = (char *)malloc(sizeof(char) * 2);
	if (str == NULL)
		return (NULL);
	if (c == '%')
		str[0] = '%';
	else if (code > 257 || code < 0)
	  	str[0] = '\0';
	else
		str[0] = code;
	str[1] = '\0';
	return (str);
}

int	ft_convertstr(va_list alist, const char c, t_flags *flags)
{
	char	*str;
	int		bytes;

	if (c == 's')
		str = ft_getstr(alist);
	else
		str = ft_getchar(alist, c);
	if (str == NULL)
		return (-1);
	if (!ft_adjuststr(str, c, flags))
	{
		free(str);
		return (-1);
	}
	bytes = ft_str(str, flags);
	free(str);
	return (bytes);
}
