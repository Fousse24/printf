/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrtohex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 15:11:20 by sfournie          #+#    #+#             */
/*   Updated: 2021/06/18 16:25:36 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

static int	ft_base_is_valid(char *base, int size)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (ft_strlen(base) <= 1)
		return (0);
	while (i < size)
	{
		while (j < size)
		{
			if (base[j] == 43 || base[j] == 45 ||
				(base[j] == base[i] && i != j))
				return (0);
			j++;
		}
		i++;
		j = 0;
	}
	return (1);
}

static int	ft_fillstr(char **dst, unsigned long nbr, char *base, int size, int i)
{
	unsigned long	num;

	num = nbr % size;
	if (nbr / size != 0)
		i = ft_fillstr(dst, nbr / size, base, size, i);
	(*dst)[i] = base[num % size];
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
