/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucisanc <lucisanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 13:36:17 by lucisanc          #+#    #+#             */
/*   Updated: 2022/03/07 20:49:45 by lucisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include <stdbool.h>
# include <sys/time.h>
# include <pthread.h>

# define PHILO_EAT "is eating"
# define PHILO_SLEEP "is sleeping"
# define PHILO_THINK "is thinking"
# define PHILO_FORK "has taken a fork"
# define PHILO_ATE "has taken a fork"
# define PHILO_DIED "died"

# define ERROR_ARGS "Wrong number of arguments"
# define INVALID_N_PHILOS "Invalid number of philosophers"
# define INVALID_SPECS "Invalid specifications"
# define MALLOC_FAIL "Malloc failed"
# define GET_TIME_FAIL "Error getting time"
# define PARSING_ERROR "Parsing failed"


# define THREAD_CREATE_FAIL "creating thread failed"
# define MUTEX_INIT_FAIL "failed to init mutex"

# define FORK 1
# define EAT 2
# define SLEEP 3
# define THINK 4
# define DIE 5

typedef struct	s_data
{
	int				nb_philos;
	int				tt_die;
	int				tt_eat;
	int				tt_sleep;
	int				max_meals;
	time_t			start_time;
	struct s_philo	*philos;
	pthread_mutex_t	*fork;
}				t_data;

typedef struct	s_philo
{
	int				id;
	int				nb_philos;
	int				remaining_meals;
	int				finished_eating;
	int				died;
	time_t			born_time;
	time_t			last_ate;
	pthread_t		*philo_thread;
	// pthread_mutex_t	time;
	// time_t			born_time;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	// pthread_mutex_t	*printer;
}				t_philo;

typedef	struct	s_info
{
	struct s_data	data;
	struct s_philo	philo;
}				t_info;

/*
 *	utils.c
 */

int		ft_atoi(char *str);
int		ft_strlen(char *str);
int		error_exit(char *msg, int exit_code);
void	ft_putstr_fd(char *str, int fd);
time_t	get_time(void);
// int		print_message(t_philo philo, char *msg);
void	print_status(t_philo philo, char *msg, int death);

int		init(int ac, char **av, t_philo **philos, t_data *data);
void	*main_loop(void *philo_ptr);
void	ft_usleep(useconds_t time_val);


#endif