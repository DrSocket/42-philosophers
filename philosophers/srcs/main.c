/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucisanc <lucisanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 13:36:14 by lucisanc          #+#    #+#             */
/*   Updated: 2022/03/11 18:13:50 by lucisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	init_threads(t_philo *philos)
{
	int				i;
	int				amount;
	pthread_mutex_t	*print;
	pthread_t		th;

	amount = philos->nb_philos;
	print = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	if (!print)
		return (error_exit(MALLOC_FAIL, -1));
	if (pthread_mutex_init(print, NULL) != 0)
		return (error_exit(MUTEX_INIT_FAIL, -1));
	i = -1;
	while (++i < amount)
	{
		philos[i].left_fork = philos[i].fork;
		philos[i].right_fork = philos[(i + 1) % amount].fork;
		philos[i].print = print;
		if (pthread_create(&th, NULL, &main_loop, (void *)&philos[i]) != 0)
			return (error_exit(THREAD_CREATE_FAIL, -1));
		pthread_detach(th);
	}
	return (0);
}

static void	check_alive(t_philo *philos)
{
	int	i;
	int	amount;

	amount = philos->nb_philos;
	while (1)
	{
		i = -1;
		usleep(500);
		while (++i < amount)
		{	
			if (philos[i].finished_eating)
				return ;
			if (get_time() - philos[i].last_ate > philos[i].tt_die)
				return (print_status(philos[i], PHILO_DIED, 1));
		}
	}
}

int	main(int ac, char **av)
{
	t_philo		*philos;
	int			i;

	if (parse(ac, av, &philos) == -1)
		return (1);
	if (init_mutex(&philos) == -1)
		return (1);
	if (init_threads(philos) == -1)
		return (1);
	check_alive(philos);
	i = -1;
	while (++i < philos->nb_philos)
		pthread_mutex_destroy(philos[i].fork);
	free(philos);
	return (0);
}
