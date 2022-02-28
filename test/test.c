/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 19:59:01 by yoojlee           #+#    #+#             */
/*   Updated: 2021/11/09 18:00:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>

typedef struct	s_info
{
	pthread_mutex_t	check_died;
}				t_info;


typedef	struct	s_philo
{
	t_info			*info;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
}				t_philo;

void	take_forks(t_philo *p)
{
	pthread_mutex_lock(p->left_fork);
	pthread_mutex_lock(p->right_fork);
}

void	sleep_philo(t_philo *p)
{
	pthread_mutex_unlock(p->left_fork);
	pthread_mutex_unlock(p->right_fork);
}

t_common_info		*init_check_died_mutex(void)
{
	pthread_mutex_t	*check_died;

	check_died = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	if (check_died == NULL)
		return (NULL);
	pthread_mutex_lock(check_died);
	return (check_died);
}

pthread_mutex_t		*init_forks(int num)
{
	pthread_mutex_t		*forks;
	int					i;

	if (!(forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * num)))
		return (NULL);
	i = 0;
	while (i < num)
	{
		if (pthread_mutex_init(&forks[i], NULL) < 0) // mutex 객체 초기화
		{
			free(forks);
			return (NULL);
		}
		i++;
	}
	return (forks);
}

t_philo		init_philo(int num)
{
	t_philo			*philo;
	pthread_mutex_t	*forks;
	int				i;

	philo = (t_philo *)malloc(sizeof(t_philo) * num);
	if (philo == NULL)
		return (NULL);
	forks = init_forks(num);
	if (forks == NULL)
		return (NULL);
	i = 0;
	while (i < num)
	{
		philo[i].right_fork = &forks[(i + 1) % num];
		philo[i].left_fork = &forks[i];
		i++;
	}
	return (philo);
}

int		start_pthread(t_philo *p)
{
	int		i;

	i = 0;
	while (i < 5)
	{
		if (pthread_create(&(p[i].pthread), NULL, &routine, (void *)&(p[i]) != 0))
			return (1);
		if (pthread_detach(p[i].pthread) != 0)
			return (1);
		i++;
	}
	pthread_mutex_lock(p->info->check_died);
	pthread_mutex_unlock(p->info->check_died);
}

int		main(int argc, char *argv[])
{
	int		i;
	pthread_t	philo;

	i = 0;
	while (i < 5)
	{
		if (pthread_create(&philo, NULL, &routine, (void *)&common) != 0) //성공 시 리턴 0
			return (1);
		if (pthread_detach(philo) != 0) //성공 시 리턴 0
			return (1);
		i++;
	}
}
