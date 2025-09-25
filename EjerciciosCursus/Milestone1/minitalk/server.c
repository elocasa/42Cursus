/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerezo- <dcerezo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 12:59:37 by diego             #+#    #+#             */
/*   Updated: 2025/09/08 15:47:11 by dcerezo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <signal.h>
#include <unistd.h>

struct mt_server mt_server = {0, 0, 0};

static void	mt_kill_server(unsigned char c, pid_t client_pid)
{
	if (!c)
	{
		kill(client_pid, SIGUSR2);
		client_pid = 0;
		return ;
	}
	ft_putchar_fd(c, 1);
	c = 0;
	kill(client_pid, SIGUSR1);
}

static void	action(int sig, siginfo_t *info, void *context)
{
	(void)context;
	if (!mt_server.client_pid)
		mt_server.client_pid = info->si_pid;
	mt_server.c <<= 1;
	if (sig == SIGUSR2)
		mt_server.c |= 1;
	if (++mt_server.i == 8)
	{
		mt_server.i = 0;
		mt_kill_server(mt_server.c, mt_server.client_pid);
	}
}

int	main(void)
{
	struct sigaction	s_sigaction;
	
	ft_putstr_fd("Server PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	s_sigaction.sa_sigaction = action;
	s_sigaction.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s_sigaction, 0);
	sigaction(SIGUSR2, &s_sigaction, 0);
	while (1)
		pause();
	return (0);
}
