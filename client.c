/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lykalon <lykalon@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:39:04 by lykalon           #+#    #+#             */
/*   Updated: 2022/03/07 14:39:10 by lykalon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	action(int sig, siginfo_t *act, void *old)
{
	(void)sig;
	(void)act;
	(void)old;
}

static void	send_char(int pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c % 2 == 0)
		{
			kill(pid, SIGUSR1);
		}
		else
		{
			kill(pid, SIGUSR2);
		}
		pause();
		usleep(30);
		c /= 2;
		++i;
	}
}

void	send_str(int pid, char *str)
{
	while (*str)
	{
		send_char(pid, *str);
		str++;
	}
	send_char(pid, 0);
}

int	main(int argc, char **argv)
{
	struct sigaction	act;

	act.sa_sigaction = action;
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &act, NULL);
	if (argc != 3)
	{
		mt_putstr("Usage: ./client [PID] [message]", 1);
		exit(-1);
	}
	else
	{
		send_str(mt_atoi(argv[1]), argv[2]);
	}
}
