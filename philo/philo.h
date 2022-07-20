/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrechai <anrechai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 18:29:58 by anrechai          #+#    #+#             */
/*   Updated: 2022/07/20 16:01:12 by anrechai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define FORK "has taken a fork\n"
# define EAT "is eating\n"
# define SLEEP "is sleeping\n"
# define THINK "is thinking\n"
# define DEAD "is dead\n"
typedef struct s_data
{
	long int		time_start;
	int				nb_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				nb_eat;
	int				stop;
	pthread_mutex_t	write_mutex;
	pthread_mutex_t	dead_mutex;
	pthread_mutex_t	eat_mutex;
	pthread_mutex_t	stop_mutex;
	pthread_mutex_t	lf;
	pthread_mutex_t	rf;
}					t_data;

typedef struct s_philo
{
	int				id;
	int				lf;
	int				rf;
	int				x_meal;
	long int		last_meal;
	pthread_t		thread;
	struct s_data	*data;
}					t_philo;

int					ft_strlen(char *str);
int					init_mutex(t_data *data);
void				init_philo(t_data *data, t_philo *philo);
int					ft_check_arg(int argc, char **argv);
int					ft_check_arg2(char **argv);
int					ft_atoi(const char *nptr);
void				ft_bzero(void *s, size_t n);
long int			ft_time(void);
void				init_all(int argc, char **argv, t_data *data);
void				ft_one_philo(t_data *data);
void				create_thread(t_philo *philo);

#endif
