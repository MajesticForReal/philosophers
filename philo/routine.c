/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrechai <anrechai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 16:05:36 by anrechai          #+#    #+#             */
/*   Updated: 2022/08/05 17:58:50 by anrechai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_status(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->stop_mutex);
	if (philo->data->status == 1)
	{
		pthread_mutex_unlock(&philo->data->stop_mutex);
		return (-1);
	}
	if ((ft_time() - philo->last_meal) > philo->data->time_die)
	{
		philo->data->status = 2;
	}
	if (philo->data->status == 0)
	{
		pthread_mutex_unlock(&philo->data->stop_mutex);
		return (0);
	}
	else if (philo->data->status == 2)
	{
		ft_msg(philo, 5);
		philo->data->status = 1;
		pthread_mutex_unlock(&philo->data->stop_mutex);
		return (-1);
	}
	return (0);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2)
		usleep(15 * 1000);
	routine_loop(philo);
	return (NULL);
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
	}
}
