/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manageflags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 15:25:17 by sfournie          #+#    #+#             */
/*   Updated: 2021/05/26 17:07:59 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libftprintf.h"

// int		ft_checkpadding(char *flags, t_flag *flags)
// {
// 	return (0);
// }

void	ft_initflags(t_flags *tflag)
{
	tflag->left_align = 0;
	tflag->pad_with = ' ';
	tflag->precision = 0;
	tflag->width = 0;
	tflag->signspace = '\0';
	tflag->modifier = '\0';
	tflag->length = '\0';
}

int		ft_setflags(const char *format, t_flags *tflags, int count)
{
	char	*options;
	size_t	pos;

	pos = 0;
	options = ft_substr(format, 0, count);
	if (options == NULL)
		return (0);
	if (!ft_setpadding(options, tflags))
		return (0);
	pos = count;
	if (!ft_setwidth(&format[pos], tflags, &pos))
		return (0);
	if (format[pos] == '.')
	{
		pos++;
		if (!ft_setprecision(&format[pos], tflags, &pos))
			return (0);
	}
	return (pos);
}