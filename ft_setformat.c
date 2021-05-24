/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setformat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 14:57:10 by sfournie          #+#    #+#             */
/*   Updated: 2021/05/24 13:57:48 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libftprintf.h"
#include 	<stdio.h>

static int	ft_checkflags(const char *format)
{
	int	last;
	int	i;
	int	count;
	int	pos;
	int size;

	size = (int)ft_strlen(FLAGSET);
	i = -1;
	last = -1;
	count = 0;
	while (++i < size)
	{
		pos = ft_strpchr(FLAGSET, format[i]);
		if (pos >= 0)
		{
			if (pos <= last)
				return (-1);
			last = pos;
			count++;
		}
		else
			return (count);
	}
	return (count);
}

static char	*ft_setflags(const char *format, size_t *pos)
{
	char	*flags;
	int		count;

	count = ft_checkflags(format);
	if (count < 0)
		return (NULL);
	flags = ft_substr(format, 0, count);
	if (flags == NULL)
		return (NULL);
	*pos = count;
	return (flags);
}

static int	ft_setconvert(int c)
{
	if (ft_strchr(CONVERTSET, c) < 0)
		return (0);
	return (c);
}

static char	*ft_setstr(const char *format, size_t pos)
{
	char	*str;

	str = ft_substr(&format[pos], 0, ft_strlen(&format[pos]));
	if (str == NULL)
		return (NULL);
	return (str);
	
	
}

t_form	*ft_setformat(const char *format)
{
	t_form	*form;
	size_t	pos;

	pos = 0;
	form = (t_form *)malloc(sizeof(t_form));
	if (form == NULL)
		return (NULL);
	if (format[pos] == '%')
	{
		pos++;
		form->flags = ft_setflags(format, &pos);
		form->convert = ft_setconvert(format[pos++]);
	}
	form->str = ft_setstr(format, pos);
	if (form->str == NULL || form->convert == 0 || form->flags == NULL)
		ft_freeform(form);
	return (form);
}

// static	int	ft_checkflags(const char *format)
// {
// 	int		i;
// 	int		j;
// 	int		count;
// 	int 	last;
// 	int	size;

// 	i = 0;
// 	last = 0;
// 	j = 0;
// 	size = (int)ft_strlen(CONVERTSET);
// 	count = 0;
// 	while (j < size)
// 	{
// 		if (format[i] == CONVERTSET[j])
// 		{
// 			if (i > last)
// 				return (-1);
// 			last = j;
// 			i = 0;
// 			j++;
// 			count++;
// 		}
// 		else if (++i == size)
// 		{
// 			if (count == 0)
// 				return (-1);
// 			i = 0;
// 			j++;
// 		}
// 	}
// 	return (count);
// }

// static char	*ft_setstring(const char *format, int pos)
// {	
// 	char	*str;

// 	str = ft_substr(str, pos, (ft_strlen(format) - pos));
// 	if (str == NULL)
// 		return (NULL);
// 	return (str);
// }

// static char	*ft_setflags(const char *format, int *pos)
// {	
// 	char	*flags;
// 	int		count;
// 	int 	i;

// 	i = -1;
// 	if (!(count = ft_checkflags(format)))
// 		return (NULL);
// 	flags = (char *)malloc(sizeof(char) * (count + 1));
// 	if (flags == NULL)
// 		return (NULL);
// 	while (++i < count)
// 		flags[i] = format[i];
// 	flags[i] = '\0';
// 	*pos = count;
// 	return (flags);
// }

// static char	ft_setconvert(const char *format, int pos)
// {	
// 	char	convert;
// 	convert = format[pos];
// 	if (convert == '\0')
// 		return (0);
// 	return (convert);
// }

// t_form	*ft_setformat(const char *format)
// {
// 	t_form	*form;
// 	size_t	pos;
// 	char	convert;
// 	char	*flags;
// 	char	*str;

// 	ft_putendl_fd("starting...", 1);
// 	pos = 0;
// 	if ((flags = ft_setflags(format, (int *)&pos)) == NULL)
// 		return (NULL);
// 	ft_putendl_fd(flags, 1);
// 	if ((convert = ft_setconvert(format, pos)) == '\0')
// 		return (NULL);
// 	ft_putendl_fd("convert done...", 1);
// 	if ((str = ft_setstring(format, (pos + 1))) == NULL)
// 	{
// 		free (flags);
// 		return (NULL);
// 	}
// 	ft_putendl_fd("starting...", 1);
// 	form = (t_form *)malloc(sizeof(t_form));
// 	if (form == NULL)
// 	{
// 		free (flags);
// 		free (str);
// 		return (NULL);
// 	}
// 	form->convert = convert;
// 	form->flags = flags;
// 	form->str = str;
// 	ft_putendl_fd("starting...", 1);
// 	return (form);
// }
