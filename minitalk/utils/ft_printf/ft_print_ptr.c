/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yturgut <yturgut@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:55:20 by yturgut           #+#    #+#             */
/*   Updated: 2023/02/13 14:11:01 by yturgut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(unsigned long num, char format)
{
	int	count;

	count = 0;
	count += ft_printstr("0x");
	if (num == 0)
		count += ft_putchar('0');
	else
	{
		ft_print_hex(num, format);
		count += ft_hex_len(num);
	}
	return (count);
}
