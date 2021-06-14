/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmanip.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 11:42:09 by sfournie          #+#    #+#             */
/*   Updated: 2021/06/08 13:28:21 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

size_t	ft_strlenuntil(const char *s, int delim)
{
	size_t	count;

	count = 0;
	while (*s && *s != delim)
	{
		count++;
		s++;
	}
	return (count);
}

char	*ft_movetochar(char *str, char c)
{
	while (*str && *str != c)
		str++;
	return (str);
}
