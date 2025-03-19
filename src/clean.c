/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 13:37:09 by jmeirele          #+#    #+#             */
/*   Updated: 2025/03/19 14:49:45 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
