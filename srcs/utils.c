/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoojlee <yoojlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 14:23:04 by yoojlee           #+#    #+#             */
/*   Updated: 2022/03/03 00:25:57 by yoojlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	print_death(t_philo *philo, char *str)
{
	long long	time;

	pthread_mutex_lock(&philo->system->print);
	time = get_current_time() - philo->system->begin_time;
	printf("%lldms %d %s\n", time, philo->idx + 1, str);
	pthread_mutex_unlock(&philo->system->print);
}

void	print_act(t_philo *philo, char *str)
{
	long long	time;

	pthread_mutex_lock(&philo->system->print);
	if (!philo->system->alive)
	{
		pthread_mutex_unlock(&philo->system->print);
		return ;
	}
	time = get_current_time() - philo->system->begin_time;
	printf("%lldms %d %s\n", time, philo->idx + 1, str);
	pthread_mutex_unlock(&philo->system->print);
}

bool	sleep_for_ms(long long ms)
{
	long long	start_time;

	start_time = get_current_time();
	if (!start_time)
		return (false);
	while (get_current_time() - start_time < ms)
		usleep(100);
	return (true);
}

long long	get_current_time(void)
{
	struct timeval	tv;
	long long		time;

	time = 0;
	if (gettimeofday(&tv, NULL) == -1)
		return (-1);
	time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (time);
}
