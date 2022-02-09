/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvarela <lvarela@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 13:56:42 by lvarela           #+#    #+#             */
/*   Updated: 2022/02/09 15:25:20 by lvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	throw_error(char *error)
{
	perror(error);
	return(1);
}

int	comprobing(t_data *data, int argc)
{
	if (data->parameters[NUM_OF_PHILOS] <= 1)
		return (throw_error("Philosophers must be a number greater than 1\n"));
	if (data->parameters[TIME_TO_DIE] <= 0)
		return (throw_error("Time to die must be a number greater than 0\n"));
	if (data->parameters[TIME_TO_EAT] <= 0)
		return (throw_error("Time to eat must be a number greater than 0\n"));
	if (data->parameters[TIME_TO_SLEEP] <= 1)
		return (throw_error("Time to sleep must be a number greater than 1\n"));
	if (argc == 6)
		if (data->parameters[NUM_OF_TIMES_TO_EAT] <= 0)
			return (throw_error("Times to die must be a number greater than 0\n"));
	return (0);
}

int	parsing(t_data *data, int argc, char **argv)
{
	int	i;
	
	i = 0;
	data->parameters = (int *)malloc(sizeof(int) * (argc - 1));
	while (argv[++i])
		data->parameters[i - 1] = ft_atoi(argv[i]);
	return (comprobing(data, argc));
}
