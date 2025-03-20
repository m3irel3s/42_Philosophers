/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 13:37:09 by jmeirele          #+#    #+#             */
/*   Updated: 2025/03/20 12:01:25 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_cleanup(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < data->n_philos)
		pthread_mutex_destroy(&data->forks[i++]);
	ft_free(data->forks);
	ft_free(data);
	ft_free(philo);
}

void	ft_free(void *p)
{
	if (p)
		free(p);
	p = NULL;
}

void	ft_print_err(char *str, int fd)
{
	write(fd, str, ft_strlen(str));
}
