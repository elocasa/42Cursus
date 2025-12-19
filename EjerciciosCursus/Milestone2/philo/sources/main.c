/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diego <diego@student.42.fr>                #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-12-12 14:36:48 by diego             #+#    #+#             */
/*   Updated: 2025-12-12 14:36:48 by diego            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
PARAMETROS

number_of_philosophers
time_to_die
time_to_eat
time_to_sleep
[number_of_times_each_philosopher_must_eat]
*/

int	main(int ac, char **av)
{
	t_program program;
	t_philo philos[MAX_PHILOS];
	pthread_mutex_t forks[MAX_PHILOS];

	init_program(&program, philos);
	init_forks(philos->num_of_philos, forks);
	init_philos(philos, &program, forks, ac, av);
}