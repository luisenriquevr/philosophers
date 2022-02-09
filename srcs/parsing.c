/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvarela <lvarela@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 13:56:42 by lvarela           #+#    #+#             */
/*   Updated: 2022/02/09 20:12:39 by lvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	throw_error(char *error)
{
	printf("%s\n", error);
	return (1);
}

int	comprobing(t_data *data, int argc)
{
	int	i;

	i = -1;
	while (data->parameters[++i] && i < 6)
		 if (data->parameters[i] <= 0)
		 	return (1);
	if (argc == 6)
		if (data->parameters[5])
			return (1);
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
