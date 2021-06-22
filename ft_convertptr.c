/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 13:42:04 by sfournie          #+#    #+#             */
/*   Updated: 2021/06/22 18:23:14 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

static int	ft_adjustptr(const char *str, t_flags *flags) //Need to be done
{
	if (!str)
		return (0);
	flags->padc = ' ';
	flags->sign = '\0';
	if (!(*str))
		flags->prec = 0;
	flags->ssize = ft_strlen(str);
	flags->pads = ft_sethighest(flags->ssize, flags->w, flags->prec);
	if (!flags->left && flags->pads > flags->ssize)
			flags->startpos = flags->pads - flags->ssize;
	return (1);
}

static int	ft_ptr(const char *str, t_flags *flags)
{
	char	*fstr;
	int		i;
	int		count;

	count = 0;
	fstr = (char *)malloc(sizeof(char) * (flags->pads + 1));
	if (fstr == NULL)
		return (-1);
	i = -1;
	while (++i < (int)flags->pads)
	{
		if (i < flags->startpos)
			fstr[i] = flags->padc;
		else if (flags->ssize > 0 && flags->ssize-- > 0)
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
	str = ft_nbrtohex(varg);
	if (str == NULL)
		return (NULL);
	return(str);
}

int	ft_convertptr(va_list alist, t_flags *flags)
{
	int		bytes;
	char	*str;

	str = ft_getptr(alist);
	if (str == NULL)
		return (-1);
	ft_adjustptr(str, flags);
	bytes = ft_ptr(str, flags);
	free(str);
	return (bytes);
}
