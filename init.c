/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrechai <anrechai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:58:44 by anrechai          #+#    #+#             */
/*   Updated: 2022/07/13 22:04:23 by anrechai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_all(int argc, char **argv, t_data *data)
{
	ft_bzero(data, sizeof(t_data));
	data->time_start = ft_time();
	data->nb_philo = ft_atoi(argv[1]);
	data->time_die = ft_atoi(argv[2]);
	data->time_eat = ft_atoi(argv[3]);
	data->time_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->nb_eat = ft_atoi(argv[5]);
	return ;
}

void	init_philo(t_data *data, t_philo *philo)
{
	int	i;

	i = data->nb_philo;
	while (--i >= 0)
	{
		philo[i].id = i;
		philo[i].x_meal = 0;
		philo[i].lf = i;
		philo[i].rf = (i + 1) % data->nb_philo;
		philo[i].last_meal = 0;
		philo[i].data = data;
	}
	return ;
}
