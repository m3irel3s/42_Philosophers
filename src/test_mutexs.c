/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_mutexs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 11:28:19 by jmeirele          #+#    #+#             */
/*   Updated: 2025/03/18 17:10:57 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <limits.h>

void	*increment();

int	mails = 0;
pthread_mutex_t mutex;

int main(void)
{
	pthread_t thread1;
	pthread_t thread2;
	pthread_t thread3;
	pthread_t thread4;
	pthread_mutex_init(&mutex, NULL);
	pthread_create(&thread1, NULL, increment, NULL);
	pthread_create(&thread2, NULL, increment, NULL);
	pthread_create(&thread3, NULL, increment, NULL);
	pthread_create(&thread4, NULL, increment, NULL);
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	pthread_join(thread3, NULL);
	pthread_join(thread4, NULL);
	pthread_mutex_destroy(&mutex);
	printf("number of mails => %d\n", mails);
}
void	*increment()
{
	long long i = 0;

	while (i < 10000000)
	{
		i++;
	}
	pthread_mutex_lock(&mutex);
	mails += i;
	pthread_mutex_unlock(&mutex);
	return (NULL);
}
