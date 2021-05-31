/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmanip.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 11:42:09 by sfournie          #+#    #+#             */
/*   Updated: 2021/05/30 17:38:58 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

char	*ft_substruntil(const char *src, int delim)
{
	char	*result;
	size_t	count;
	size_t	i;

	count = ft_strlenuntil(src, delim);
	result = (char *)malloc(sizeof(char) * (count + 1));
	if (result == NULL)
		return (NULL);
	i = -1;
	while (++i < count)
	{
		result[i] = src[i];
	}
	result[i] = '\0';
	return (result);
}

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
