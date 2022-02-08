/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvarela <lvarela@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:34:41 by lvarela           #+#    #+#             */
/*   Updated: 2022/02/08 12:39:28 by lvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	*routine(void *i)
{
	t_philosopher *ph;
	int x;
	
	ph = (t_philosopher *)i;
	x = ph->id;
	printf("El philosopher %d ha despertado\n", x);
	return NULL;
}

int	philosophing(t_philosopher *philosopher)
{
	int	i;

	i = -1;
	while (++i < philosopher->data->parameters[NUM_OF_PHILOS])
	{
		if (pthread_create(&(philosopher[i].thread), NULL,
			&routine, &philosopher[i]))
			return (1);
		pthread_join(philosopher[i].thread, NULL);
	}
	return (0);
}