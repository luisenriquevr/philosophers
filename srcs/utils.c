/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvarela <lvarela@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 17:07:20 by lvarela           #+#    #+#             */
/*   Updated: 2022/02/08 17:52:07 by lvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	print(char *msg, int philosopher, t_data *data)
{
	pthread_mutex_lock(&data->print_mutex);
	if (!data->died)
		printf("%lli ms %i %s\n", timing() - data->timestamp, philosopher, msg);
	pthread_mutex_unlock(&data->print_mutex);
}

long long	timing(void)
{
	struct timeval	time;
	
	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}