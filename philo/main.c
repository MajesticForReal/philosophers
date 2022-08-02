/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 19:52:35 by anrechai          #+#    #+#             */
/*   Updated: 2022/08/02 23:04:44 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_status(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->dead_mutex);
	if (philo->data->status == 0)
	{
		pthread_mutex_unlock(&philo->data->dead_mutex);
		return ;
	}
	else if (philo->data->status == 1)
	{
		pthread_mutex_unlock(&philo->data->dead_mutex);
		// ft_exit();
		exit(EXIT_SUCCESS);
	}
	else if (philo->data->status == 2)
	{
		printf("%ld %d %s", (ft_time() - philo->data->time_start), philo->id, DEAD);
		// ft_msg(philo, DEAD);
		// ft_exit();
		exit(EXIT_SUCCESS);
	}
	return ;
}

// void	ft_eat(t_philo *philo)
// {
// 	pthread_mutex_lock(&philo->data->lf);
// 	ft_msg(philo, FORK);
// 	pthread_mutex_lock(&philo->data->rf);
// 	ft_msg(philo, FORK);
// 	if (philo->last_meal - ft_time() > philo->data->time_die)
// 	{
// 		philo->data->status = 2;
// 		check_status(philo);
// 	}
// 	usleep(philo->data->time_eat / 1000);
// 	philo->last_meal = ft_time;
// 	philo->x_meal++;
// 	pthread_mutex_unlock(&philo->data->lf);
// 	pthread_mutex_unlock(&philo->data->rf);
	
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

void	*routine_loop(t_philo *philo)
{
	int	i;

	i = 0;
	while (1)
	{
		// if (philo->data->nb_eat == 0 || philo->x_meal == philo->data->nb_eat)
		// 	exit(EXIT_SUCCESS);
		// FT FREEEEE EXIIIIIIIT
		// if (check_stop == 0 && check_dead == 0)
		ft_eat(philo);
		ft_sleep(philo);
		printf("%ld %d %s", (ft_time() - philo->data->time_start), philo->id, THINK);
		// while (i < philo->data->nb_philo)
		// {	
			// pthread_join(philo[i].thread, NULL);
			// i++;
		// }
		printf("\nOK CA REPART\n");
		// if (check_stop == 0 && check_dead == 0)
			// ft_sleep(philo);
		// if (check_stop == 0 && check_dead == 0)
			// ft_think(philo);
	}
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2)
		usleep(500);
	routine_loop(philo);
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_data	*data;
	t_philo	*philo;
	// int		i;

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
	// i = 0;
	// while (i < data->nb_philo)
	// {
		// printf("ID : %d\nLF : %d\nRF : %d\nX_MEAL : %d\nLAST MEAL : %ld\n",
				// philo[i].id, philo[i].lf, philo[i].rf, philo[i].x_meal,
				// philo[i].last_meal);
		// i++;
	// }
	// printf("ID : %d\nLF : %d\nRF : %d\nX_MEAL : %d\nLAST MEAL : %ld\n",
			// philo[i].id, philo[i].lf, philo[i].rf, philo[i].x_meal,
			// philo[i].last_meal;
	// printf("%ld\n%d\n%d\n%d\n%d\n%d\n", data->time_start, data->nb_philo,
			// data->time_die, data->time_eat, data->time_sleep, data->nb_eat);
	free(data);
	free(philo);
	return (0);
}

