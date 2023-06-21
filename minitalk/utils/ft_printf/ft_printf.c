/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yturgut <yturgut@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:55:39 by yturgut           #+#    #+#             */
/*   Updated: 2023/02/13 14:14:20 by yturgut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_findpercentsign(va_list args, const char *str)
{
	int	i;
	int	lenght;

	lenght = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			lenght += ft_findformat(args, str[i + 1]);
			i++;
		}
		else
			lenght += ft_putchar(str[i]);
		i++;
	}
	return (lenght);
}

int	ft_findformat(va_list args, const char c)
{
	int	lenght;

	lenght = 0;
	if (c == '%')
		lenght += ft_putchar('%');
	else if (c == 'c')
		lenght += ft_putchar(va_arg(args, int));
	else if (c == 's')
		lenght += ft_printstr(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		lenght += ft_printnbr(va_arg(args, int));
	else if (c == 'u')
		lenght += ft_printnumber(va_arg(args, unsigned int), c);
	else if (c == 'X')
		lenght += ft_printnumber(va_arg(args, unsigned int), c);
	else if (c == 'x')
		lenght += ft_printnumber(va_arg(args, unsigned int), c);
	else if (c == 'p')
		lenght += ft_print_ptr(va_arg(args, unsigned long), c);
	return (lenght);
}

int	ft_printf(const char *str, ...)
{
	int		result;
	va_list	args;

	result = 0;
	va_start(args, str);
	result = ft_findpercentsign(args, str);
	va_end(args);
	return (result);
}
