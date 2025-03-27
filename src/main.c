/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 15:40:25 by jmeirele          #+#    #+#             */
/*   Updated: 2025/03/27 14:19:47 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data		*data;
	t_philo		*philo;

	data = NULL;
	philo = NULL;
	if (argc != 5 && argc != 6)
		return (ft_print_err("Invalid number of arguments\n", 2), FAILURE);
	data = malloc(sizeof(t_data));
	if (ft_parse_and_set(data, argv) != SUCCESS)
		return (ft_free(data), FAILURE);
	data = ft_init_data(data);
	philo = ft_init_philos(data, philo);
	if (data->n_philos == 1)
		ft_single_thread(philo);
	else
		ft_start_simulation(data, philo);
	ft_cleanup(data, philo);
	return (SUCCESS);
}
