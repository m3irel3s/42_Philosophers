/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 13:47:23 by jmeirele          #+#    #+#             */
/*   Updated: 2025/03/27 11:30:20 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_data	*ft_init_data(t_data *data)
{
	int	i;

	i = -1;
	data->forks = malloc(sizeof(t_mutex) * data->n_philos);
	while (++i < data->n_philos)
		pthread_mutex_init(&data->forks[i], NULL);
	data->start_time = ft_get_curr_time();
	data->simulation_state = OPEN;
	pthread_mutex_init(&data->print_mutex, NULL);
	return (data);
}

t_philo	*ft_init_philos(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	philo = malloc(sizeof(t_philo) * data->n_philos);
	while (i < data->n_philos)
	{
		philo[i].id = i + 1;
		philo[i].meals_eaten = 0;
		philo[i].last_meal_time = 0;
		philo[i].l_fork = &data->forks[i];
		philo[i].r_fork = &data->forks[(i + 1) % data->n_philos];
		philo[i].data = data;
		pthread_mutex_init(&philo[i].meal_mutex, NULL);
		i++;
	}
	return (philo);
}
