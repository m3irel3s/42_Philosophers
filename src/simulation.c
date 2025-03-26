/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 13:49:15 by jmeirele          #+#    #+#             */
/*   Updated: 2025/03/26 17:11:02 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*ft_routine(void *arg);
static void	ft_eat(t_philo *philo);
static void	ft_give_forks(t_philo *philo);

// philo thinks
// philo eats
// philo sleeps
// philo dies

// [TRY FORKS] => [EAT] => [RELEASE FORKS] => [SLEEP] => [THINK] => Repeat
// create a thread to watch the other philos => monitor thread
// will check for time since last_meal > time_to_die 
// if all philos ate the req meals

int	ft_start_simulation(t_data *data, t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < data->n_philos)
	{
		if (pthread_create(&philo[i].th, NULL, ft_routine, &philo[i]) != SUCCESS)
			return (FAILURE);
	}
	pthread_create(&data->monitor, NULL, ft_monitor, philo);
	return (SUCCESS);
}
static void	*ft_routine(void *arg)
{
	t_philo	*philo;
	t_data	*data;
	long	time_to_think;

	philo = (t_philo *)arg;
	data = philo->data;
	while (1)
	{
		pthread_mutex_lock(&data->print_mutex);
		if (data->simulation_state != OPEN)
		{
			pthread_mutex_unlock(&data->print_mutex);
			break ;
		}
		pthread_mutex_unlock(&data->print_mutex);
		ft_give_forks(philo);
		ft_eat(philo);
		usleep(philo->data->time_to_eat * 1000);
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
		ft_print_state(philo, SLEEPING);
		usleep(philo->data->time_to_sleep * 1000);
		time_to_think = ft_max(0, (data->time_to_die - (data->time_to_eat + data->time_to_sleep)) / 2);
		ft_print_state(philo, THINKING);
		usleep(time_to_think * 1000);
	}
	return (NULL);
}

static void	ft_give_forks(t_philo *philo)
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
}

static void	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->meal_mutex);
	philo->last_meal_time = ft_get_curr_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->meal_mutex);
	ft_print_state(philo, EATING);
}
