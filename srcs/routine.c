/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoojlee <yoojlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 15:27:30 by yoojlee           #+#    #+#             */
/*   Updated: 2022/03/03 08:26:53 by yoojlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	start_eating(t_system *system, t_philo *philo)
{
	pthread_mutex_lock(&system->fork[philo->left]);
	print_act(philo, "has taken a fork");
	pthread_mutex_lock(&system->fork[philo->right]);
	print_act(philo, "has taken a fork");
	print_act(philo, "is eating");
	philo->start_eating_time = get_current_time();
	sleep_for_ms(philo->system->time_to_eat);
	pthread_mutex_unlock(&system->fork[philo->left]);
	pthread_mutex_unlock(&system->fork[philo->right]);
	philo->count++;
	if (system->must_eat != -1 && philo->count == system->must_eat)
	{
		system->count_current_done++;
	}
}

void	start_sleeping(t_philo *philo)
{
	print_act(philo, "is sleeping");
	sleep_for_ms(philo->system->time_to_sleep);
}

void	start_thinking(t_philo *philo)
{
	print_act(philo, "is thinking");
}
