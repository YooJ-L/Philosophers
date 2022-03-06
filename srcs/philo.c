/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoojlee <yoojlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 23:25:34 by yoojlee           #+#    #+#             */
/*   Updated: 2022/03/06 21:16:48 by yoojlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	monitor_philos(t_system *system, t_philo *philo)
{
	int	i;

	sleep_for_ms(system->time_to_die - 10);
	while (system->alive)
	{
		i = -1;
		while (++i < system->philos_total_num && system->alive)
		{
			if (system->must_eat != -1 \
					&& system->count_current_done == system->philos_total_num)
			{
				system->alive = 0;
				return ;
			}
			if (get_current_time() - philo[i].start_eating_time \
				 > system->time_to_die)
			{
				system->alive = 0;
				print_death(&philo[i], "died");
				return ;
			}
		}
	}
}

void	*start_routine(void *arg)
{
	t_philo		*philo;
	t_system	*system;

	philo = (t_philo *)arg;
	system = philo->system;
	if (!check_must_eat(system))
		return (NULL);
	if (system->philos_total_num == 1)
	{
		print_act(philo, "has taken a fork");
		return (NULL);
	}
	if (philo->idx % 2 == 1)
		sleep_for_ms(system->time_to_eat / 2);
	while (system->alive)
	{
		if (system->alive)
			start_eating(system, philo);
		if (system->alive)
			start_sleeping(philo);
		if (system->alive)
			start_thinking(philo);
	}
	return (NULL);
}

void	init_a_philo(t_system *system, t_philo *philo, int i)
{
	philo->idx = i;
	philo->left = i;
	philo->right = (i + 1) % system->philos_total_num;
	philo->count = 0;
	philo->start_eating_time = get_current_time();
	philo->system = system;
}

bool	create_pthread(t_system *system, t_philo *philo)
{
	int		i;
	void	*join;

	i = -1;
	system->begin_time = get_current_time();
	if (!system->begin_time)
		return (false);
	while (++i < system->philos_total_num)
	{
		init_a_philo(system, &philo[i], i);
		if (pthread_create(&philo[i].thread, NULL, \
				   	start_routine, (void *)&philo[i]))
			return (false);
	}
	monitor_philos(system, philo);
	i = -1;
	while (++i < system->philos_total_num)
	{
		if (pthread_join(philo[i].thread, (void *)&join) != 0)
			return (false);
	}
	return (true);
}
