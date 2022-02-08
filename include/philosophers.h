/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvarela <lvarela@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 16:30:55 by lvarela           #+#    #+#             */
/*   Updated: 2022/02/08 12:48:25 by lvarela          ###   ########.fr       */
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

typedef struct 			data
{
	int					*parameters;
	pthread_mutex_t		*fork_mutex;
	pthread_mutex_t		access_mutex;
	pthread_mutex_t		print_mutex;
	int					eaters;
	int					died;
	long long			time;
}						t_data;

typedef	struct			s_philosopher
{
	int					id;
	int					eaten;
	int					die;
	t_data				*data;
	int					left_fork;
	int					right_fork;
	pthread_t			thread;
}						t_philosopher;

int						parsing(t_data *data, int argc, char **argv);
int						initializing(t_data *data, t_philosopher **philo);
int						philosophing(t_philosopher *philosopher);
long int				ft_atoi(const char *str);

#endif