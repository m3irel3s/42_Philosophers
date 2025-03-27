/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 13:37:09 by jmeirele          #+#    #+#             */
/*   Updated: 2025/03/27 11:30:17 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_cleanup(t_data *data, t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < data->n_philos)
		pthread_join(philo[i].th, NULL);
	pthread_join(data->monitor, NULL);
	i = -1;
	while (++i < data->n_philos)
		pthread_mutex_destroy(&data->forks[i]);
	pthread_mutex_destroy(&data->print_mutex);
	i = -1;
	while (++i < data->n_philos)
		pthread_mutex_destroy(&philo[i].meal_mutex);
	ft_free(data->forks);
	ft_free(philo);
	ft_free(data);
}

void	ft_free(void *p)
{
	if (p)
		free(p);
}

void	ft_print_err(char *str, int fd)
{
	write(fd, str, ft_strlen(str));
}
