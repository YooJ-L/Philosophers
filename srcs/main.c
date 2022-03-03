/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoojlee <yoojlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 08:23:31 by yoojlee           #+#    #+#             */
/*   Updated: 2022/03/03 14:58:46 by yoojlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char *argv[])
{
	t_system	system;
	t_philo		*philo;

	philo = NULL;
	if (!init(&system, &philo, argc, argv))
	{
		printf("ARGUMENTS ERROR\n");
		return (-1);
	}
	if (!create_pthread(&system, philo))
	{
		clear_all(&system, philo);
		return (-1);
	}
	clear_all(&system, philo);
	printf("END\n");
	return (0);
}
