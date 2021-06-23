/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrtohex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 15:11:20 by sfournie          #+#    #+#             */
/*   Updated: 2021/06/22 18:45:59 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

static int	ft_base_is_valid(char *b, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (ft_strlen(b) <= 1)
		return (0);
	while (i < size)
	{
		while (j < size)
		{
			if (b[j] == 43 || b[j] == 45 || (b[j] == b[i] && i != j))
				return (0);
			j++;
		}
		i++;
		j = 0;
	}
	return (1);
}

static int	ft_fillstr(char **dst, unsigned long nbr, char *b, int size, int i) //to redo
{
	unsigned long	num;

	num = nbr % size;
	if (nbr / size != 0)
		i = ft_fillstr(dst, nbr / size, b, size, i);
	(*dst)[i] = b[num % size];
	return (i + 1);
}

char	*ft_nbrtohex(unsigned long nbr)
{
	int		size;
	char	*base;
	char	*ptr;

	base = "0123456789abcdef";
	size = ft_strlen(base);
	if (ft_base_is_valid(base, size) == 1)
	{
		ptr = (char *)malloc(sizeof(char) * 256);
		if (ptr == NULL)
			return (NULL);
		ft_memset(ptr, '\0', 256);
		ptr[0] = '0';
		ptr[1] = 'x';
		ft_fillstr(&ptr, nbr, base, size, 2);
		return (ptr);
	}
	return (NULL);
}
