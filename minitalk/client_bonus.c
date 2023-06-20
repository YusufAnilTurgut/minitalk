/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yturgut <yusufanilturgut22@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 00:20:38 by yturgut           #+#    #+#             */
/*   Updated: 2023/06/21 00:25:49 by yturgut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		pn;
	long	result;

	i = 0;
	pn = 1;
	result = 0;
	while (str[i] == 32 || ((str[i] >= 9) && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			pn *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0') * pn;
		if (result > 2147483647)
			return (-1);
		if (result < -2147483648)
			return (0);
		i++;
	}
	return ((int)result);
}

int	main(int argc, char **argv)
{
	int	pid;
	int	size;
	int	i;

	if (argc != 3)
		return (write(2, "Argument error!!", 16));
	pid = ft_atoi(argv[1]);
	i = 0;
	while ((argv[2][i]))
	{
		size = 8;
		while (size--)
		{
			if (((argv[2][i] >> size) & 1) == 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(100);
		}
		i++;
	}
	return (0);
}
