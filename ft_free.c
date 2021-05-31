/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 15:24:54 by sfournie          #+#    #+#             */
/*   Updated: 2021/05/30 19:01:11 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

void	ft_freearg(void *arg)
{
	free(((t_arg *)arg)->convert);
	free(((t_arg *)arg)->str);
	free((t_arg *)arg);
	return ;
}
