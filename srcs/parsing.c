/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvarela <lvarela@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 13:56:42 by lvarela           #+#    #+#             */
/*   Updated: 2021/12/30 19:23:16 by lvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	throw_error(char *error, int ret)
{
	ft_putstr_fd(error, 2); // saca el error por el stderror
	return(ret);
}

int	parsing(t_data *data, int argc, char **argv)
{
	if (argc != 5)
		return (0);
	data->nphilo = ft_atoi(argv[1]);
	//printf("%d\n", data->nphilo);
	if (data->nphilo <= 1)
		throw_error("Philosophers number must be greater than 1.\n", 1);
	data->tdie = ft_atoi(argv[2]);
	if (data->tdie <= 0)
		throw_error("Time to die must be greater than 0.\n", 1);
	data->teat = ft_atoi(argv[3]);
	if (data->teat <= 0)
		throw_error("Time to eat must be greater than 0.\n", 1);
	data->tsleep = ft_atoi(argv[4]);
	if (data->tsleep <= 1)
		throw_error("Time to sleep must be greater than 1", 1);
	return (0);
}