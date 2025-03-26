/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 17:13:49 by jmeirele          #+#    #+#             */
/*   Updated: 2025/03/26 15:35:11 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_get_curr_time(void)
{
	t_time	time;

	gettimeofday(&time, NULL);

	return ((time.tv_sec * 1000) + (time.tv_usec * 0.001));
}

long	ft_time_since_start(t_philo *philo)
{
	return (ft_get_curr_time() - philo->data->start_time);
}
