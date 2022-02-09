/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvarela <lvarela@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 16:30:55 by lvarela           #+#    #+#             */
/*   Updated: 2022/02/09 21:25:59 by lvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>

# define NUM_OF_PHILOS 0
# define TIME_TO_DIE 1
# define TIME_TO_EAT 2
# define TIME_TO_SLEEP 3
# define NUM_OF_TIMES_TO_EAT 4
# define EATING "is eating"
# define SLEEPING "is sleeping"
# define THINKING "is thinking"
# define DIE "died"
# define LEFT_FORK "has taken left fork"
# define RIGHT_FORK "has taken right fork"
# define FORK "has taken a fork"

typedef struct data
{
	int					*parameters;
	pthread_mutex_t		*fork_mutex;
	pthread_mutex_t		access_mutex;
	pthread_mutex_t		print_mutex;
	int					all_eaten;
	int					died;
	long long			timestamp;
}						t_data;

typedef struct s_philosopher
{
	int					id;
	int					eaten;
	int					die;
	t_data				*data;
	int					left_fork;
	int					right_fork;
	long long			t_last_meal;
	pthread_t			thread;
}						t_philosopher;

int						parsing(t_data *data, int argc, char **argv);
int						initializing(t_data *data, t_philosopher **philo);
int						throw_error(char *error);
int						philosophing(t_philosopher *philosopher);
void					sleep_time(long long time, t_data *data);
long long				timestamp(void);
void					print(char *msg, int philosopher, t_data *data);
int						ft_atoi(const char *str);

#endif