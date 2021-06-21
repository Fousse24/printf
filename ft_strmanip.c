/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmanip.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 11:42:09 by sfournie          #+#    #+#             */
/*   Updated: 2021/06/21 09:23:03 by sfournie         ###   ########.fr       */
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

char	*ft_setnull(void)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * 7);
	if (str == NULL)
		return (NULL);
	str[0] = '(';
	str[1] = 'n';
	str[2] = 'u';
	str[3] = 'l';
	str[4] = 'l';
	str[5] = ')';
	str[6] = '\0';
	return (str);
}
