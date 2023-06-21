/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yturgut <yturgut@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:55:17 by yturgut           #+#    #+#             */
/*   Updated: 2023/02/13 14:09:47 by yturgut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printnbr(int a)
{
	int		len;
	char	*num;

	len = 0;
	num = ft_itoa(a);
	len += ft_printstr(num);
	free(num);
	return (len);
}

int	ft_printnumber(unsigned int a, char format)
{
	int		len;
	char	*num;

	len = 0;
	if (a == 0)
		return (ft_putchar('0'));
	if (format == 'X' || format == 'x')
	{
		ft_print_hex(a, format);
		return (ft_hex_len(a));
	}
	if (format == 'p')
		return (ft_print_ptr(a, format));
	else
	{
		num = ft_itoa(a);
		len += ft_printstr(num);
		free(num);
	}
	return (len);
}
