/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diego <diego@student.42.fr>                #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-12-18 18:01:10 by diego             #+#    #+#             */
/*   Updated: 2025-12-18 18:01:10 by diego            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_user_input(t_philo *philos, char **av)
{
		philos->time_to_die = ft_atoi(av[2]);
		philos->time_to_eat = ft_atoi(av[3]);
		philos->time_to_sleep = ft_atoi(av[4]);
		if(av[5])
			philos->num_of_philos = ft_atoi(av[5]);
		else
			philos->num_of_philos = -1;
}

void	init_philos(t_philo *philos, t_program *program, pthread_mutex_t *forks,
		int ac, char **av)
{
	int	i;

	i = 0;
	while (i < av[1])
	{
		philos[i].id = i + 1;
		philos[i].eating = 0;
		philos[i].meals_eaten = 0;
		init_user_input(&philos[i], av);
		philos[i].start_time = get_current_time();
		philos[i].last_meal = get_current_time();
		philos[i].num_of_philos = av[1];
		philos[i].write_lock = &program->write_lock;
		philos[i].meal_lock = &program->meal_lock;
		philos[i].dead_lock = &program->dead_lock;
		philos[i].l_fork = &forks[i];
		if(i == 0)
			philos[i].r_fork = &forks[philos[i].num_of_philos - 1];
		else
			philos[i].r_fork = &forks[i - 1];
	}
}

void	init_forks(int num_philos, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	while (i < num_philos)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
}

void	init_program(t_program *program, t_philo *philos)
{
	program->dead_flag = 0;
	program->philos = philos;
	pthread_mutex_init(&program->dead_lock, NULL);
	pthread_mutex_init(&program->meal_lock, NULL);
	pthread_mutex_init(&program->write_lock, NULL);
}