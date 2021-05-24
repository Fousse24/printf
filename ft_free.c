/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 15:24:54 by sfournie          #+#    #+#             */
/*   Updated: 2021/05/23 15:32:36 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libftprintf.h"

void	ft_freeform(t_form *form)
{
	if (form->flags != NULL)
		free(form->flags);
	if (form->str != NULL)
		free(form->str);
	free(form);
	return ;
}