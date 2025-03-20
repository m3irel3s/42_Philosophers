/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 15:40:25 by jmeirele          #+#    #+#             */
/*   Updated: 2025/03/20 12:07:50 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char **argv)
{
	t_data	*data;
	t_philo	*philo;

	data = NULL;
	philo = NULL;
	if (argc != 5 && argc != 6)
		return (ft_print_err("Invalid number of arguments\n", 2), FAILURE);
	data = malloc(sizeof(t_data));
	ft_parse_and_set(data, argv);
	data = ft_init_data(data);
	philo = ft_init_philos(data,philo);
	// ft_start_simulation();
	for (int i = 0; i < data->n_philos; i++)
		pthread_join(philo[i].th, NULL);
	ft_cleanup(data, philo);
}
