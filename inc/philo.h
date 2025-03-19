/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 11:28:41 by jmeirele          #+#    #+#             */
/*   Updated: 2025/03/19 17:24:05 by jmeirele         ###   ########.fr       */
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

# define BLK "\e[0;30m"	// RGB(0, 0, 0)
# define RED "\e[0;31m"	// RGB(255, 0, 0)
# define GRN "\e[0;32m"	// RGB(0, 255, 0)
# define YEL "\e[0;33m"	// RGB(255, 255, 0)
# define BLU "\e[0;34m"	// RGB(0, 0, 255)
# define MAG "\e[0;35m"	// RGB(255, 0, 255)
# define CYN "\e[0;36m"	// RGB(0, 255, 255)
# define WHT "\e[0;37m"	// RGB(255, 255, 255)

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
typedef struct timeval	t_time;

typedef struct s_philo
{
	int			id;
	int			meals_eaten;
	pthread_t	th;
	t_mutex		*l_fork;
	t_mutex		*r_fork;
}	t_philo;

typedef struct s_data
{
	int			n_philos;
	long		start_time;
	long		time_to_eat;
	long		time_to_sleep;
	long		time_to_die;
	int			must_eat_count;
	t_mutex		*forks;
}	t_data;

//============================================================================//
//                                PROTOTYPES                                  //
//============================================================================//

/* parse.c */
void	ft_validate_and_set(t_data *data, t_philo *philo, char **argv);

/* init.c */
void	ft_init_structs(t_data *data, t_philo *philo);

/* utils.c */
int		ft_is_space(char c);
int		ft_is_num(char c);
int		ft_strlen(char *str);

/* time_utils.c */
long	ft_get_curr_time(void);

/* clean.c */
void	ft_print_err(char *str, int fd);

#endif