/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manageformat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 13:56:44 by sfournie          #+#    #+#             */
/*   Updated: 2021/06/07 20:23:19 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

static int	ft_getstr(const char **format, char **content)
{
	char	*str;

	str = ft_substruntil(*format, '%');
	if (str == NULL)
		return (0);
	*content = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (*content == NULL)
		return (0);
	ft_strlcpy(*content, str, (ft_strlen(str) + 1));
	*format = *format + ft_strlen(str);
	free(str);
	return (1);
}

static int	ft_getstrconv(va_list alist, const char **format, char **arg)
{
	int		count;
	t_flags	*flags;

	count = ft_getflags(format, &flags);
	if (count < 0)
		return (0);
	if (!ft_setflags(format, flags, count))
	{
		free(flags);
		return (0);
	}
	//ft_showflags(flags);
	if (!ft_convertarg(alist, **format, arg, flags))
	{
		free(flags);
		return (0);
	}
	free(flags);
	*format = *format + 1;
	return (1);
} 

int	ft_readformat(va_list alist, const char **format, t_list *arg)
{	
	if (*format && **format != '%')
	{
		if (!ft_getstr(format, (char **)&(arg->content)))
			return (0);
	}
	else if (*format && **format == '%')
	{
		*format = *format + 1;
		if (!ft_getstrconv(alist, format, (char **)&(arg->content)))
			return (0);
	}
	return (1);
}

