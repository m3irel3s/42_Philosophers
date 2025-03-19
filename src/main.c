/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 15:40:25 by jmeirele          #+#    #+#             */
/*   Updated: 2025/03/19 15:45:32 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char **argv)
{
	t_data	data;
	t_philo	philo;

	if (argc != 5 && argc != 6)
		return (ft_print_err("Invalid number of arguments\n", 2), FAILURE);
	ft_validate_and_set(&data, &philo, argv);
	ft_init_srtucts(&data, &philo);
}