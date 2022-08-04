/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrechai <anrechai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 19:52:35 by anrechai          #+#    #+#             */
/*   Updated: 2022/08/04 22:35:13 by anrechai         ###   ########.fr       */
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

void	*ft_exit(t_philo *philo)
{
	// pthread_mutex_unlock(&philo->data->dead_mutex);
	// pthread_mutex_unlock(&philo->data->eat_mutex);
	// pthread_detach(philo->thread);
	pthread_mutex_destroy(&philo->data->forks[philo->id - 1]);
	pthread_mutex_destroy(&philo->data->eat_mutex);
	pthread_mutex_destroy(&philo->data->write_mutex);
	pthread_mutex_destroy(&philo->data->stop_mutex);
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_data	*data;
	t_philo	*philo;

	if (ft_check_arg(argc, argv) == -1)
		return (-1);
	data = malloc(sizeof(t_data));
	if (init_data(argc, argv, data) != 0)
		return (-1);
	philo = malloc(sizeof(t_philo) * (data->nb_philo));
	init_philo(data, philo);
	init_mutex(data);
	init_thread(philo);
	// ft_exit(philo);
	free(data->forks);
	free(data->meals);
	free(data);
	free(philo);
	return (0);
}

