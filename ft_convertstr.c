/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 13:42:04 by sfournie          #+#    #+#             */
/*   Updated: 2021/06/27 13:52:22 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

static int	ft_adjuststr(const char *str, char c, t_flags *fl)
{
	if (!str)
		return (0);
	if (c != '%')
		fl->padc = ' ';
	fl->sign = '\0';
	if (!str)
		fl->prec = 0;
	fl->ssize = ft_strlen(str);
	if (c == 'c' && str[0] == 0)
		fl->ssize = 1;
	if (fl->prec < fl->ssize && fl->prec >= 0 && c != 'c' && c != '%')
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
		else if (fl->ssize > 0 && fl->ssize-- > 0)
			ft_putchar_fd(*(str++), 1);
		else
			ft_putchar_fd(' ', 1);
		count++;
	}
	return (count);
}

static char	*ft_getstr(va_list alist, t_flags *fl)
{
	char	*str;
	char	*varg;

	ft_gettype_str(alist, fl, &varg);
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

static char	*ft_getchar(va_list alist, const char c, t_flags *fl)
{
	char	*str;
	int		code;

	code = -1;
	if (c == 'c')
		ft_gettype_c(alist, fl, &code);
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

int	ft_convertstr(va_list alist, const char c, t_flags *fl)
{
	char	*str;
	int		bytes;

	if (c == 's')
		str = ft_getstr(alist, fl);
	else
		str = ft_getchar(alist, c, fl);
	if (str == NULL)
		return (-1);
	if (!ft_adjuststr(str, c, fl))
	{
		free(str);
		return (-1);
	}
	bytes = ft_str(str, fl);
	free(str);
	return (bytes);
}
