/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 10:55:34 by jmeirele          #+#    #+#             */
/*   Updated: 2025/03/27 12:07:27 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_atol(char *str)
{
	int		i;
	long	res;

	i = 0;
	res = 0;
	while (str[i] && ft_is_space(str[i]))
		i++;
	if (str[i] == '+')
		i++;
	while (str[i] && ft_is_num(str[i]))
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res);
}

int	ft_check_valid_number(char *str)
{
	int	i;

	i = 0;
	while (str[i] && ft_is_space(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			return (FAILURE);
		i++;
	}
	while (str[i])
	{
		if (ft_is_num(str[i]))
			i++;
		else
			return (FAILURE);
	}
	return (SUCCESS);
}
