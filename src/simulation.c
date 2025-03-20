/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 13:49:15 by jmeirele          #+#    #+#             */
/*   Updated: 2025/03/20 17:17:44 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*ft_routine(void *arg);

int	ft_start_simulation(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < data->n_philos)
	{
		if (pthread_create(&philo[i].th, NULL, ft_routine, &philo[i]) != SUCCESS)
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}

// philo thinks
// philo eats
// philo sleeps
// philo dies

// [TRY FORKS] => [EAT] => [RELEASE FORKS] => [SLEEP] => [THINK] => Repeat
// create a thread to watch the other philos => monitor thread
// will check for time since last_meal > time_to_die 
// if all philos ate the req meals



static void	*ft_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (philo->data->simulation_active)
	{
		if (philo->id % 2 == 0)
		{
			pthread_mutex_lock(philo->l_fork);
			ft_print_state(philo, TAKEN_FORK);
			pthread_mutex_lock(philo->r_fork);
			ft_print_state(philo, TAKEN_FORK);
		}
		else
		{
			pthread_mutex_lock(philo->r_fork);
			ft_print_state(philo, TAKEN_FORK);
			pthread_mutex_lock(philo->l_fork);
			ft_print_state(philo, TAKEN_FORK);
		}
		ft_print_state(philo, EATING);
		usleep(philo->data->time_to_eat * 1000);
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
		ft_print_state(philo,SLEEPING);
		usleep(philo->data->time_to_sleep * 1000);
	}
	return NULL;
}


