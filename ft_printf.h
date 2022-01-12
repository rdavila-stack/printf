/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavila <rdavila@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 13:46:12 by rdavila           #+#    #+#             */
/*   Updated: 2022/01/10 15:29:14 by rdavila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

int					ft_printf(const char *str, ...);
int					pick_con(va_list list, char c);
int					con_c(va_list list);
int					con_s(va_list list);
int					con_d(va_list list);
int					con_p(va_list list);
int					con_u(va_list list);
int					con_x(va_list list, char c);

void				hex_con(unsigned long int n, int *i);
void				hexstring(int i, int *p, char c);
void				ft_putchar_fd(char c, int fd);
int					ft_putnbr_fd(int n, int fd);
void				put_unsign(unsigned int n, int fd);

#endif