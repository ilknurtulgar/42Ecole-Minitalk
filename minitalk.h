/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar < itulgar@student.42istanbul.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 18:48:23 by itulgar           #+#    #+#             */
/*   Updated: 2024/03/18 14:58:21 by itulgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "ft_printf/ft_printf.h"
# include <signal.h>
# include <unistd.h>

int		ft_atoi(char *src);
void	signal_a(int a);
void	bitwise(char c, int pid);
void	bitwise_unix(char c, int pid);
void	signal_handler(int signum);
void	handler(int sig, siginfo_t *siginfo, void *context);

#endif