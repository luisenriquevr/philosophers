/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvarela <lvarela@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 16:31:07 by lvarela           #+#    #+#             */
/*   Updated: 2022/02/04 11:10:46 by lvarela          ###   ########.fr       */
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
	
	if (argc != 5 && argc != 6)
		return (throw_error("Number of arguments is incorrected\n", 1));
	if (parsing(&data, argc, argv))
		removing(&data);
	if (all_init(&data))
		return (throw_error("Error when intializing mutex\n", 1));
	return (0);
}
