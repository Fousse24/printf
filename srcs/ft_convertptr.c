/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 13:42:04 by sfournie          #+#    #+#             */
/*   Updated: 2021/06/28 10:54:16 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../includes/ft_printf.h"

static int	ft_adjustptr(const char *str, t_flags *fl)
{
	if (!str)
		return (0);
	fl->padc = ' ';
	fl->sign = '\0';
	if (!(*str))
		fl->prec = 0;
	fl->ssize = ft_strlen(str);
	if (fl->prec == 0 && str[2] && str[2] == '0')
		fl->ssize = 2;
	fl->pads = ft_sethighest(fl->ssize, fl->w, fl->prec);
	if (!fl->left && fl->pads > fl->ssize)
		fl->startpos = fl->pads - fl->ssize;
	return (1);
}

static int	ft_ptr(const char *str, t_flags *fl)
{
	char	*fstr;
	int		i;
	int		count;

	count = 0;
	fstr = (char *)malloc(sizeof(char) * (fl->pads + 1));
	if (fstr == NULL)
		return (-1);
	i = -1;
	while (++i < (int)fl->pads)
	{
		if (i < fl->startpos)
			fstr[i] = fl->padc;
		else if (fl->ssize > 0 && fl->ssize-- > 0)
			fstr[i] = *(str++);
		else
			fstr[i] = ' ';
		count++;
	}
	fstr[i] = '\0';
	ft_putstr_fd(fstr, 1);
	free(fstr);
	return (count);
}

static char	*ft_getptr(va_list alist)
{
	unsigned long	varg;
	char			*str;

	varg = (unsigned long)va_arg(alist, void *);
	str = ft_nbrtobase(varg, "0123456789abcdef");
	if (str == NULL)
		return (NULL);
	if (!ft_setprefix(&str, 'x'))
	{
		free(str);
		return (NULL);
	}
	return (str);
}

int	ft_convertptr(va_list alist, t_flags *fl)
{
	int		bytes;
	char	*str;

	str = ft_getptr(alist);
	if (str == NULL)
		return (-1);
	ft_adjustptr(str, fl);
	bytes = ft_ptr(str, fl);
	free(str);
	return (bytes);
}
