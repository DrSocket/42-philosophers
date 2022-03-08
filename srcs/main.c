/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucisanc <lucisanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 13:36:14 by lucisanc          #+#    #+#             */
/*   Updated: 2022/03/08 14:09:43 by lucisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_usleep(useconds_t time_val)
{
	time_t		start_time;
	useconds_t	to_wait;
	useconds_t	sleep_val;

	start_time = get_time();
	to_wait = (start_time * 1000 + time_val) - get_time() * 1000;
	if (to_wait > 500)
		sleep_val = 500;
	else
		sleep_val = to_wait;
	while (to_wait > 0)
	{
		usleep(sleep_val);
		to_wait = (start_time * 1000 + time_val) - get_time() * 1000;
		if (to_wait > 500)
			sleep_val = 500;
		else
			sleep_val = to_wait;
	}
}

// void		*check_threads(void *philo)
// {
// 	t_philo ref;

// 	ref = *(t_philo *)philo;
// 	printf("Hello philo: %d\n", ref.remaining_meals);
// 	return (0);
// }

static int	init_threads(t_philo *philos)
{
	int				i;
	int				amount;
	pthread_t		th_id[philos->nb_philos];

	amount = philos->nb_philos;
	i = -1;
	while (++i < amount)
	{
		philos[i].left_fork = philos[i].fork;
		philos[i].right_fork = philos[(i + 1) % amount].fork;
		if (pthread_create(&th_id[i], NULL, &main_loop, (void *)(philos + i)) != 0)
			return (error_exit(THREAD_CREATE_FAIL, -1));
		if (philos[i].finished_eating)
			return (0);
	}
	i = -1;
	while (++i < amount)
		if (pthread_join(th_id[i], NULL) != 0)
			return (error_exit(THREAD_JOIN_FAIL, -1));
	return (0);
}

int	init_mutex(t_philo *p_philo)
{
	int	i;

	i = 0;
	while (i < p_philo->nb_philos)
	{
		// printf("PHILO ID: %d\n", p_philo[i].id);
		p_philo[i].fork = malloc(sizeof(pthread_mutex_t));
		if (!p_philo[i].fork)
			return (error_exit(MUTEX_INIT_FAIL, -1));
		if (pthread_mutex_init(p_philo[i].fork, NULL) == -1)
			return (error_exit(MUTEX_INIT_FAIL, -1));
		i++;
	}
	return (0);
}

int	destroy_mutex(t_philo *p_philo)
{
	int	i;

	i = -1;
	while (++i < p_philo->nb_philos)
		if (pthread_mutex_destroy(p_philo[i].fork) != 0)
			return (error_exit(MUTEX_DESTROY_FAIL, -1));
	return (0);
}

int		main(int ac, char **av)
{
	t_philo		*philos;
	
	if (init(ac, av, &philos) == -1)
		return (1);
	if (init_mutex(philos) == -1)
		return (1);
	if (init_threads(philos) == -1)
		return (1);
	if (destroy_mutex(philos) == -1)
		return (1);


	free(philos);
	return (0);
}