/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 13:59:22 by jmeirele          #+#    #+#             */
/*   Updated: 2025/03/27 14:19:55 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*ft_single_thread_routine(void *arg);

int	ft_single_thread(t_philo *philo)
{
	pthread_create(&philo->th, NULL, ft_single_thread_routine, philo);
	pthread_join(philo->th, NULL);
	return (SUCCESS);
}

static void	*ft_single_thread_routine(void *arg)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)arg;
	data = philo->data;
	ft_print_state(philo, TAKEN_FORK);
	usleep(data->time_to_die * 1000);
	ft_print_state(philo, DIED);
	return (NULL);
}
