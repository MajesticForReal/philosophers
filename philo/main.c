/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrechai <anrechai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 19:52:35 by anrechai          #+#    #+#             */
/*   Updated: 2022/08/05 18:47:58 by anrechai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = '\0';
		i++;
	}
}

void	ft_exit(t_philo *philo, t_data *data)
{
	int	i;

	i = data->nb_philo;
	while (i-- > 0)
		pthread_mutex_destroy(&philo->data->forks[i]);
	pthread_mutex_destroy(&philo->data->eat_mutex);
	pthread_mutex_destroy(&philo->data->write_mutex);
	pthread_mutex_destroy(&philo->data->stop_mutex);
	free(data->forks);
	free(data->meals);
	free(data);
	free(philo);
	return ;
}

int	main(int argc, char **argv)
{
	t_data	*data;
	t_philo	*philo;

	if (ft_check_arg(argc, argv) == -1)
		return (-1);
	data = malloc(sizeof(t_data));
	if (!data)
		return (-1);
	if (init_data(argc, argv, data) != 0)
		return (free(data->meals), free(data), 0);
	philo = malloc(sizeof(t_philo) * (data->nb_philo));
	if (!philo)
		return (free(data), -1);
	init_philo(data, philo);
	if (init_mutex(data) != 0)
		return (free(data), free(philo), -1);
	init_thread(philo);
	ft_exit(philo, data);
	return (0);
}
