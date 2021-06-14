/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adjustflags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 17:15:42 by sfournie          #+#    #+#             */
/*   Updated: 2021/06/11 19:11:22 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

int	ft_adjustnum(const char *str, char c, t_flags *flags)
{
	c = '\0'; //to remove
	if (!str)
		return (0);
	if (flags->prec < 0)
		flags->prec = 0;
	flags->ssize = ft_strlen(str);
	if (str[0] == '-')
	{
		flags->ssize--;
		flags->sign = '-';
	}
	flags->pads = flags->ssize;
	if (flags->prec > (int)flags->pads)
		flags->pads = flags->prec;
	if (flags->w > (int)flags->pads)
		flags->pads = flags->w;
	flags->padp = flags->prec - flags->ssize;
	if (!flags->left && flags->pads > flags->ssize)
	{
		if ((int)flags->ssize >= flags->prec)
			flags->startpos = flags->pads - flags->ssize;
		else
			flags->startpos = (int)flags->pads - flags->prec;
		if (flags->startpos != 0 && flags->sign)
			flags->startpos--;
	}
	if (str[0] && flags->sign && (flags->ssize == flags->pads || flags->prec == (int)flags->pads))
		flags->pads++;
	return (1);
}

int	ft_adjuststr(const char *str, char c, t_flags *flags) //Need to be done
{
	c = '\0'; //to remove
	if (!str)
		return (0);
	flags->padc = ' ';
	flags->sign = '\0';
	if (!(*str))
		flags->prec = 0;
	flags->ssize = ft_strlen(str);
	if (flags->prec < (int)flags->ssize && flags->prec >= 0)
		flags->ssize = flags->prec;
	if (flags->w > (int)flags->ssize)
		flags->pads = flags->w;
	else
		flags->pads = flags->ssize;
	if (!flags->left && flags->pads > flags->ssize)
			flags->startpos = flags->pads - flags->ssize;
	return (1);
}