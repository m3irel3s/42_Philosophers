/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 16:37:33 by jmeirele          #+#    #+#             */
/*   Updated: 2025/03/27 13:06:02 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_monitor(void *arg)
{
	t_philo	*philos;
	t_data	*data;
	int		i;
	int		full_philos;

	philos = (t_philo *)arg;
	data = philos->data;
	while (data->simulation_state == OPEN)
	{
		i = -1;
		full_philos = 0;
		while (++i < data->n_philos)
		{
			pthread_mutex_lock(&philos[i].meal_mutex);
			// Check if the philosopher has starved
			if ((ft_get_curr_time() - philos[i].last_meal_time > data->time_to_die) && philos[i].last_meal_time != 0)
			{
				ft_print_state(&philos[i], DIED);
				pthread_mutex_unlock(&philos[i].meal_mutex);
				pthread_mutex_lock(&philos[i].data->print_mutex);
				data->simulation_state = DONE;
				pthread_mutex_unlock(&philos[i].data->print_mutex);
				return (NULL);
			}
			// Count philosophers who ate enough
			if (data->must_eat_count > 0 && philos[i].meals_eaten >= data->must_eat_count)
				full_philos++;
			pthread_mutex_unlock(&philos[i].meal_mutex);
		}
		// If all philosophers have eaten enough times, stop the simulation
		if (data->must_eat_count > 0 && full_philos == data->n_philos)
		{
			pthread_mutex_lock(&philos->data->print_mutex);
			data->simulation_state = DONE;
			pthread_mutex_unlock(&philos->data->print_mutex);
			return (NULL);
		}
		usleep(1000);
	}
	return (NULL);
}
