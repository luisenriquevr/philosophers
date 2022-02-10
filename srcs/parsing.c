/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvarela <lvarela@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 13:56:42 by lvarela           #+#    #+#             */
/*   Updated: 2022/02/10 13:10:36 by lvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	throw_error(char *error)
{
	printf("%s\n", error);
	return (1);
}

int	parsing(t_data *data, int argc, char **argv)
{
	int	i;

	i = 0;
	data->parameters = (int *)malloc(sizeof(int) * (argc));
	while (argv[++i])
	{
		data->parameters[i - 1] = ft_atoi(argv[i]);
		if (data->parameters[i - 1] <= 0)
			return (1);
	}
	if (argc == 5)
	{
		printf("hola");
		data->parameters[NUM_OF_TIMES_TO_EAT] = -1;
	}
	return (0);
}
