/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucisanc <lucisanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 21:22:57 by lucisanc          #+#    #+#             */
/*   Updated: 2022/03/08 21:58:15 by lucisanc         ###   ########.fr       */
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

void	print_status(t_philo philo, char *msg, int death)
{
	static int	has_died = 0;

	if (death)
		has_died = death;
	sem_wait(philo.print);
	if (death || !has_died)
		printf("%-7ld %-2d %s\n",
			get_time() - philo.start_time, philo.id, msg);
	sem_post(philo.print);
}

time_t	get_time(void)
{
	static struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * (time_t)1000) + (tv.tv_usec / 1000));
}

int	error_exit(char *msg, int exit_code)
{
	ft_putstr_fd("Error: ", STDERR_FILENO);
	ft_putstr_fd(msg, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	return (exit_code);
}
