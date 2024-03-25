/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar < itulgar@student.42istanbul.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:29:52 by itulgar           #+#    #+#             */
/*   Updated: 2024/03/18 15:29:53 by itulgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int signum)
{
	static int	i;
	static int	bit;

	if (signum == SIGUSR1)
		bit |= (1 << i);
	i++;
	if (i == 7)
	{
		write(1, &bit, 1);
		bit = 0;
		i = 0;
	}
}

int	main(void)
{
	ft_printf(" PID: %d\n", getpid());
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
		sleep(1);
	return (0);
}
