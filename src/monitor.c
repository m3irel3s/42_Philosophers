/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 16:37:33 by jmeirele          #+#    #+#             */
/*   Updated: 2025/03/25 17:14:58 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


void	*ft_monitor(void *arg)
{
	t_philo	*philo;
	t_data	*data;
	int		i;
	int		full_philos;

	philo = (t_philo *)arg;
	data = philo->data;
	while (data->simulation_state)
	{
		i = -1;
		full_philos = 0;
		while (++i < data->n_philos)
		{
			pthread_mutex_lock(&philo[i].meal_mutex);
			if (ft_get_curr_time() - philo[i].last_meal_time > data->time_to_die)
			{
				ft_print_state(philo, DIED);
				data->simulation_state = 0;
				pthread_mutex_unlock(&philo[i].meal_mutex);
				return (NULL);
			}
			if (data->must_eat_count > 0 && philo[i].meals_eaten >= data->must_eat_count)
				full_philos++;

			pthread_mutex_unlock(&philo[i].meal_mutex);
		}
		if (data->must_eat_count > 0 && full_philos == data->n_philos)
		{
			data->simulation_state = 0;
			return (NULL);
		}
		usleep(1000);
	}
	return (NULL);
}

