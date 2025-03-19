/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 13:47:23 by jmeirele          #+#    #+#             */
/*   Updated: 2025/03/19 17:24:13 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_init_philos(t_data *data, t_philo *philo);
static void	ft_init_data(t_data *data);
static void	*ft_routine();

void	ft_init_structs(t_data *data, t_philo *philo)
{
	ft_init_philos(data, philo);
	ft_init_data(data);
}

static void	ft_init_philos(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	philo = malloc(sizeof(t_philo) * data->n_philos + 1);
	while (i < data->n_philos)
	{
		philo[i].id = i;
		philo[i].meals_eaten = 0;
		philo[i].l_fork = &data->forks[i];
		philo[i].l_fork = &data->forks[(i + 1) % data->n_philos];
		pthread_create(&philo[i].th, NULL, ft_routine, &philo[i]);
		i++;
	}
}

static void	ft_init_data(t_data *data)
{
	data->start_time = ft_get_curr_time();
	printf("%ld\n", data->start_time);
}


static void	*ft_routine()
{
	return NULL;
}