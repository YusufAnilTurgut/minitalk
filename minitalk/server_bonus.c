/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yturgut <yusufanilturgut22@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 00:00:52 by yturgut           #+#    #+#             */
/*   Updated: 2023/06/21 00:26:19 by yturgut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int signal)
{
	static unsigned char	c;
	static int				max = 128;

	if (signal == SIGUSR2)
		c += max;
	max /= 2;
	if (max == 0)
	{
		write(1, &c, 1);
		c = 0;
		max = 128;
	}
}

int	main(void)
{
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	ft_printf("Server PID: %d\n", getpid());
	while (1)
	{
		sleep(1);
	}
	return (0);
}
