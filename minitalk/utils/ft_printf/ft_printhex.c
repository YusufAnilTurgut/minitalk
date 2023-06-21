/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yturgut <yturgut@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:56:19 by yturgut           #+#    #+#             */
/*   Updated: 2023/02/13 14:21:03 by yturgut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

int	ft_hex_len(unsigned long num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		num = num / 16;
		len++;
	}
	return (len);
}

void	ft_print_hex(unsigned long num, char format)
{
	if (num >= 16)
	{
		ft_print_hex(num / 16, format);
		ft_print_hex(num % 16, format);
	}
	else
	{
		if (num <= 9)
			ft_putchar(num + '0');
		else
		{
			if (format == 'x' || format == 'p')
				ft_putchar(num - 10 + 'a');
			else
				ft_putchar(num - 10 + 'A');
		}
	}
}
