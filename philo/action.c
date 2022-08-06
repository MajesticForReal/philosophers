/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrechai <anrechai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 17:56:59 by anrechai          #+#    #+#             */
/*   Updated: 2022/08/05 18:20:51 by anrechai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_fork(t_philo *philo)
{
	int	i;
	int	fork;

	i = 0;
	while (i < 2)
	{
		if (i == 0)
			fork = philo->lf;
		else
			fork = philo->rf;
		pthread_mutex_lock(&philo->data->forks[fork]);
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
	pthread_mutex_lock(&philo->data->stop_mutex);
	ft_stop(philo);
	pthread_mutex_unlock(&philo->data->stop_mutex);
	pthread_mutex_unlock(&philo->data->eat_mutex);
	usleep(philo->data->time_eat * 1000);
	pthread_mutex_unlock(&philo->data->forks[philo->lf]);
	pthread_mutex_unlock(&philo->data->forks[philo->rf]);
}

void	ft_sleep(t_philo *philo)
{
	ft_msg(philo, 3);
	usleep(philo->data->time_sleep * 1000);
}

void	ft_think(t_philo *philo)
{
	ft_msg(philo, 4);
	if (philo->data->time_eat * 2 > philo->data->time_die)
		usleep(((philo->data->time_die + 1) - (philo->data->time_eat
					+ philo->data->time_sleep)) * 1000);
}

void	ft_stop(t_philo *philo)
{
	int	i;
	int	index;

	i = 0;
	index = 0;
	if (philo->data->nb_eat >= 0)
	{
		while (philo->data->meals[index] >= philo->data->nb_eat)
		{
			if (i == philo->data->nb_philo - 1)
			{
				philo->data->status = 1;
				return ;
			}
			i++;
			index++;
		}
	}
}
