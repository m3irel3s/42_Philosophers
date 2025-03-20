/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 13:47:23 by jmeirele          #+#    #+#             */
/*   Updated: 2025/03/20 11:26:24 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void		*ft_routine();

t_data	*ft_init_data(t_data *data)
{
	int	i;

	i = 0;
	data->forks = malloc(sizeof(t_mutex) * data->n_philos);
	while (i < data->n_philos)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
	data->start_time = ft_get_curr_time();
	return (data);
}

t_philo	*ft_init_philos(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	philo = malloc(sizeof(t_philo) * data->n_philos);
	while (i < data->n_philos)
	{
		philo[i].id = i;
		philo[i].meals_eaten = 0;
		philo[i].l_fork = &data->forks[i];
		philo[i].r_fork = &data->forks[(i + 1) % data->n_philos];
		pthread_create(&philo[i].th, NULL, ft_routine, &philo[i]);
		i++;
	}
	return (philo);
}

static void	*ft_routine()
{
	return NULL;
}