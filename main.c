/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrechai <anrechai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 19:52:35 by anrechai          #+#    #+#             */
/*   Updated: 2022/07/14 15:55:07 by anrechai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// int	check_dead(t_philo *philo)
// {
// 	pthread_mutex_lock(&philo->data->dead_mutex);
// 	if ((ft_time() - philo->data->time_start)
// 		- philo->last_meal >= philo->data->time_die)
// 	{
// 		write(1, "DEAD\n", 5);
// 		pthread_mutex_lock(&philo->data->stop_mutex);
// 		philo->data->stop = 1;
// 		pthread_mutex_unlock(&philo->data->stop_mutex);
// 		pthread_mutex_unlock(&philo->data->dead_mutex);
// 		return (0);
// 	}
// 	pthread_mutex_unlock(&philo->data->dead_mutex);
// 	return (1);
// }

// int	check_stop(t_data *data)
// {
// 	int	ret;

// 	pthread_mutex_lock(&data->stop_mutex);
// 	ret = data->stop;
// 	pthread_mutex_unlock(&data->stop_mutex);
// 	return (ret);
// }

// int	check_eat(t_philo *philo)
// {
// 	pthread_mutex_lock(&philo->data->eat_mutex);
// 	if (philo->data->time_eat == philo->data->nb_eat
// 		&& philo->data->nb_eat != 0)
// 	{
// 		pthread_mutex_lock(&philo->data->stop_mutex);
// 		philo->data->stop = 1;
// 		pthread_mutex_unlock(&philo->data->stop_mutex);
// 		pthread_mutex_unlock(&philo->data->eat_mutex);
// 		return (0);
// 	}
// 	pthread_mutex_unlock(&philo->data->eat_mutex);
// 	return (1);
// }

// void	*routine(void *data)
// {
// 	t_philo	*philo;

// 	philo = (t_philo *)data;
// 	while (check_stop(philo->data) == 0)
// 		take_fork(philo);
// 	return (NULL);
// }

// void	next_prog(t_philo *philo)
// {
// 	int	j;

// 	j = 0;
// 	while (check_stop(philo->data) == 0)
// 	{
// 		if (check_dead(&philo[j]) == 0 || check_eat(philo) == 0)
// 		{
// 			j = 0;
// 			while (j < philo->data->nb_philo)
// 			{
// 				pthread_join(philo[j].thread, NULL);
// 				j++;
// 			}
// 			// j = -1;
// 			// while (++j < philo->data->nb_philo)
// 				// pthread_mutex_destroy(&philo[j].lf);
// 			pthread_mutex_destroy(&philo->data->dead_mutex);
// 			pthread_mutex_destroy(&philo->data->write_mutex);
// 			pthread_mutex_destroy(&philo->data->eat_mutex);
// 			pthread_mutex_destroy(&philo->data->stop_mutex);
// 			return ;
// 		}
// 	}
// }

void	create_thread(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->data->nb_philo)
	{
		// pthread_create(&philo[i].thread, NULL, &routine, &philo[i]);
		usleep(2000);
		i++;
	}
	// next_prog(philo);
}

int	init_mutex(t_data *data)
{
	if (pthread_mutex_init(&data->write_mutex, NULL) != 0)
		return (-1);
	if (pthread_mutex_init(&data->dead_mutex, NULL) != 0)
		return (-1);
	if (pthread_mutex_init(&data->eat_mutex, NULL) != 0)
		return (-1);
	if (pthread_mutex_init(&data->stop_mutex, NULL) != 0)
		return (-1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	*data;
	t_philo *philo;
	int	i;

	if (ft_check_arg(argc, argv) == -1)
		return (-1);
	data = malloc(sizeof(t_data));
	init_all(argc, argv, data);
	philo = malloc(sizeof(t_philo) * (data->nb_philo));
	if (argv[1][0] == '1' && argv[1][1] == '\0')
		ft_one_philo(data);
	init_philo(data, philo);
	// create__TREAD
	init_mutex(data);
	i = 0;
	while (i < data->nb_philo)
	{
		printf("ID : %d\nLF : %d\nRF : %d\nX_MEAL : %d\nLAST MEAL : %ld\n", philo[i].id, philo[i].lf, philo[i].rf, philo[i].x_meal, philo[i].last_meal);
		i++;
	}
	// printf("ID : %d\nLF : %d\nRF : %d\nX_MEAL : %d\nLAST MEAL : %ld\n", philo[i].id, philo[i].lf, philo[i].rf, philo[i].x_meal, philo[i].last_meal);
	printf("%ld\n%d\n%d\n%d\n%d\n%d\n", data->time_start, data->nb_philo, data->time_die, data->time_eat, data->time_sleep, data->nb_eat);
	free(data);
	free(philo);
	return (0);
}
