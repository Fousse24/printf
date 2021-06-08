/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_managelist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 14:13:33 by sfournie          #+#    #+#             */
/*   Updated: 2021/05/31 17:02:41 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

t_list	*ft_initarg()
{
	char	*str;

	str = (char *)malloc(sizeof(char));
	if (str == NULL)
		return (NULL);
	return (ft_lstnew(str));
}

void	ft_printlist(void *arg)
{
	if (*((char *)arg))
		ft_putstr_fd((char *)arg, 1);
	return ;
}

void	ft_freearg(void *arg)
{
	free((char *)arg);
	return ;
}