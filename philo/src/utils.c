/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 12:00:52 by jmeirele          #+#    #+#             */
/*   Updated: 2025/03/27 23:05:34 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_is_space(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

int	ft_is_num(char c)
{
	return (c >= 48 && c <= 57);
}

int	ft_min(int num1, int num2)
{
	if (num1 < num2)
		return (num1);
	return (num2);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_print_state(t_philo *philo, t_msg_state msg)
{
	pthread_mutex_lock(&philo->data->print_mutex);
	if (philo->data->simulation_state == OPEN)
	{
		if (msg == TAKEN_FORK)
			printf(CYN TAKEN_FORK_MSG NC, ft_time_passed(philo), philo->id);
		if (msg == EATING)
			printf(YEL EATING_MSG NC, ft_time_passed(philo), philo->id);
		if (msg == SLEEPING)
			printf(MAG SLEEPING_MSG NC, ft_time_passed(philo), philo->id);
		if (msg == THINKING)
			printf(GRN THINKING_MSG NC, ft_time_passed(philo), philo->id);
		if (msg == DIED)
			printf(RED DIED_MSG NC, ft_time_passed(philo), philo->id);
	}
	pthread_mutex_unlock(&philo->data->print_mutex);
	return ;
}
