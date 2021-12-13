/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoojlee <yoojlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 16:16:15 by jseo              #+#    #+#             */
/*   Updated: 2021/12/13 17:54:22 by yoojlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_eat(t_philo *philo)
{
	if (!console(philo, EATING)
		|| !chrono(&philo->cur))
		pthread_mutex_unlock(&philo->op->t);
	++(philo->c);
	elapse(philo, philo->cur, philo->op->time_eat);
	if (philo->op->limit && philo->c == philo->op->limit)
		if (++(philo->op->meet) >= philo->op->total)
			if (!console(philo, FULL))
				pthread_mutex_unlock(&philo->op->t);
}

void	philo_sleep(t_philo *philo)
{
	if (!console(philo, SLEEPING))
		pthread_mutex_unlock(&philo->op->t);
	elapse(philo, 0, philo->op->time_nap);
}

void	philo_think(t_philo *philo)
{
	if (!console(philo, THINKING))
		pthread_mutex_unlock(&philo->op->t);
}