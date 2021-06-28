/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmanip.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 11:42:09 by sfournie          #+#    #+#             */
/*   Updated: 2021/06/28 10:54:16 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../includes/ft_printf.h"

void	ft_putwchar_fd(long wc, int fd)
{
	if (fd >= 0 && fd <= 2)
		write(fd, &wc, sizeof(wc));
}

char	*ft_wstrtostr(wchar_t *wstr)
{
	char	*str;
	int		size;
	int		i;

	if (wstr == NULL)
		return (NULL);
	i = -1;
	size = 0;
	while (wstr[++i] != '\0')
		size++;
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (str == NULL)
	{
		free(wstr);
		return (NULL);
	}
	i = -1;
	while (wstr[++i] != '\0')
		str[i] = (unsigned char)wstr[i];
	str[i] = '\0';
	return (str);
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
