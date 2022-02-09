/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvarela <lvarela@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 17:07:20 by lvarela           #+#    #+#             */
/*   Updated: 2022/02/09 14:52:10 by lvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	ft_isspace(int c)
{
	c = (unsigned char)c;
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r'
		|| c == ' ')
		return (1);
	return (0);
}

long int	ft_atoi(const char *str)
{
	long	num;
	int		neg;

	num = 0;
	neg = 1;
	while (ft_isspace(*str))
		str++;
	str--;
	if (*str == '-')
		neg = -1;
	str++;
	if (*str == '-' || *str == '+')
		str++;
	while (*str != '\0' && *str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str - 48);
		str++;
	}
	return ((int)(num * neg));
}

void	print(char *msg, int philosopher, t_data *data)
{
	pthread_mutex_lock(&data->print_mutex);
	if (!data->died)
		printf("%lli ms %i %s\n", timing() - data->timestamp, philosopher, msg);
	pthread_mutex_unlock(&data->print_mutex);
}

long long	timing(void)
{
	struct timeval	time;
	
	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	sleep_time(long long time, t_data *data)
{
	long long	i;

	i = timing();
	while (!data->died)
	{
		if ((i - timing()) >= time)
			break ;
		usleep(50);
	}
}
