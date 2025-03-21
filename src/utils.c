/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 12:00:52 by jmeirele          #+#    #+#             */
/*   Updated: 2025/03/20 14:57:26 by jmeirele         ###   ########.fr       */
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
	if (msg == TAKEN_FORK)
		printf(TAKEN_FORK_MSG, ft_time_since_start(philo), philo->id);
	if (msg == EATING)
		printf(EATING_MSG, ft_time_since_start(philo), philo->id);
	if (msg == SLEEPING)
		printf(SLEEPING_MSG, ft_time_since_start(philo), philo->id);
	if (msg == THINKING)
		printf(THINKING_MSG, ft_time_since_start(philo), philo->id);
	if (msg == DIED)
		printf(DIED_MSG, ft_time_since_start(philo), philo->id);
	return ;
}

