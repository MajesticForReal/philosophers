/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrechai <anrechai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 16:05:36 by anrechai          #+#    #+#             */
/*   Updated: 2022/07/20 17:10:28 by anrechai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_eat(t_philo *philo)
{
	// if (philo->x_meal == philo->data->nb_eat)
		// exit(EXIT_SUCCESS) ;
	pthread_mutex_lock(&philo->data->lf);
	printf("%ld %d %s" , (ft_time() - philo->data->time_start), philo->id, FORK);
	pthread_mutex_lock(&philo->data->rf);
	printf("%ld %d %s" , (ft_time() - philo->data->time_start), philo->id, FORK);
	pthread_mutex_lock(&philo->data->eat_mutex);
	philo->last_meal = ft_time();
	printf("ID : %d\nLF : %d\nRF : %d\nX_MEAL : %d\nLAST MEAL : %ld\n", philo->id, philo->lf, philo->rf, philo->x_meal, philo->last_meal);
	philo->x_meal++;
	pthread_mutex_unlock(&philo->data->eat_mutex);
	printf("%ld %d %s", (ft_time() - philo->data->time_start), philo->id, EAT);
	pthread_mutex_unlock(&philo->data->lf);
	pthread_mutex_unlock(&philo->data->rf);
	pthread_mutex_lock(&philo->data->stop_mutex);
	usleep(1500);
	pthread_mutex_unlock(&philo->data->stop_mutex);
}
