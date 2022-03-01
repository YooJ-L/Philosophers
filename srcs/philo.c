/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoojlee <yoojlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 16:35:35 by yoojlee           #+#    #+#             */
/*   Updated: 2022/03/01 19:34:07 by yoojlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*monitor(void *arg)
{
	t_philo		*philo;
	t_system	*system;

	philo = (t_philo *)arg;
	system = philo->system;
	sleep_for_ms(system->time_to_die - 10);
	while (true)
	{
		if (system->must_eat &&
			system->count_current_done == system->philos_total_num)
			return (NULL);
		if (get_current_time() - philo->start_eating_time > system->time_to_die)
		{
			system->alive = 0;
			print_death(philo, "died");
			break ;
		}
	}
	return (NULL);
}

void	*start_routine(void *arg)
{
	t_philo		*philo;
	t_system	*system;

	philo = (t_philo *)arg;
	system = philo->system;
	if (philo->idx % 2 == 0)
		sleep_for_ms(10);
	while (true)
	{
		pick_up_fork(system, philo);
		start_eating(philo);
		put_down_fork(system, philo);
		start_sleeping(philo);
		start_thinking(philo);
	}
	return (NULL);
}

bool	create_pthread(t_system *system, t_philo *philo)
{
	int	i;
	int	join;

	i = -1;
	if (pthread_mutex_lock(&system->time))
		return (false);
	system->begin_time = get_current_time();
	if (!system->begin_time)
		return (false);
	while (++i < system->philos_total_num)
	{
		philo[i].idx = i;
		philo[i].left = i;
		philo[i].right = (i + 1) % system->philos_total_num;
		philo[i].count = 0;
		philo[i].system = system;
		if (pthread_create(&philo->thread, NULL, start_routine, (void *)&philo[i])
			|| pthread_join(philo->thread, (void *)&join)
			|| pthread_detach(philo->thread))
			return (false);
		if (pthread_create(&philo->monitor, NULL, monitor, (void *)&philo[i])
			|| pthread_join(philo->monitor, (void *)&join)
			|| pthread_detach(philo->monitor))
			return (false);
	}
	if (pthread_mutex_lock(&system->time))
		return (false);
	return (true);
}

int	main(int argc, char *argv[])
{
	t_system	system;
	t_philo	*philo;

	philo = NULL;
	printf("start\n");
	if (!init(&system, &philo, argc, argv))
	{
		printf("ERROR: init\n");
		return (-1);
	}
	if (!create_pthread(&system, philo))
		return (-1);
}

	// 			printf("--------\n");
	// printf("system->philos_total_num: %d\n", system->philos_total_num);
	// printf("system->timetodie: %d\n", system->time_to_die);
	// printf("system->timetoeat: %d\n", system->time_to_eat);
	// printf("system->timetosleep: %d\n", system->time_to_sleep);
	// printf("system->must_eat: %d\n", system->must_eat);
	// printf("system->count_current_done: %d\n", system->count_current_done);
	// printf("system->BEGIN_TIME: %lld\n", system->begin_time);