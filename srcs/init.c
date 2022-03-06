/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoojlee <yoojlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 14:18:40 by yoojlee           #+#    #+#             */
/*   Updated: 2022/03/06 21:17:26 by yoojlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

bool	init_arguments(t_system *system, int argc, char **argv)
{
	memset((void *)system, 0, sizeof(t_system));
	system->must_eat = -1;
	system->alive = 1;
	if (!ft_atoi(argv[1], &system->philos_total_num)
		|| !ft_atoi(argv[2], &system->time_to_die)
		|| !ft_atoi(argv[3], &system->time_to_eat)
		|| !ft_atoi(argv[4], &system->time_to_sleep))
		return (false);
	if (argc == 6 && !ft_atoi(argv[5], &system->must_eat))
		return (false);
	return (true);
}

bool	init_philo_and_forks(t_system *system, t_philo **philo)
{
	*philo = (t_philo *)malloc(sizeof(t_philo) * system->philos_total_num);
	if (!*philo)
		return (false);
	system->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) \
			* system->philos_total_num);
	if (!system->fork)
		return (false);
	return (true);
}

bool	init_mutex(t_system *system)
{
	int	i;

	i = 0;
	while (i < system->philos_total_num)
	{
		if (pthread_mutex_init(&system->fork[i], NULL))
			return (false);
		i++;
	}
	if (pthread_mutex_init(&system->print, NULL))
		return (false);
	if (pthread_mutex_init(&system->check, NULL))
		return (false);
	return (true);
}

bool	init(t_system *system, t_philo **philo, int argc, char **argv)
{	
	if (argc < 5 || argc > 6)
		return (false);
	if (!init_arguments(system, argc, argv))
	{
		return (false);
	}
	if (!init_philo_and_forks(system, philo))
	{
		clear_malloc(system, *philo);
		return (false);
	}
	if (!init_mutex(system))
	{
		clear_all(system, *philo);
		return (false);
	}
	return (true);
}
