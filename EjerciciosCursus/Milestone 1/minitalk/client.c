/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diego <diego@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 12:32:16 by diego             #+#    #+#             */
/*   Updated: 2025/09/03 16:25:07 by diego            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft/libft.h"

static void action(int sig)
{
	static int received = 0;

	if (sig == SIGUSR1)
		++received;
	else
	{
		ft_putnbr_fd(received, 1);
		ft_putchar_fd('\n', 1);
		exit(0);
	}
}

static void mt_kill(int pid, char *str)
{
	int	i;
	char	c;

	while(*str)
	{
		i = 8;
		c = *str++;
		while(i--)
		{
			if (c >> i & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(200);
		}
	}
	i = 8;
	while(i--)
	{
		kill(pid, SIGUSR1);
		usleep(200);
	}
}

int main(int argc, char **argv)
{
	if(argc != 3 || !ft_strlen(argv[2]))
		return(1);
	ft_putstr_fd("Enviado	: ", 1);
	ft_putnbr_fd(ft_strlen(argv[2]), 1);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("Recibido : ", 1);
	signal(SIGUSR1, action);
	signal(SIGUSR2, action);
	mt_kill(ft_atoi(argv[1]), argv[2]);
	while(1)
		pause();
	return (0);
}