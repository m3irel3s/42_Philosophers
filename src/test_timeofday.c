/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_timeofday.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:01:52 by jmeirele          #+#    #+#             */
/*   Updated: 2025/03/18 16:14:11 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <sys/time.h>
# include <stdio.h>

int main(void)
{
	struct timeval	time;
	gettimeofday(&time, NULL);

	printf("%ld\n", time.tv_sec);
	return 0;
}