/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmanip.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 11:42:09 by sfournie          #+#    #+#             */
/*   Updated: 2021/07/05 10:34:02 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../includes/ft_printf.h"

void	ft_putwchar_fd(wchar_t wc, int fd)
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
