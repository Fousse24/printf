/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 18:27:52 by sfournie          #+#    #+#             */
/*   Updated: 2021/08/17 20:57:18 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"
#include	<stdarg.h>
#include	<unistd.h>
#include	<stdio.h>
#include	<limits.h>

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	count;

	count = 0;
	if (s == NULL)
		count += ft_putstr("(null)");
	while (s != NULL && *s)
		count += ft_putchar(*(s++));
	return (count);
}

long ft_countdigits(long n)
{
	long	count;

	count = 1;
	if (n < 0)
		n *= -1;
	while (n / 10 != 0)
	{
		count *= 10;
		n /= 10;
	}
	return (count);
}

int	ft_putnbr(int n)
{
	long	nb;
	long	multi;
	int		neg;
	int		bytes;
	char	c;

	bytes = 0;
	nb = n;
	neg = 1;
	multi = ft_countdigits(nb);
	if (nb < 0)
	{
		nb *= -1;
		bytes += ft_putchar('-');
	}
	while (multi > 0)
	{
		c = (nb / multi) + '0';
		ft_putchar(c);
		nb -= (c - 48) * multi;
		multi /= 10;
		bytes++;
	}
	return (bytes);
}

int	ft_puthexa(unsigned int n)
{
	char *base = "0123456789abcdef";
	int	bytes;

	bytes = 0;
	if (n / 16 != 0)
		bytes += ft_puthexa(n / 16);
	bytes += ft_putchar(base[n % 16]);
	return (bytes);
}

int	ft_convert(va_list vl, char *f, int *i)
{
	int	bytes;

	bytes = 0;
	if (f[++(*i)])
	{
		if (f[*i] == 'c')
			bytes = ft_putchar(va_arg(vl, unsigned int));
		else if (f[*i] == 's')
			bytes = ft_putstr(va_arg(vl, char *));
		else if (f[*i] == 'd')
			bytes = ft_putnbr(va_arg(vl, int));
		else if (f[*i] == 'x')
			bytes = ft_puthexa(va_arg(vl, unsigned int));
		else
		{
			bytes = ft_putchar('%');
			bytes += ft_putchar(f[*i]);
		}
		(*i)++;
	}
	return (bytes);
}

//19h
int	ft_printf(const char *format, ...)
{
	va_list vl;
	int		i;
	int		bytes;

	if (format == NULL)
		return (0);
	va_start(vl, format);
	i = 0;
	bytes = 0;
	while (format[i])
	{
		if (format[i] != '%')
			bytes += ft_putchar(format[i++]);
		else
			bytes += ft_convert(vl, format, &i);
	}
	va_end(vl);
	return (bytes);
}

// int	main(void)
// {
// 	int	bytes;
// 	bytes = ft_printf("allo s=%s|deux c=%c|trois d=%d|quatre x=%x|cinq %=", NULL, 'z', -0, LONG_MAX);
// 	printf("\n%d", bytes);
// }
