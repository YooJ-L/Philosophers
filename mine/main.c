/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoojlee <yoojlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 16:50:08 by yoojlee           #+#    #+#             */
/*   Updated: 2022/02/14 20:08:23 by yoojlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>

pthread_t philosopher[5];
pthread_mutex_t fork[5];

int	main(int argc, char *argv[])
{
	int	i;

	for (i = 0; i < 5; i++)
	{
		pthread_mutex_init(&fork[i], NULL);
	}
	for (i = 0; i < 5; i++)
	{
		pthread_create(&philosopher[i], NULL, (void *)func, (void *)(long)i);
	}
	for (i = 0; i < 5; i++)
	{
		pthread_join(philosopher[i], NULL);
	}
	
}