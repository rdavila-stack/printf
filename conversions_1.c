/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavila <rdavila@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 20:38:35 by rdavila           #+#    #+#             */
/*   Updated: 2022/01/06 14:11:20 by rdavila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	con_c(va_list list)
{
	char	c;

	c = (char)va_arg(list, int);
	write(1, &c, 1);
	return (1);
}

int	con_s(va_list list)
{
	int		len;
	char	*ptr;

	ptr = va_arg(list, char *);
	len = 0;
	if (ptr == NULL)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	while (ptr[len] != '\0')
	{
		write(1, &ptr[len], 1);
		len++;
	}
	return (len);
}

int	con_d(va_list list)
{
	int	i;
	int	len;

	len = 0;
	i = va_arg(list, int);
	ft_putnbr_fd(i, len);
	return (len);
}

int	con_p(va_list list)
{
	int					len;
	unsigned long int	i;

	len = 0;
	i = va_arg(list, unsigned long int);
	if (i == 0)
	{
		write(1, "0x0", 3);
		return (3);
	}
	write(1, "0x", 2);
	len += 2;
	hex_con(i, &len);
	return (len);
}

int	con_u(va_list list)
{
	unsigned int	i;
	int				len;

	len = 0;
	i = va_arg(list, unsigned int);
	put_unsign(i, len);
	return (len);
}
