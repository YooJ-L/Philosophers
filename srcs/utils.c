/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoojlee <yoojlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 14:23:04 by yoojlee           #+#    #+#             */
/*   Updated: 2022/03/01 19:33:49 by yoojlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	print_death(t_philo *philo, char *str)
{
	long long 	time;

	pthread_mutex_lock(&philo->system->print);
	time = get_current_time() - philo->system->begin_time;
	// printf("PRINT_DEATH system->begin_time:%lld\n", philo->system->begin_time);
	printf("%lld %d %s\n", time, philo->idx + 1, str);
	pthread_mutex_unlock(&philo->system->print);
}

void	print_act(t_philo *philo, char *str)
{
	long long 	time;

	pthread_mutex_lock(&philo->system->print);
	if (!philo->system->alive)
	{
		pthread_mutex_unlock(&philo->system->print);
		return ;
	}
	time = get_current_time() - philo->system->begin_time;
	// printf("PRINT_ACT system->begin_time:%lld\n", philo->system->begin_time);
	printf("%lld %d %s\n", time, philo->idx + 1, str);
	pthread_mutex_unlock(&philo->system->print);
}

bool	sleep_for_ms(long long ms)
{
	long long	start_time;

	start_time = get_current_time();
	if (!start_time)
		return (false);
	while (get_current_time() - start_time < ms)
		usleep(10);
	return (true);
}

long long	get_current_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == -1)
		return (-1);
	return ((long long)(tv.tv_sec * 1000 + tv.tv_usec / 1000));
}

bool	ft_isspace(int c)
{
	return (c == ' ' || c == '\n' || c == '\r'
		|| c == '\v' || c == '\f' || c == '\t');
}

bool ft_isdigit(char *s)
{
	int i;
	i = 0;
	while (s[i])
	{
		if ('0' > s[i] || s[i] > '9')
			return (false);
		i++;
	}
	return (true);
}

int	ft_atoi(char *nptr, int *store)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '-')
		return (0);
	if (nptr[i] == '+')
		i++;
	if (!ft_isdigit(nptr + i))
		return (0);
	while ('0' <= nptr[i] && nptr[i] <= '9')
	{
		num *= 10;
		num += nptr[i] - 48;
		i++;
	}
	*store = num;
	return(1);
}
