/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar < itulgar@student.42istanbul.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:29:47 by itulgar           #+#    #+#             */
/*   Updated: 2024/03/18 15:30:02 by itulgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(char *src)
{
	int	res;
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	res = 0;
	while ((src[i] >= 9 && src[i] <= 13) || src[i] == ' ')
		i++;
	if (src[i] == '-' || src[i] == '+')
	{
		if (src[i] == '-')
			sign *= -1;
		i++;
	}
	while (src[i] >= '0' && src[i] <= '9')
	{
		res = (res * 10) + src[i] - '0';
		i++;
	}
	return (res * sign);
}

void	bitwise(char c, int pid)
{
	int	bit;

	bit = 0;
	while (bit <= 6)
	{
		if ((c >> bit) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit++;
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	int	server_pid;
	int	i;

	i = 0;
	if (argc == 3)
	{
		server_pid = ft_atoi(argv[1]);
		while (argv[2][i])
		{
			bitwise(argv[2][i], server_pid);
			i++;
		}
	}
	else
		ft_printf("you added too nany arguments \n");
	return (0);
}
