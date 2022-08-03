/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrechai <anrechai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 16:05:36 by anrechai          #+#    #+#             */
/*   Updated: 2022/08/03 21:29:40 by anrechai         ###   ########.fr       */
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
	return (NULL);
}

void	*routine_loop(t_philo *philo)
{
	int	i;
	int	index;
	
	while (1)
	{
		
		ft_eat(philo);
		ft_sleep(philo);
		if (ft_time() - philo->last_meal > philo->data->time_die)
		{
			philo->data->status = 2;
			check_status(philo);
		}
		ft_msg(philo, 4);
		usleep(11 * 1000);
		// if (ft_time() - philo->last_meal > philo->data->time_die)
		// {
			// philo->data->status = 2;
			// check_status(philo);
		// }
		i = 0;
		index = 0;
		if (philo->data->nb_eat >= 0)
		{
			while (philo->data->meals[index] >= philo->data->nb_eat)
			{
				if (i == philo->data->nb_philo - 1)
					exit(EXIT_SUCCESS);
				i++;
				index++;
			}
		}
	}

}

void	ft_fork(t_philo *philo)
{
	int		i;
	int		fork;

	i = 0;
	// pthread_mutex_lock(&philo->data->dead_mutex);
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
}

void	ft_eat(t_philo *philo)
{
	if (ft_time() - philo->last_meal > philo->data->time_die)
	{
		philo->data->status = 2;
		check_status(philo);
	}
	ft_fork(philo);
	pthread_mutex_lock(&philo->data->eat_mutex);
	if (ft_time() - philo->last_meal > philo->data->time_die)
	{
		philo->data->status = 2;
		check_status(philo);
	}
	philo->last_meal = ft_time();
	philo->x_meal++;
	philo->data->meals[philo->id - 1]++;
	ft_msg(philo, 2);
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