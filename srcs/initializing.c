/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvarela <lvarela@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 13:46:31 by lvarela           #+#    #+#             */
/*   Updated: 2022/02/08 10:24:36 by lvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	data_fill(t_data *data)
{
	data->fork_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
		* data->parameters[NUM_OF_PHILOS]);
	data->eaters = 0;
	data->died = 0;
	if (pthread_mutex_init(&data->access_mutex, NULL)
		|| pthread_mutex_init(&data->print_mutex, NULL))
		return (1);
	return (0);
}

int	philosophers_fill(t_philosopher *philo, t_data *data, int i)
{
	philo->id = i + 1;
	philo->eaten = 0;
	philo->die = 0;
	philo->data = data;
	if (pthread_mutex_init(&data->fork_mutex[i], NULL))
		return (1);
	philo->left_fork = i;
	if (i == data->parameters[NUM_OF_PHILOS] - 1) // Esta condicion la ponemos por si es el ultimo philo
		philo->right_fork = 0;
	else
		philo->left_fork = i + 1;
	return (0);
}

int	initializing(t_data *data, t_philosopher **philosopher)
{
	t_philosopher	*philo;
	int				i;

	i = -1;
	philo = *philosopher;
	if (data_fill(data))
		return (1);
	philo = (t_philosopher *)malloc(sizeof(t_philosopher) * data->parameters[NUM_OF_PHILOS]);
	while (++i < data->parameters[NUM_OF_PHILOS])
		philosophers_fill(&philo[i], data, i);
	*philosopher = philo;
	return (0);
}