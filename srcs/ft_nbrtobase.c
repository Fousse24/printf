/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrtobase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 15:11:20 by sfournie          #+#    #+#             */
/*   Updated: 2021/06/30 12:42:48 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../includes/ft_printf.h"

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

static int	ft_fillstr(char **dst, unsigned long nbr, char *b, int size)
{
	unsigned long	num;
	int				i;

	i = 0;
	num = nbr % size;
	if (nbr / size != 0)
		i = ft_fillstr(dst, nbr / size, b, size);
	(*dst)[i] = b[num % size];
	return (i + 1);
}

char	*ft_nbrtobase(unsigned long nbr, char *base)
{
	int		size;
	char	*ptr;

	size = ft_strlen(base);
	if (ft_base_is_valid(base, size) == 1)
	{
		ptr = (char *)malloc(sizeof(char) * 256);
		if (ptr == NULL)
			return (NULL);
		ft_memset(ptr, '\0', 256);
		ft_fillstr(&ptr, nbr, base, size);
		return (ptr);
	}
	return (NULL);
}
