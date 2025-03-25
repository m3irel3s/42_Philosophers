/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 13:49:15 by jmeirele          #+#    #+#             */
/*   Updated: 2025/03/25 11:57:15 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*ft_routine(void *arg);
static int	ft_check_starve(t_philo *philo);
static void	ft_eat(t_philo *philo);

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
	t_data	*data;

	philo = (t_philo *)arg;
	data = philo->data;
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
		ft_eat(philo);
		usleep(philo->data->time_to_eat * 1000);
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
		ft_print_state(philo,SLEEPING);
		ft_check_starve(philo);
		usleep(philo->data->time_to_sleep * 1000);

	}
	return NULL;
}


static void	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->meal_mutex);
	philo->last_meal_time = ft_get_curr_time();
	philo->meals_eaten++;
	ft_print_state(philo, EATING);
	if (philo->meals_eaten == philo->data->must_eat_count)
		exit(1);
	pthread_mutex_unlock(&philo->meal_mutex);
}

static int		ft_check_starve(t_philo *philo)
{
	pthread_mutex_lock(&philo->meal_mutex);
	if (ft_get_curr_time() - philo->last_meal_time > philo->data->time_to_die)
	{
		ft_print_state(philo, DIED);
		return (FAILURE);
	}
	pthread_mutex_unlock(&philo->meal_mutex);
	return (SUCCESS);
}
