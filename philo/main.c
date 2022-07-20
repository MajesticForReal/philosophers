/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrechai <anrechai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 19:52:35 by anrechai          #+#    #+#             */
/*   Updated: 2022/07/20 17:08:54 by anrechai         ###   ########.fr       */
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

void	*routine_loop(t_philo *philo)
{
	int	i;

	i = 0;
	while (1)
	{
		if (philo->data->nb_eat == 0 || philo->x_meal == philo->data->nb_eat)
			exit(EXIT_SUCCESS);
		// FT FREEEEE EXIIIIIIIT
		// if (check_stop == 0 && check_dead == 0)
		ft_eat(philo);
		pthread_join(philo[i].thread, NULL);
		i++;
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
		usleep(1000);
	routine_loop(philo);
	return (NULL);
}

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

	// mutex_fork(t_utils_philo *philo, pthread_mutex_t *rf, pthread_mutex_t *lf)
// {
	// pthread_mutex_lock(lf);
	// display_msg(philo, FORK, 0);
	// pthread_mutex_lock(rf);
	// display_msg(philo, FORK, 0);
	// display_msg(philo, EAT, 0);
	// pthread_mutex_lock(&philo->info->death_mutex);
	// philo->last_meal = actual_time() - philo->info->start_time;
	// pthread_mutex_unlock(&philo->info->death_mutex);
	// pthread_mutex_lock(&philo->info->eat_mutex);
	// if (philo->to_eat < philo->info->nb_eat)
		// philo->to_eat++;
	// if (philo->to_eat == philo->info->nb_eat && philo->info->nb_eat != 0)
		// philo->info->finish_eat++;
	// pthread_mutex_unlock(&philo->info->eat_mutex);
	// ft_usleep(philo->info->time_eat, philo->info);
	// pthread_mutex_unlock(rf);
	// pthread_mutex_unlock(lf);
	// display_msg(philo, SLEEP, 0);
	// ft_usleep(philo->info->time_sleep, philo->info);
	// display_msg(philo, THINK, 0);
// }

// void	eat_action(t_philo *philo)
// {
	// t_data	*data;
//
	// data = philo->data;
	// pthread_mutex_lock(&(data->fork_m[philo->left_fork_id]));
	// print_things(data, philo->id, "has taken a fork");
	// pthread_mutex_lock(&(data->fork_m[philo->right_fork_id]));
	// print_things(data, philo->id, "has taken a fork");
	// print_things(data, philo->id, "is eating");
	// pthread_mutex_lock(&(data->meal_check));
	// philo->t_last_meal = timestamp();
	// pthread_mutex_unlock(&(data->meal_check));
	// wait_action(data->time_eat);
	// pthread_mutex_lock(&(data->meal_check));
	// (philo->x_ate)++;
	// pthread_mutex_unlock(&(data->meal_check));
	// pthread_mutex_unlock(&(data->fork_m[philo->left_fork_id]));
	// pthread_mutex_unlock(&(data->fork_m[philo->right_fork_id]));
// }

void	create_thread(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->data->nb_philo)
	{
		pthread_create(&philo[i].thread, NULL, &routine, &philo[i]);
		usleep(2000);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_data	*data;
	t_philo	*philo;
	// int		i;

	if (ft_check_arg(argc, argv) == -1)
		return (-1);
	data = malloc(sizeof(t_data));
	init_all(argc, argv, data);
	philo = malloc(sizeof(t_philo) * (data->nb_philo));
	if (argv[1][0] == '1' && argv[1][1] == '\0')
		ft_one_philo(data);
	init_philo(data, philo);
	init_mutex(data);
	create_thread(philo);
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
