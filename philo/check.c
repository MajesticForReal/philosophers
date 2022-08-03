/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrechai <anrechai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 20:54:47 by anrechai          #+#    #+#             */
/*   Updated: 2022/08/03 15:18:18 by anrechai         ###   ########.fr       */
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
		if (j > 9)
			return (-1);
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
