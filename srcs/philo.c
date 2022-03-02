/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoojlee <yoojlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 23:25:34 by yoojlee           #+#    #+#             */
/*   Updated: 2022/03/02 23:25:35 by yoojlee          ###   ########.fr       */
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
	while (system->alive)
	{
		if (system->must_eat &&
			system->count_current_done == system->philos_total_num)
			{
				system->alive = 0;
				return (NULL);
			}
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
	if (system->philos_total_num == 1)
	{
		print_act(philo, "has taken a fork");
		return (NULL);
	}
	if (philo->idx % 2 == 1)
		sleep_for_ms(100);
	while (system->alive)
	{
		if (system->alive)  // --> 누군가 죽은걸 확인
			start_eating(system, philo);  // 포크를 쥐고 있다.  // 왼손 오른손 포크 내려놓기
		if (system->alive)
			start_sleeping(philo);  // 포크를 들고 있지 않다.
		if (system->alive)
			start_thinking(philo);  // 포크를 들고 있지 않다.
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
	int	i;
	void	*join;

	i = -1;
	system->begin_time = get_current_time();
	if (!system->begin_time)
		return (false);
	while (++i < system->philos_total_num)
	{
		init_a_philo(system, &philo[i], i);
		if (pthread_create(&philo[i].thread, NULL, start_routine, (void *)&philo[i]))
			return (false);
		if (pthread_create(&philo[i].monitor, NULL, monitor, (void *)&philo[i]))
			return (false);
	}
	i = -1;
	while (++i < system->philos_total_num)
	{
		if (pthread_join(philo[i].thread, (void *)&join) != 0)
			return (false);
		if (pthread_join(philo[i].monitor, (void *)&join) != 0)
			return (false);
	}
	return (true);
}

int	main(int argc, char *argv[])
{
	t_system	system;
	t_philo		*philo;

	philo = NULL;
	printf("start\n");
	if (!init(&system, &philo, argc, argv))
	{
		printf("ERROR: init\n");
		return (-1);
	}
	if (!create_pthread(&system, philo))
	{
		clear_all(&system,philo);
		return (-1);
	}
	clear_all(&system, philo);
	return (0);
}

	// 			printf("--------\n");
	// printf("system->philos_total_num: %d\n", system->philos_total_num);
	// printf("system->timetodie: %d\n", system->time_to_die);
	// printf("system->timetoeat: %d\n", system->time_to_eat);
	// printf("system->timetosleep: %d\n", system->time_to_sleep);
	// printf("system->must_eat: %d\n", system->must_eat);
	// printf("system->count_current_done: %d\n", system->count_current_done);
	// printf("system->BEGIN_TIME: %lld\n", system->begin_time);
