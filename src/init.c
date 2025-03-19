/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 13:47:23 by jmeirele          #+#    #+#             */
/*   Updated: 2025/03/19 15:47:37 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_init_philos(t_data *data, t_philo *philo);

void	ft_init_srtucts(t_data *data, t_philo *philo)
{
	(void)data;
	ft_init_philos(data, philo);
}

static void	ft_init_philos(t_data *data, t_philo *philo)
{
	(void)philo;
	printf("n_philos => %d\n", data->n_philos);
}