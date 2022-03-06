/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucisanc <lucisanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 13:36:17 by lucisanc          #+#    #+#             */
/*   Updated: 2022/03/06 19:48:43 by lucisanc         ###   ########.fr       */
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
# define GET_TIME_FAIL "error getting time"
# define PARSING_ERROR "parsing failed"


# define ITOA_MALLOC_FAIL "malloc failed on ft_itoa"
# define THREAD_CREATE_FAIL "creating thread failed"
# define MUTEX_INIT_FAIL "failed to init mutex"

typedef struct	s_philo
{
	int				id;
	int				n_of_meals;
	long			to_die;
	long			to_sleep;
	long			to_eat;
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
time_t	get_time(void);
int		print_message(char *msg);


int		parse_args(int ac, char **av, t_philo **philos);



#endif