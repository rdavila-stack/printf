/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavila <rdavila@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 20:38:45 by rdavila           #+#    #+#             */
/*   Updated: 2022/01/06 14:02:20 by rdavila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

static unsigned int	ft_module_fd(int n)
{
	if (n < 0)
		return (n * (-1));
	else
		return (n);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nbr;

	if (n < 0)
		ft_putchar_fd ('-', fd);
	nbr = ft_module_fd(n);
	if (nbr >= 10)
	{
		ft_putnbr_fd(nbr / 10, fd);
		ft_putnbr_fd(nbr % 10, fd);
	}
	else
		ft_putchar_fd(nbr + '0', fd);
}

void	hex_con(unsigned long int n, int *i)
{
	if (n >= 16)
	{
		hex_con(n / 16, i);
		hex_con(n % 16, i);
	}
	else if (n <= 9)
	{
		ft_putchar_fd(n + 48, 1);
		(*i)++;
	}
	else if (n <= 16)
	{
		ft_putchar_fd(n + 87, 1);
		(*i)++;
	}
}

void	hexstring(int i, int *p, char c)
{
	int	letter;

	if (c == 'x')
		letter = 87;
	if (c == 'X')
		letter = 55;
	if (i >= 16)
	{
		hexstring (i / 16, p, c);
		hexstring (i % 16, p, c);
	}
	else if (i <= 9)
	{
		ft_putchar_fd(i + 48, 1);
		(*p)++;
	}
	else if (i <= 16)
	{
		ft_putchar_fd(i + letter, 1);
		(*p)++;
	}
}
