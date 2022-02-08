/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvarela <lvarela@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 16:31:07 by lvarela           #+#    #+#             */
/*   Updated: 2022/02/08 12:47:53 by lvarela          ###   ########.fr       */
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
		return (throw_error("Error: Number of arguments is incorrected\n"));
	if (parsing(&data, argc, argv))
		throw_error("Error: Error with arguments\n");
	else
	{
		if (initializing(&data, &philosophers))
			return (throw_error("Error: Threads initialization not possible\n"));
		if (philosophing(philosophers))
			return (throw_error("Error: An error has ocurred\n"));
	}
	removing(&data);
	return (EXIT_SUCCESS);
}
