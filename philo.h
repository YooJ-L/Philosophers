/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoojlee <yoojlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 16:28:48 by yoojlee           #+#    #+#             */
/*   Updated: 2022/02/28 19:59:29 by yoojlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <sys/time.h> //gettimeofday
# include <pthread.h>
# include <unistd.h> //usleep
# include <stdbool.h> //bool
# include <stdlib.h> //malloc
# include <stdio.h> //printf
# include <string.h> //memset

typedef struct	s_system
{
	int				philos_total_num;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	int				count_current_done;
	pthread_mutex_t	print;
	pthread_mutex_t	time; //?
	pthread_mutex_t	*fork;
	long long		begin_time;
}				t_system;

typedef struct	s_philo
{
	int			idx;
	int			left;
	int			right;
	int			count;
	bool		alive; //출력하는 도중에 죽은 경우 확인을 위해 필요
	pthread_t	thread;
	pthread_t	monitor;
	t_system	*system;
	long long	start_eating_time;
}				t_philo;

// init.c
bool	init_arguments(t_system *system, int argc, char **argv);
bool	init_philo_and_forks(t_system *system, t_philo **philo);
bool	init_mutex(t_system *system);
bool	init(t_system *system, t_philo **philo, int argc, char **argv);

//philo.c
void	*monitor(void *arg);
void	*start_routine(void *arg);
bool	create_pthread(t_system *system, t_philo *philo);

//routine.c
void	pick_up_fork(t_system *system, t_philo *philo);
void	start_eating(t_philo *philo);
void	put_down_fork(t_system *system, t_philo *philo);
void	start_sleeping(t_philo *philo);
void	start_thinking(t_philo *philo);

//utils.c
void	print_death(t_philo *philo, char *str);
void	print_act(t_philo *philo, char *str);
long long	get_current_time(void);
bool		sleep_for_ms(long long ms);
int	ft_atoi(char *nptr, int *store);
