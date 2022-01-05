/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvarela <lvarela@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 16:31:07 by lvarela           #+#    #+#             */
/*   Updated: 2022/01/02 13:39:17 by lvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers.h"

int	main(int argc, char **argv)
{
	t_data	data;
	if (argc == 5 || argc == 6)
	{
		if (parsing(&data, argc, argv))
			return (0);
		all_init(&data);
	}
	return (0);
}