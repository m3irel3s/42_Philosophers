/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 13:49:15 by jmeirele          #+#    #+#             */
/*   Updated: 2025/03/25 17:15:47 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*ft_routine(void *arg);
static int	ft_check_starve(t_philo *philo);
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

	i = 0;

	while (i < data->n_philos)
	{
		if (pthread_create(&philo[i].th, NULL, ft_routine, &philo[i]) != SUCCESS)
			return (FAILURE);
		i++;
	}
	pthread_create(&data->monitor, NULL, ft_monitor, &philo);
	return (SUCCESS);
}
static void	*ft_routine(void *arg)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)arg;
	data = philo->data;
	while (data->simulation_state)
	{
		if (!data->simulation_state)
			break;
		ft_give_forks(philo);
		if (!data->simulation_state)
			break;
		ft_eat(philo);
		usleep(data->time_to_eat * 1000);
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
		if (!data->simulation_state)
			break;
		ft_print_state(philo, SLEEPING);
		usleep(data->time_to_sleep * 1000);
		if (!data->simulation_state)
			break;
	}
	return NULL;
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
	ft_print_state(philo, EATING);
	pthread_mutex_unlock(&philo->meal_mutex);
}

static int		ft_check_starve(t_philo *philo)
{
	pthread_mutex_lock(&philo->meal_mutex);
	if (ft_get_curr_time() - philo->last_meal_time > philo->data->time_to_die)
		return (FAILURE);
	pthread_mutex_unlock(&philo->meal_mutex);
	return (SUCCESS);
}