/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmanip.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 11:42:09 by sfournie          #+#    #+#             */
/*   Updated: 2021/05/26 16:40:08 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libftprintf.h"

char	*ft_strcatuntil(char *dest, const char *src, int delim)
{
	char	*result;
	size_t	destsize;
	size_t	i;
	size_t	len;
	
	destsize = ft_strlen(dest);
	len = 0;
	i = 0;
	while (src[i] && (unsigned char)src[i++] != (unsigned char)delim)
		len++;
	result = (char *)malloc(sizeof(char) * (destsize + len + 1));
	if (result == NULL)
		return (NULL);
	i = -1;
	while (dest[++i])
		result[i] = dest[i];
	while (len-- >0)
	{
		result[i++] = *src++;
	}	
	result[i] = '\0';
	free(dest);
	return (result);
}

char	*ft_movetochar(char *str, char c)
{
	while (*str && *str != c)
		str++;
	return (str);
}
