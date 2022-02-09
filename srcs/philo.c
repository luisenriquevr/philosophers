/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvarela <lvarela@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 16:31:07 by lvarela           #+#    #+#             */
/*   Updated: 2022/02/09 21:29:27 by lvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	joining_destroying(t_data *data, t_philosopher *philosopher)
{
	int	i;

	i = -1;
	while (++i < data->parameters[NUM_OF_PHILOS]
			&& data->parameters[NUM_OF_PHILOS] > 1)
	{
		if (pthread_join(philosopher[i].thread, NULL))
			return (1);
		pthread_mutex_destroy(&data->fork_mutex[i]);
	}
	pthread_mutex_destroy(&data->access_mutex);
	pthread_mutex_destroy(&data->print_mutex);
	free(data->fork_mutex);
	free(philosopher);
	free(data->parameters);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data			data;
	t_philosopher	*philosophers;

	if (argc != 5 && argc != 6)
		return (throw_error("Error: Incorrect number of arguments"));
	if (parsing(&data, argc, argv))
		return (throw_error("Error: Arguments are not valid"));
	if (initializing(&data, &philosophers))
		return (throw_error("Error: Threads initialization not possible"));
	if (philosophing(philosophers))
		return (throw_error("Error: An error has ocurred"));
	if (joining_destroying(&data, philosophers))
		return (throw_error("Error: An error with join threads ocurred"));
	return (EXIT_SUCCESS);
}
