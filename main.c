/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrechai <anrechai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 19:52:35 by anrechai          #+#    #+#             */
/*   Updated: 2022/07/11 16:20:57 by anrechai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_arg2(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		if (argv[i][0] == '\0')
			return (-1);
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_check_arg(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
	{
		write(2, "Invalid number of arguments\n", 28);
		return (-1);
	}
	if (ft_check_arg2(argv) == -1)
	{
		write(2, "Invalid argument\n", 17);
		return (-1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	long int		time;
	struct timeval	current_time;

	if (gettimeofday(&current_time, NULL) == -1)
		return (-1);
	time = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	printf("TIME : %ld\n", time);
	// printf("TIME : %ld\n", current_time.tv_usec);
	// printf("TIME : %ld\n", current_time.tv_usec);
	// printf("TIME : %ld\n", current_time.tv_usec);
	// printf("TIME : %ld\n", current_time.tv_usec);
	// printf("seconds : %ld\nmicro seconds : %ld",
			// current_time.tv_sec,
			// current_time.tv_usec);
	if (ft_check_arg(argc, argv) == -1)
		return (-1);
	return (0);
}
