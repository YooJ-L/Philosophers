/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoojlee <yoojlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 10:12:33 by yoojlee           #+#    #+#             */
/*   Updated: 2022/01/05 16:36:35 by yoojlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

static bool	check_argc(int ac)
{
	if (ac != 5 && ac != 6)
		return (false);
	return (true);
}

static bool	check_isdigit(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] < '0' || av[i][j] > '9')
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

static bool	check_overflow(char **av)
{
	// (void **)av;
	return (true);
}

bool	validate_arg(int ac, char **av, t_info *info)
{
	if (!check_argc(ac))
		return (false);
	if (!check_isdigit(av))
		return (false);
	if (!check_overflow(av))
		return (false);
	return (true);
}

bool	init(int argc, char **argv, t_info *info)
{
	if (!init_info(argc, argv, info))
		return (false);
}

bool	init_info(int argc, char **argv, t_info *info)
{

}

void	clear_info()

int main(int argc, char *argv[])
{
	t_info   info;

	memset(&info, 0, sizeof(t_info));
	if (!validate_arg(argc, argv, &info) || !init_info(argc, argv, &info))
	{
		return (ft_exit(&info, clear_info));
	}
}