/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavila <rdavila@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 20:10:42 by rdavila           #+#    #+#             */
/*   Updated: 2022/01/06 14:43:29 by rdavila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_printf(const char *str, ...)
{
	va_list	va;
	int		size;
	int		i;

	va_start(va, str);
	size = 0; 
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '%')
		{
			write(1, &str[i], 1);
			size++;
		}
		else
		{
			size += pick_con(va, str[i + 1]);
			i++;
		}
		i++;
	}
	va_end(va);
	return (size);
}

int main()
{
	int ret;
	unsigned int input;

	input = 2147483647;

	ret = ft_printf("%d", input);
	printf("\n%d\n", input);
}