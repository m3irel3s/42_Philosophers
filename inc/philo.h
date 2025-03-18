/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 11:28:41 by jmeirele          #+#    #+#             */
/*   Updated: 2025/03/18 17:34:38 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

//============================================================================//
//                                INCLUDES                                    //
//============================================================================//

# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <limits.h>

//============================================================================//
//                                 MACROS                                     //
//============================================================================//

//============================================================================//
//                                  ENUMS                                     //
//============================================================================//

typedef enum e_exit
{
	SUCCESS,
	FAILURE
}	t_exit;

typedef enum e_msg_state
{
	TAKEN_FORK,
	EATING,
	SLEEPING,
	THINKING,
	DIED
}	t_msg_state;

//============================================================================//
//                                STRUCTURES                                  //
//============================================================================//

typedef pthread_mutex_t	t_mutex;
typedef struct s_philo	t_philo;
typedef struct s_data	t_data;

typedef struct s_data
{
	int			n_philos;
	t_philo		*philos;
	long		start_time;
	long		time_to_eat;
	long		time_to_sleep;
	long		time_to_die;
	int			must_eat_count;
	t_mutex		*forks;
}	t_data;

typedef struct s_philo
{
	int			id;
	pthread_t	th;
	t_mutex		*l_fork;
	t_mutex		*r_fork;
	int			meals_eaten;
	t_data		*data;
}	t_philo;

#endif