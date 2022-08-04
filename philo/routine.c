/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrechai <anrechai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 16:05:36 by anrechai          #+#    #+#             */
/*   Updated: 2022/08/04 22:12:08 by anrechai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2)
		usleep(15 * 1000);
	routine_loop(philo);
	// ft_exit(philo);
	return (NULL);
}

void	ft_think(t_philo *philo)
{
	ft_msg(philo, 4);
	if (philo->data->time_eat * 2 > philo->data->time_die)
		usleep(((philo->data->time_die + 1) - (philo->data->time_eat + philo->data->time_sleep)) * 1000);
}

void	ft_stop(t_philo *philo)
{
	int	i;
	int	index;

	pthread_mutex_lock(&philo->data->stop_mutex);
	i = 0;
	index = 0;
	if (philo->data->nb_eat >= 0)
	{
		while (philo->data->meals[index] >= philo->data->nb_eat)
		{
			if (i == philo->data->nb_philo - 1)
			{
				philo->data->status = 1;
				pthread_mutex_unlock(&philo->data->stop_mutex);
				return ;
			}
			i++;
			index++;
		}
	}
	pthread_mutex_unlock(&philo->data->stop_mutex);
}

void	*routine_loop(t_philo *philo)
{
	while (1)
	{
		if (check_status(philo) != 0)
			return (NULL);
		ft_eat(philo);
		if (check_status(philo) != 0)
			return (NULL);
		ft_sleep(philo);
		if (check_status(philo) != 0)
			return (NULL);
		ft_think(philo);
		if (check_status(philo) != 0)
			return (NULL);
		ft_stop(philo);
	}
}

int	ft_fork(t_philo *philo)
{
	int		i;
	int		fork;

	i = 0;
	while (i < 2)
	{
		if (i == 0)
			fork = philo->lf;
		else
			fork = philo->rf;
		pthread_mutex_lock(&philo->data->forks[fork]);
		if (check_status(philo) != 0)
			return (-1);
		ft_msg(philo, 1);
		i++;
	}
	return (0);
}

void	ft_eat(t_philo *philo)
{
	ft_fork(philo);
	pthread_mutex_lock(&philo->data->eat_mutex);
	philo->last_meal = ft_time();
	ft_msg(philo, 2);
	philo->data->meals[philo->id - 1]++;
	pthread_mutex_unlock(&philo->data->eat_mutex);
	usleep(philo->data->time_eat * 1000);
	pthread_mutex_unlock(&philo->data->forks[philo->rf]);
	pthread_mutex_unlock(&philo->data->forks[philo->lf]);
}

void	ft_sleep(t_philo *philo)
{
	ft_msg(philo, 3);
	usleep(philo->data->time_sleep * 1000);
}