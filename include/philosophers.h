/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvarela <lvarela@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 16:30:55 by lvarela           #+#    #+#             */
/*   Updated: 2022/01/02 13:47:35 by lvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

typedef struct data
{
	int	nphilo;
	int	tdie;
	int	teat;
	int	tsleep;
	int	neat;
}	t_data;


int			parsing(t_data *data, int argc, char **argv);
void		all_init(t_data *data);

long int	ft_atoi(const char *str);
void		ft_putstr_fd(char *s, int fd);
