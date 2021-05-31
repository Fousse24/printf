/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manageflags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 15:25:17 by sfournie          #+#    #+#             */
/*   Updated: 2021/05/30 20:34:33 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

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

int		ft_setflags(const char **format, t_flags *tflags, int count)
{
	char	*options;

	options = ft_substr(*format, 0, count);
	if (options == NULL)
		return (0);
	if (!ft_setpadding(options, tflags))
		return (0);
	*format = *format + count;
	if (!ft_setwidth(format, tflags))
		return (0);
	if (**format == '.')
		if (!ft_setprecision(format, tflags))
			return (0);
	return (1);
}