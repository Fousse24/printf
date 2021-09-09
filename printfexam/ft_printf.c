/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 12:54:05 by sfournie          #+#    #+#             */
/*   Updated: 2021/08/20 13:14:56 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//13h00

int	ft_strlen(char	*s)
{
	int	count = 0;

	while (*(s++))
		count++;
	return (count);
}

char	*ft_strappend(char *dst, char *src, int len)
{
	int		size;
	int		i;
	char	*str;

	size = ft_strlen(dst) + len;
	str = (char *)malloc(sizeof(char) * (size + 1));
	i = -1;
	while (dst[++i])
		str[i] = dst[i];
	while (len-- > 0)
		str[i++] = *(src++)
	str[i] = '\0';
	free(dst);
	return (dst);
}

void	ft_strtrim(char *s1, char *s2)
{
	while (*s2)
		*(s1++) = *(s2++);
	while (*s1)
		*s1 = '\0';
}

char	*ft_init_buf(char *buf)
{
	int	i = 0;

	if (buf == NULL)
	{
		buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (buf == NULL)
			return (NULL)
		while (i <= BUFFER_SIZE)
			buf[i++] = '\0';
	}
	return (buf);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*line;
	int			i;
	int			bytes;

	bytes = 1;
	i = -1;
	buf = ft_init_buf(buf);
	if (buf == NULL)
		return (NULL)
	if (!*buf)
		bytes = read(fd, buf, BUFFER_SIZE);
	if (bytes <= 0)
	{
		free(buf);
		buf = NULL;
		return (NULL)
	}
	line = (char *)malloc(sizeof(char));
	line[0] = '\0';
	while (bytes >= 1)
	{
		if (buf[++i] == '\n')
		{
			line = ft_strappend(line, buf, i + 1);
			ft_strtrim(buf, &buf[i]);
			return (line);
		}
		if (buf[i] == '\0')
		{
			line = ft_strappend(line, buf, i);
			bytes = read(fd, buf, BUFFER_SIZE);
			if (bytes >= 0)
				buf[bytes] = '\0';
			i = -1;
		}
	}
	free(buf);
	buf == NULL;
	if (bytes == 0)
		return (line)
	free(line);
	return (NULL);
}

