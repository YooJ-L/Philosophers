/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoojlee <yoojlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 20:56:17 by yoojlee           #+#    #+#             */
/*   Updated: 2022/03/02 23:25:25 by yoojlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	clear_all(t_system *system, t_philo *philo)
{
	clear_mutex(system);
	clear_malloc(system, philo);
}

void	clear_mutex(t_system *system)
{
	int	i;

	pthread_mutex_destroy(&system->print);
	i = -1;
	while (++i < system->philos_total_num)
	{
		pthread_mutex_destroy(&system->fork[i]);
	}
}

void	clear_malloc(t_system *system, t_philo *philo)
{
	int	i;

	i = -1;
	free(philo);
	free(system->fork);
}