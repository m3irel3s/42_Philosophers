/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:28:33 by jmeirele          #+#    #+#             */
/*   Updated: 2025/03/27 11:38:14 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_validate_argv(char **argv);
static long	ft_convert_into_nb(char *str);
static int	ft_validate_numbers(t_data *data, char **argv);

int	ft_parse_and_set(t_data *data, char **argv)
{
	if (ft_validate_argv(argv) != SUCCESS)
		return (FAILURE);
	if (ft_validate_numbers(data, argv) != SUCCESS)
		return (FAILURE);
	if (argv[5])
		data->must_eat_count = (int)ft_convert_into_nb(argv[5]);
	else
		data->must_eat_count = -1;
	if (data->n_philos < 1 || data->n_philos > 200
		|| data->time_to_die < 60 || data->time_to_eat < 60
		|| data->time_to_sleep < 60 || data->must_eat_count == 0)
	{
		ft_print_err("Invalid parameters given to the program\n", 2);
		return (FAILURE);
	}
	return (SUCCESS);
}

static int	ft_validate_numbers(t_data *data, char **argv)
{
	if (ft_convert_into_nb(argv[1]) == ERROR
		|| ft_convert_into_nb(argv[2]) == ERROR
		|| ft_convert_into_nb(argv[3]) == ERROR
		|| ft_convert_into_nb(argv[4]) == ERROR
		|| (argv[5] && ft_convert_into_nb(argv[5]) == ERROR))
		return (FAILURE);
	data->n_philos = (int)ft_convert_into_nb(argv[1]);
	data->time_to_die = ft_convert_into_nb(argv[2]);
	data->time_to_eat = ft_convert_into_nb(argv[3]);
	data->time_to_sleep = ft_convert_into_nb(argv[4]);
	return (SUCCESS);
}

static int	ft_validate_argv(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (ft_check_valid_number(argv[i]) == FAILURE)
		{
			ft_print_err("Invalid number given\n", 2);
			return (FAILURE);
		}
		i++;
	}
	return (SUCCESS);
}

static long	ft_convert_into_nb(char *str)
{
	long	num;

	num = ft_atol(str);
	if (num < 0 || num >= INT_MAX)
	{
		ft_print_err("Number out of limits\n", 2);
		return (ERROR);
	}
	return (num);
}
