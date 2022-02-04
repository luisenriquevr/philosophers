/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvarela <lvarela@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 13:46:31 by lvarela           #+#    #+#             */
/*   Updated: 2022/02/04 13:24:02 by lvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	*routine()
{
	printf("One more philosopher\n");
	return NULL;
}

int	mutex_init(t_data *data)
{
	t_philosopher	philo[data->parameters[NUM_OF_PHILOS]];
	int				i;

	i = -1;
	
	while (++i < data->parameters[NUM_OF_PHILOS])
	{
		if (pthread_create(&philo[i].thread, NULL, &routine, NULL) != 0)
			return (throw_error("Error whith thread\n", 1));
		if (pthread_join(philo[i].thread, NULL))
			return (throw_error("Error with join\n", 1));
	}
	data->philosopher = philo;
	return (0);


	
	/*pthread_t	philo_tmp[data->parameters[0] - 1];
	int	i;
	
	i = -1;
	while (++i < data->parameters[0])
	{
		//	philo_tmp[i] = malloc(sizeof(pthread_t)); // Comprobar si es necesario guardar en memoria dinamica
		if (pthread_create(&philo_tmp[i], NULL, &routine, NULL) != 0)
			return (throw_error("Error whith thread\n", 1));
		if (pthread_join(philo_tmp[i], NULL) != 0)
			return (throw_error("Error with join\n", 1));
	}
	data->philo_th = philo_tmp;
	return (0);*/
}

int	all_init(t_data *data)
{
	if (mutex_init(data))
		return (1);
	return (0);
}