/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_managelist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 14:13:33 by sfournie          #+#    #+#             */
/*   Updated: 2021/05/30 20:28:07 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

t_list	*ft_initarg()
{
	t_arg	*arg;

	arg = (t_arg *)malloc(sizeof(t_arg));
	if (arg == NULL)
		return (NULL);
	arg->convert = (char *)malloc(sizeof(char));
	if (arg->convert == NULL)
	{
		free(arg);
		return (NULL);
	}
	arg->str = (char *)malloc(sizeof(char));
	if (arg->str == NULL)
	{
		free(arg);
		free(arg->convert);
		return (NULL);
	}
	return (ft_lstnew(arg));
}

void	ft_printlist(void *arg)
{
	if (((t_arg *)arg)->str)
		ft_putstr_fd(((t_arg *)arg)->str, 1);
	if (((t_arg *)arg)->convert)
		ft_putstr_fd(((t_arg *)arg)->convert, 1);
	return ;
}