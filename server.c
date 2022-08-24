/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lykalon <lykalon@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:40:30 by lykalon           #+#    #+#             */
/*   Updated: 2022/03/07 14:40:31 by lykalon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	mt_putchar(char c)
{
	write(1, &c, 1);
}

static void	mt_putnbr(int n)
{
	if (n == -2147483648)
	{
		mt_putstr("-2147483648", 0);
		return ;
	}
	if (n < 0)
	{
		mt_putchar('-');
		n = -n;
	}
	if (n > 9)
	{
		mt_putnbr(n / 10);
		mt_putnbr(n % 10);
	}
	else
		mt_putchar((char)(n + '0'));
}

void	action(int sig, siginfo_t *act, void *old)
{
	static int	i;
	static char	c;
	static char	*str;
	static int	index;

	(void)old;
	if (!str)
	{
		str = malloc(50000);
		if (!str)
			exit(1);
	}
	if (sig == SIGUSR2)
		c = (char)(c | 1 << i);
	++i;
	if (i == 8)
	{
		i = 0;
		str[index++] = c;
		if (c == '\0')
			print_str(&str, &index);
		c = 0;
	}
	usleep(30);
	kill(act->si_pid, SIGUSR1);
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	act;

	pid = getpid();
	mt_putstr("PID: ", 0);
	mt_putnbr(pid);
	mt_putchar('\n');
	act.sa_sigaction = action;
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}
