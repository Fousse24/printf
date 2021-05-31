/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_applyflags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 16:39:58 by sfournie          #+#    #+#             */
/*   Updated: 2021/05/30 18:41:26 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_alignleft(const char *str, t_arg *arg, t_flags *tflags)
{
	char	*fstr;
	size_t	padsize;
	size_t	strsize;

	strsize = ft_strlen(str);
	padsize = strsize;
	if (tflags->signspace)
		padsize++;
	if (padsize < tflags->width)
		padsize = tflags->width;
	fstr = (char *)malloc(sizeof(char) * (padsize + 1));
	if (fstr == NULL)
	{
		free((char *)str);
		return (0);
	}
	ft_memset(fstr, tflags->pad_with, padsize);
	if (tflags->signspace)
	{
		fstr[0] = tflags->signspace;
		ft_memmove(&fstr[1], str, strsize);
	}
	else
		ft_memmove(fstr, str, strsize);
	free((char *)str);
	fstr[padsize] = '\0';
	arg->convert = fstr;
	return (1);
}

int	ft_applyflagsint(const char *str, t_arg *arg, t_flags *tflags)
{
	char	*fstr;
	size_t	padsize;
	size_t	strsize;

	if (tflags->left_align == 1)
		return (ft_alignleft(str, arg, tflags));
	strsize = ft_strlen(str);
	padsize = strsize;
	if (tflags->signspace)
		padsize++;
	if (padsize < tflags->width)
		padsize = tflags->width;
	fstr = (char *)malloc(sizeof(char) * (padsize + 1));
	if (fstr == NULL)
	{
		free((char *)str);
		return (0);
	}
	ft_memset(fstr, tflags->pad_with, padsize);
	if (tflags->signspace)
		fstr[0] = tflags->signspace;
	ft_memmove(&fstr[padsize - strsize], str, strsize);
	free((char *)str);
	fstr[padsize] = '\0';
	arg->convert = fstr;
	return (1);
}
