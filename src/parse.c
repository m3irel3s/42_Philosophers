/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:28:33 by jmeirele          #+#    #+#             */
/*   Updated: 2025/03/19 17:25:50 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_check_valid_number(char *str);
static int	ft_validate_argv(char **argv);
static long	ft_convert_into_nb(char *str);
static long	ft_atol(char *str);

// argv[1] = number_of_philosophers
// argv[2] = time_to_die
// argv[3] = time_to_eat
// argv[4] = time_to_sleep
// argv[5] = number_of_times_each_philosopher_must_eat

void	ft_validate_and_set(t_data *data, t_philo *philo, char **argv)
{
	(void)philo;
	ft_validate_argv(argv);
	data->n_philos = (int)ft_convert_into_nb(argv[1]);
	data->time_to_die = ft_convert_into_nb(argv[2]);
	data->time_to_eat = ft_convert_into_nb(argv[3]);
	data->time_to_sleep = ft_convert_into_nb(argv[4]);
	if (argv[5])
		data->must_eat_count = (int)ft_convert_into_nb(argv[5]);
	else
		data->must_eat_count = -1;
	if (data->n_philos < 1 || data->n_philos > 200 || \
	data->time_to_die < 60 || data->time_to_eat < 60 || \
	data->time_to_sleep < 60 || data->must_eat_count == 0)
	{
		ft_print_err("Invalid parameteres given to the program\n", 2);
		exit(1);
	}
}

static int	ft_validate_argv(char **argv)
{	
	int i = 1;
	while (argv[i])
	{
		if (ft_check_valid_number(argv[i]) == FAILURE)
		{
			ft_print_err("Invalid number given\n", 2);
			exit(1);
		}
		i++;
	}
	return SUCCESS;
}

static long	ft_convert_into_nb(char *str)
{
	long	num;

	num = ft_atol(str);
	if (num < 0 || num >= INT_MAX)
	{
		ft_print_err("Number out of limits\n", 2);
		exit(1);
	}
	return num;
}

static long	ft_atol(char *str)
{
	int		i;
	long	res;

	i = 0;
	res = 0;
	while (str[i] && ft_is_space(str[i]))
		i++;
	if (str[i] == '+')
		i++;
	while(str[i] && ft_is_num(str[i]))
	{
		res = res * 10 + str[i] - 48;
		i++;
	}
	return res;
}

static int	ft_check_valid_number(char *str)
{
	int	i;

	i = 0;
	while (str[i] && ft_is_space(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			return FAILURE;
		i++;
	}
	while (str[i])
	{
		if (ft_is_num(str[i]))
			i++;
		else
			return FAILURE;
	}
	return SUCCESS;
}
