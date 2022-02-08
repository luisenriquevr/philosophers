/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvarela <lvarela@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 16:31:07 by lvarela           #+#    #+#             */
/*   Updated: 2022/02/08 10:23:46 by lvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers.h"

void	removing(t_data *data)
{
	free(data->parameters);
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_philosopher	*philosophers = NULL;
	
	if (argc != 5 && argc != 6)
		return (throw_error("Error: Number of arguments is incorrected\n", 1));
	if (parsing(&data, argc, argv))
		throw_error("Error: Error with arguments\n", 1);
	else
	{
		if (initializing(&data, &philosophers))
			return (throw_error("Error: Threads initialization not possible\n", 1));
		//if (playing(&data, &philosophers))
		//	return (throw_error("Error: An error has ocurred\n", 1));
	}
	printf("data->died = %d\n", data.died);
	printf("philosofer[1]->data.died = %d\n", philosophers[1].data->died);
	removing(&data);
	return (EXIT_SUCCESS);
}
