/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoojlee <yoojlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 10:08:31 by yoojlee           #+#    #+#             */
/*   Updated: 2021/12/15 13:11:23 by yoojlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include <string.h> //memset
# include <stdbool.h> //bool

typedef struct  s_info
{
    int     num_of_philo;
    int     time_to_die;
    int     time_to_eat;
    int     time_to_sleep;
    int     num_of_meals;
}               t_info;

#endif
