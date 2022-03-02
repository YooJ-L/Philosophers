/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoojlee <yoojlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 00:24:17 by yoojlee           #+#    #+#             */
/*   Updated: 2022/03/03 00:24:59 by yoojlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

bool	ft_isspace(int c)
{
	return (c == ' ' || c == '\n' || c == '\r'
		|| c == '\v' || c == '\f' || c == '\t');
}

bool	ft_isdigit(char *s)
{
	int	i;

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
	return (1);
}
