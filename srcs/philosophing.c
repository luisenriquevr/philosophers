/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvarela <lvarela@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:34:41 by lvarela           #+#    #+#             */
/*   Updated: 2022/02/09 10:20:21 by lvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	sumatorie(t_data *data)
{
	pthread_mutex_lock(&data->access_mutex);
	data->died++;
	pthread_mutex_unlock(&data->access_mutex);
}

void	sumatorie0(t_data *data)
{
	pthread_mutex_lock(&data->access_mutex);
	data->died = data->died + 10;
	pthread_mutex_unlock(&data->access_mutex);
}


void	*routine(void *philo)
{
	t_philosopher	*philosopher;
	t_data			*data;
	
	philosopher = (t_philosopher *)philo;
	data = philosopher->data;
	if (philosopher->id % 2 == 0)
	{
		usleep(1000);
		sumatorie(data);
		print(EATING, philosopher->id, data);
	}
	else
		sumatorie0(data);
		print(THINKING, philosopher->id, data);
	return (NULL);
}

int	philosophing(t_philosopher *philosopher)
{
	int	i;

	i = -1;
	while (++i < philosopher->data->parameters[NUM_OF_PHILOS])
	{
		philosopher->data->timestamp = timing();
		if (pthread_create(&(philosopher[i].thread), NULL,
			&routine, &philosopher[i]))
			return (1);
		if (pthread_join(philosopher[i].thread, NULL))
			return (1);
		philosopher[i].t_last_meal = timing();
	}
	printf("Data->died = %d", philosopher->data->died);
	return (0);
}