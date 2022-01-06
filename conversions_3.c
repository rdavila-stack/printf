/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavila <rdavila@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 14:01:47 by rdavila           #+#    #+#             */
/*   Updated: 2022/01/06 14:03:43 by rdavila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_unsign(unsigned int n, int fd)
{
	if (n >= 10)
	{
		put_unsign(n / 10, fd);
		put_unsign(n % 10, fd);
	}
	else
		ft_putchar_fd(n + '0', fd);
}

int	pick_con(va_list list, char c)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += con_c(list);
	else if (c == 's')
		len += con_s(list);
	else if (c == 'p')
		len += con_p(list);
	else if (c == 'd' || c == 'i')
		len += con_d(list);
	else if (c == 'u')
		len += con_u(list);
	else if (c == 'x' || c == 'X')
		len += con_x(list, c);
	else if (c == '%')
		len += write(1, "%", 1);
	else
	{
		write(1, &c, 1);
		len++;
	}
	return (len);
}

int	con_x(va_list list, char c)
{
	unsigned int	i;
	int				len;

	len = 0;
	i = va_arg(list, unsigned int);
	hexstring(i, &len, c);
	return (len);
}