/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resource.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoojlee <yoojlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 16:15:46 by jseo              #+#    #+#             */
/*   Updated: 2021/12/13 17:54:12 by yoojlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_fork(t_philo *philo)
{
	if (pthread_mutex_lock(&philo->op->f[philo->l])
		|| !console(philo, GRAB)
		|| pthread_mutex_lock(&philo->op->f[philo->r])
		|| !console(philo, GRAB))
		pthread_mutex_unlock(&philo->op->t);
}

void	put_fork(t_philo *philo)
{
	if (pthread_mutex_unlock(&philo->op->f[philo->l])
		|| pthread_mutex_unlock(&philo->op->f[philo->r]))
		pthread_mutex_unlock(&philo->op->t);
}