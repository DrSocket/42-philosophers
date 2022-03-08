/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucisanc <lucisanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 13:36:17 by lucisanc          #+#    #+#             */
/*   Updated: 2022/03/08 21:55:19 by lucisanc         ###   ########.fr       */
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

/*
 *	PHILO MESSAGE
 */

# define PHILO_EAT "is eating"
# define PHILO_SLEEP "is sleeping"
# define PHILO_THINK "is thinking"
# define PHILO_FORK "has taken a fork"
# define PHILO_DIED "died"

/*
 *	ERROR MESSAGE
 */

# define ERROR_ARGS "Wrong number of arguments"
# define INVALID_N_PHILOS "Invalid number of philosophers"
# define INVALID_SPECS "Invalid specifications"
# define MALLOC_FAIL "Malloc failed"
# define GET_TIME_FAIL "Error getting time"
# define PARSING_ERROR "Parsing failed"
# define THREAD_CREATE_FAIL "creating threads failed"
# define THREAD_JOIN_FAIL "joining threads failed"
# define MUTEX_INIT_FAIL "failed to init mutex"
# define MUTEX_DESTROY_FAIL "failed to destroy mutex"

typedef struct s_philo
{
	int				id;
	int				nb_philos;
	long			tt_die;
	long			tt_eat;
	long			tt_sleep;
	int				remaining_meals;
	int				finished_eating;
	time_t			start_time;
	time_t			last_ate;
	pthread_mutex_t	*fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*print;
}				t_philo;

/*
 *	utils.c
 */

int			ft_atoi(const char *str);
int			ft_strlen(char *str);
void		ft_putstr_fd(char *str, int fd);

/*
 *	philo_utils.c
 */

void		ft_usleep(useconds_t time_val);
void		ft_usleep(useconds_t time_val);
void		print_status(t_philo philo, char *msg, int death);
time_t		get_time(void);
int			error_exit(char *msg, int exit_code);

/*
 *	parse.c
 */

int			parse(int ac, char **av, t_philo **philos);

/*
 *	init.c
 */

int			init_mutex(t_philo **p_philo);

/*
 *	philosopher.c
 */

void		*main_loop(void *p_philo);

#endif