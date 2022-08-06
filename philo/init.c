/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrechai <anrechai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:58:44 by anrechai          #+#    #+#             */
/*   Updated: 2022/08/05 18:44:12 by anrechai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_data_2(t_data *data)
{
	int	i;

	if (data->nb_philo > 200 || data->nb_philo < 1 || data->time_die < 0
		|| data->time_eat < 0 || data->time_sleep < 0)
	{
		write(2, "Invalid argument\n", ft_strlen("Invalid argument\n"));
		return (-1);
	}
	data->meals = malloc(sizeof(int) * data->nb_philo);
	if (!data->meals)
		return (-1);
	i = 0;
	while (i < data->nb_philo)
	{
		data->meals[i] = 0;
		i++;
	}
	if (data->nb_philo == 1)
	{
		ft_one_philo(data);
		return (-1);
	}
	return (0);
}

int	init_data(int argc, char **argv, t_data *data)
{
	ft_bzero(data, sizeof(t_data));
	data->time_start = ft_time();
	data->nb_philo = ft_atoi(argv[1]);
	data->time_die = ft_atoi(argv[2]);
	data->time_eat = ft_atoi(argv[3]);
	data->time_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->nb_eat = ft_atoi(argv[5]);
	if (argc == 5)
		data->nb_eat = -1;
	if (data->nb_eat == 0)
	{
		write(2, "Invalid argument not enough meal\n",
			ft_strlen("Invalid argument not enough meal\n"));
		return (-1);
	}
	if (init_data_2(data) != 0)
		return (-1);
	return (0);
}

int	init_mutex(t_data *data)
{
	int	i;

	if (pthread_mutex_init(&data->write_mutex, NULL) != 0)
		return (-1);
	if (pthread_mutex_init(&data->eat_mutex, NULL) != 0)
		return (-1);
	if (pthread_mutex_init(&data->stop_mutex, NULL) != 0)
		return (-1);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->nb_philo);
	if (!data->forks)
		return (-1);
	i = 0;
	while (i < data->nb_philo)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
	return (0);
}

void	init_philo(t_data *data, t_philo *philo)
{
	int	i;

	i = data->nb_philo;
	while (--i >= 0)
	{
		philo[i].id = i + 1;
		philo[i].x_meal = 0;
		philo[i].lf = i;
		philo[i].rf = (i + 1) % data->nb_philo;
		philo[i].last_meal = ft_time();
		philo[i].data = data;
	}
	return ;
}

void	init_thread(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->data->nb_philo)
	{
		pthread_create(&philo[i].thread, NULL, &routine, &philo[i]);
		i++;
	}
	i = 0;
	while (i < philo->data->nb_philo)
	{
		pthread_join(philo[i].thread, NULL);
		i++;
	}
	return ;
}
