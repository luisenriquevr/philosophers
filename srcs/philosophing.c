/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvarela <lvarela@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:34:41 by lvarela           #+#    #+#             */
/*   Updated: 2022/02/09 21:36:07 by lvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	all_eaten_check(t_philosopher *philosopher, t_data *data)
{
	int	i;

	i = 0;
	while (data->parameters[NUM_OF_TIMES_TO_EAT] > 0
		&& i < data->parameters[NUM_OF_PHILOS]
		&& philosopher[i].eaten >= data->parameters[NUM_OF_TIMES_TO_EAT])
		i++;
	if (i == data->parameters[NUM_OF_PHILOS])
		data->all_eaten = 1;
}

void	eat_time(t_philosopher *philosopher)
{
	t_data	*data;

	data = philosopher->data;
	pthread_mutex_lock(&data->fork_mutex[philosopher->left_fork]);
	print(LEFT_FORK, philosopher->id, data);
	pthread_mutex_lock(&data->fork_mutex[philosopher->right_fork]);
	print(RIGHT_FORK, philosopher->id, data);
	pthread_mutex_lock(&data->access_mutex);
	print(EATING, philosopher->id, data);
	philosopher->t_last_meal = timestamp();
	pthread_mutex_unlock(&data->access_mutex);
	sleep_time(data->parameters[TIME_TO_EAT], data);
	philosopher->eaten++;
	pthread_mutex_unlock(&data->fork_mutex[philosopher->left_fork]);
	pthread_mutex_unlock(&data->fork_mutex[philosopher->right_fork]);
}

void	dead_check(t_philosopher *philosopher)
{
	t_data		*data;
	int			i;

	data = philosopher->data;
	while (!data->all_eaten)
	{
		i = -1;
		while (++i < data->parameters[NUM_OF_PHILOS] && !data->died)
		{
			pthread_mutex_lock(&data->access_mutex);
			if ((timestamp() - philosopher[i].t_last_meal)
				>= data->parameters[TIME_TO_DIE])
			{
				print(DIE, philosopher[i].id, data);
				data->died = 1;
			}
			pthread_mutex_unlock(&data->access_mutex);
			usleep(100);
		}
		if (data->died)
			break ;
		all_eaten_check(philosopher, data);
	}
}

void	*routine(void *philo)
{
	t_philosopher	*philosopher;
	t_data			*data;
	
	philosopher = (t_philosopher *)philo;
	data = philosopher->data;
	if (philosopher->id % 2 == 0)
		usleep(1000);
	while (!data->died)
	{
		eat_time(philosopher);
		if (data->all_eaten)
			break ;
		print(SLEEPING, philosopher->id, data);
		sleep_time(data->parameters[TIME_TO_SLEEP], data);
		print(THINKING, philosopher->id, data);
	}
	return (NULL);
}

int	philosophing(t_philosopher *philosopher)
{
	int	i;

	i = -1;
	philosopher->data->timestamp = timestamp();
	while (++i < philosopher->data->parameters[NUM_OF_PHILOS])
	{
		if (pthread_create(&(philosopher[i].thread), NULL,
				&routine, &(philosopher[i])))
			return (1);
		philosopher[i].t_last_meal = timestamp();
	}
	dead_check(philosopher);
	return (0);
}