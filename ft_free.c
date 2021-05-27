/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 15:24:54 by sfournie          #+#    #+#             */
/*   Updated: 2021/05/27 18:30:30 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"
#include	<stdio.h>

void	ft_freeform(t_form *form)
{
	if (form->flags != NULL)
		free(form->flags);
	if (form->str != NULL)
		free(form->str);
	free(form);
	return ;
}

void	ft_freecontent(char *content)
{
	if (content != NULL)
		free(content);
	return ;
}

void	ft_freeargs(t_arg **args)
{
	int i;

	i = -1;
	if (args != NULL)
	{
		while (args[++i])
		{
			ft_freeform(args[i]->form);
			ft_freecontent(args[i]->content);
			free(args[i]);
		} 
		free(args);
	}
	return ;
}

void	ft_freesplit(char **array)
{
	int i;
	
	i = -1;
	/*while (array[++i] != NULL)
	{
		printf("in");
		free(array[i]);
	}*/
	free(array);
	return ;
}