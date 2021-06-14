/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converttostr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 13:42:04 by sfournie          #+#    #+#             */
/*   Updated: 2021/06/11 18:51:47 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

char	*ft_convertnumber(va_list alist, const char c)
{
	char			*str;
	int				ci;
	unsigned int	cui;

	ci = 0;
	cui = 0;
	if (c == 'd' || c == 'i')
	{
		ci = va_arg(alist, int);
		str = ft_itoa(ci);
	}
	else
	{
		cui = va_arg(alist, unsigned int);
		str = ft_uitoa(cui);
	}
	if (str == NULL)
		return (0);
	return (str);
}

char	*ft_convertstr(va_list alist, const char c)
{
	char	*str;
	char	*varg;

	if (c == 'c')
	{
		str = (char *)malloc(sizeof(char) * 2);
		if (str == NULL)
			return (NULL);
		str[0] = (unsigned char)va_arg(alist, int);
		str[1] = '\0';
	}
	else
	{
		varg = va_arg(alist, char *);
		if (varg != NULL)
		{
			str = (char *)malloc(sizeof(char) * 1);
			if (str == NULL)
				return (NULL);
			ft_strlcpy(str, varg, (ft_strlen(varg) + 1));
		}
		else
		{
			str = (char *)malloc(sizeof(char) * 7);
			str[0] = '(';
			str[1] = 'n';
			str[2] = 'u';
			str[3] = 'l';
			str[4] = 'l';
			str[5] = ')';		
			str[6] = '\0';	
		}
		if (str == NULL)
			return (NULL);		
	}
	return (str);
}
