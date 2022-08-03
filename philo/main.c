/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrechai <anrechai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 19:52:35 by anrechai          #+#    #+#             */
/*   Updated: 2022/08/03 17:53:49 by anrechai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_status(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->dead_mutex);
	if (philo->data->status == 0)
	{
		pthread_mutex_unlock(&philo->data->dead_mutex);
		return (0);
	}
	else if (philo->data->status == 1)
	{
		// pthread_mutex_unlock(&philo->data->dead_mutex);
		// ft_exit();
		exit(EXIT_SUCCESS);
	}
	else if (philo->data->status == 2)
	{
		ft_msg(philo, 5);
		// ft_msg(philo, DEAD);
		// ft_exit();
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	*data;
	t_philo	*philo;

	if (ft_check_arg(argc, argv) == -1)
		return (-1);
	data = malloc(sizeof(t_data));
	init_data(argc, argv, data);
	philo = malloc(sizeof(t_philo) * (data->nb_philo));
	if (argv[1][0] == '1' && argv[1][1] == '\0')
		ft_one_philo(data);
	init_philo(data, philo);
	init_mutex(data);
	init_thread(philo);
	free(data);
	free(philo);
	return (0);
}

