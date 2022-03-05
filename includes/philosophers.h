/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucisanc <lucisanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 13:36:17 by lucisanc          #+#    #+#             */
/*   Updated: 2022/02/26 14:12:42 by lucisanc         ###   ########.fr       */
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
# define INVALID_TIME_SPEC "Invalid time specification"
# define MALLOC_FAIL "malloc failed"


# define ITOA_MALLOC_FAIL "malloc failed on ft_itoa"
# define PARSING_ERROR "parsing failed"
# define THREAD_CREATE_FAIL "creating thread failed"
# define MUTEX_INIT_FAIL "failed to init mutex"

typedef struct	s_philo
{
	int				id;
	int				remaining_meals;
	long			death_time;
	long			sleep_time;
	long			eat_time;
	int				finished_eating;
	time_t			last_ate;
	time_t			born_time;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*printer;
}				t_philo;


/*
 *	utils.c
 */

int		ft_atoi(char *str);
int		ft_strlen(char *str);
int		error_exit(char *msg, int exit_code);
void	ft_putstr_fd(char *str, int fd);


int     parse_args(int ac, char **av, t_philo **philos);



#endif