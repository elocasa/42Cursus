/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diego <diego@student.42.fr>                #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-27 13:03:24 by diego             #+#    #+#             */
/*   Updated: 2025-10-27 13:03:24 by diego            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static int	ft_contains(int num, char **argv, int i)
{
	i++;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == num)
			return (1);
		i++;
	}
	return (0);
}

void	ft_checkarg(int ac, char **av)
{
	int		i;
	long	temp;
	char	**args;

	i = 0;
	if (ac == 2)
		args = ft_split(av[1], ' ');
	else
	{
		i = 1;
		args = av;
	}
	while (args[i])
	{
		temp = ft_atoi(args[i]);
		if (!ft_isnum(args[i]))
			ft_error("ERROR 1");
		if (ft_contains(temp, args, i))
			ft_error("ERROR 2");
		if (temp < -2147483648 || temp > 2147483647)
			ft_error("ERROR 3");
		i++;
	}
	if (ac == 2)
		ft_free(args);
}
