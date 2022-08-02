/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:55:59 by anrechai          #+#    #+#             */
/*   Updated: 2022/08/01 19:34:54 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}

int ft_atoi(const char *nptr)
{
	int i;
	int sign;
	int res;

	i = 0;
	sign = 1;
	res = 0;
	while (nptr[i] == ' ' || nptr[i] == '\f' || nptr[i] == '\n' || nptr[i] == '\r' || nptr[i] == '\t' || nptr[i] == '\v')
		i++;
	if (nptr[i] == '+')
		i++;
	else if (nptr[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + nptr[i] - '0';
		i++;
	}
	return (res * sign);
}

void ft_bzero(void *s, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = '\0';
		i++;
	}
}

long int ft_time(void)
{
	long int time;
	struct timeval current_time;

	gettimeofday(&current_time, NULL);
	time = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	return (time);
}

void ft_msg(t_philo *philo, int action)
{
	pthread_mutex_lock(&philo->data->write_mutex);
	if (action == FORK)
		printf("%ld %d %s", (ft_time() - philo->data->time_start), philo->id, FORK);
	else if (action == EAT)
		printf("%ld %d %s", (ft_time() - philo->data->time_start), philo->id, EAT);
	else if (action == SLEEP)
		printf("%ld %d %s", (ft_time() - philo->data->time_start), philo->id, SLEEP);
	else if (action == THINK)
		printf("%ld %d %s", (ft_time() - philo->data->time_start), philo->id, THINK);
	else if (action == DEAD)
		printf("%ld %d %s", (ft_time() - philo->data->time_start), philo->id, DEAD);
	pthread_mutex_unlock(&philo->data->write_mutex);
	return;
}

void ft_one_philo(t_data *data)
{
	printf("%ld %d has taken a fork\n", (ft_time() - data->time_start), 1);
	printf("%ld %d died\n", (data->time_die + 1), 1);
	exit(EXIT_SUCCESS);
}

