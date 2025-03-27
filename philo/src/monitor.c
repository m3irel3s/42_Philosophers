/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 16:37:33 by jmeirele          #+#    #+#             */
/*   Updated: 2025/03/27 15:56:51 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_check_starve(t_philo *philo, t_data *data, int i);
static int	ft_check_philos_full(t_philo *philo, t_data *data, int philos_full);

void	*ft_monitor(void *arg)
{
	t_philo	*philo;
	t_data	*data;
	int		i;
	int		philos_full;

	philo = (t_philo *)arg;
	data = philo->data;
	while (data->simulation_state == OPEN)
	{
		i = -1;
		philos_full = 0;
		while (++i < data->n_philos)
		{
			pthread_mutex_lock(&philo[i].meal_mutex);
			if (ft_check_starve(philo, data, i) == TRUE)
				return (NULL);
			if (philo[i].meals_eaten >= data->must_eat_count)
				philos_full++;
			pthread_mutex_unlock(&philo[i].meal_mutex);
		}
		if (ft_check_philos_full(philo, data, philos_full) == TRUE)
			return (NULL);
		usleep(1000);
	}
	return (NULL);
}

static int	ft_check_starve(t_philo *philo, t_data *data, int i)
{
	if ((ft_get_curr_time() - philo[i].last_meal_time > data->time_to_die)
		&& philo[i].last_meal_time != 0)
	{
		ft_print_state(&philo[i], DIED);
		pthread_mutex_unlock(&philo[i].meal_mutex);
		pthread_mutex_lock(&philo[i].data->print_mutex);
		data->simulation_state = DONE;
		pthread_mutex_unlock(&philo[i].data->print_mutex);
		return (TRUE);
	}
	return (FALSE);
}

static int	ft_check_philos_full(t_philo *philo, t_data *data, int philos_full)
{
	if (data->must_eat_count > 0 && philos_full == data->n_philos)
	{
		pthread_mutex_lock(&philo->data->print_mutex);
		data->simulation_state = DONE;
		pthread_mutex_unlock(&philo->data->print_mutex);
		return (TRUE);
	}
	return (FALSE);
}
