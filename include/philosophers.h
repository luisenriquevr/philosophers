/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvarela <lvarela@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 16:30:55 by lvarela           #+#    #+#             */
/*   Updated: 2022/02/04 18:00:23 by lvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>

# define NUM_OF_PHILOS 0
# define TIME_TO_DIE 1
# define TIME_TO_EAT 2
# define TIME_TO_SLEEP 3
# define NUM_OF_TIMES_TO_EAT 4

typedef	struct			s_philosopher
{
	int					id;
	int					x_ate;
	pthread_t			thread;
}						t_philosopher;

typedef struct data
{
	int					*parameters;
	t_philosopher		*philosopher;
}	t_data;


int						parsing(t_data *data, int argc, char **argv);
int						throw_error(char *error, int ret);
int						all_init(t_data *data);

long int				ft_atoi(const char *str);
void					ft_putstr_fd(char *s, int fd);

#endif