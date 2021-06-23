/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 16:36:47 by sfournie          #+#    #+#             */
/*   Updated: 2021/06/23 16:14:58 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

int	ft_sethighest(int n1, int n2, int n3)
{
	if (n1 >= n2 && n1 >= n3)
		return (n1);
	if (n2 >= n1 && n2 >= n3)
		return (n2);
	return (n3);
}

int	ft_setprefix(char **src, char x)
{
	char	*temp;
	size_t	size;

	if (*src == NULL)
		return (0);
	size = ft_strlen(*src);
	if (size > 0)
	{
		temp = (char *)malloc(sizeof(char) * (size + 3));
		if (temp == NULL)
			return (1);
		temp[0] = '0';
		temp[1] = x;
		temp[2] = '\0';
		ft_strlcat(temp, *src, size + 3);
		free(*src);
		*src = temp;
	}
	return (1);
}
