/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 16:05:36 by anrechai          #+#    #+#             */
/*   Updated: 2022/08/02 23:09:24 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->lf);
	printf("%ld %d %s" , (ft_time() - philo->data->time_start), philo->id, FORK);
	pthread_mutex_lock(&philo->data->rf);
	printf("%ld %d %s" , (ft_time() - philo->data->time_start), philo->id, FORK);
	pthread_mutex_lock(&philo->data->eat_mutex);
	printf("TEMPS INTERVALLE DE REPAS : \n%ld\n", (ft_time() - philo->last_meal));
	if (ft_time() - philo->last_meal > philo->data->time_die)
	{
		philo->data->status = 2;
		check_status(philo);
	}
	philo->last_meal = ft_time();
	philo->x_meal++;
	printf("%ld %d %s", (ft_time() - philo->data->time_start), philo->id, EAT);
	usleep(philo->data->time_eat * 1000);
	pthread_mutex_unlock(&philo->data->lf);
	pthread_mutex_unlock(&philo->data->rf);
	pthread_mutex_unlock(&philo->data->eat_mutex);
}

void	ft_sleep(t_philo *philo)
{
	printf("%ld %d %s", (ft_time() - philo->data->time_start), philo->id, SLEEP);
	usleep(philo->data->time_sleep * 1000);
}

	// printf("ID : %d\nLF : %d\nRF : %d\nX_MEAL : %d\nLAST MEAL : %ld\n", philo->id, philo->lf, philo->rf, philo->x_meal, philo->last_meal);