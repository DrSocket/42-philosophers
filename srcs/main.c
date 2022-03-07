/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucisanc <lucisanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 13:36:14 by lucisanc          #+#    #+#             */
/*   Updated: 2022/03/07 20:45:26 by lucisanc         ###   ########.fr       */
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

static int	init_threads(t_philo *philos, t_data *data)
{
	int				i;
	int				amount;
	t_info			info;
	pthread_t		th_id[data->nb_philos];
	// pthread_mutex_t	*printer;

	amount = data->nb_philos;
	info.data = *data;
	// printer = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	// if (!printer)
	// 	return (error_exit(MALLOC_FAIL, -1));
	// if (pthread_mutex_init(printer, NULL) != 0)
	// 	return (error_exit(MUTEX_INIT_FAIL, -1));
	i = -1;
	while (++i < amount)
	{
		info.philo = philos[i];
		philos[i].left_fork = &data->fork[i];
		philos[i].right_fork = &data->fork[(i + 1) % amount];
		// philos[i].printer = printer;
		if (pthread_create(&th_id[i], NULL, main_loop, (void *)(&info)) != 0)
			return (error_exit(THREAD_CREATE_FAIL, -1));
		// pthread_detach(th_id);
	}
	i = -1;
	while (++i < amount)
	{
		pthread_join(th_id[i], NULL);
		
	}
	return (0);
}



int	init_mutex(t_data *data)
{
	int	i;

	i = 0;
	data->fork = malloc(sizeof(pthread_mutex_t) * data->nb_philos);
	if (!data->fork)
		return (error_exit(MUTEX_INIT_FAIL, -1));
	while (i < data->nb_philos)
	{
		if (pthread_mutex_init(&data->fork[i], NULL) == -1)
			return (error_exit(MUTEX_INIT_FAIL, -1));
		i++;
	}
	return (0);
}

int		main(int ac, char **av)
{
	t_philo		*philos;
	t_data		data;

	
	if (init(ac, av, &philos, &data) == -1)
		return (1);
	if (init_mutex(&data) == -1)
		return (1);
	if (init_threads(philos, &data) == -1)
		return (1);


	free(philos);
	return (0);
}