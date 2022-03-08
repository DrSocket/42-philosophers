/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucisanc <lucisanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 19:32:34 by lucisanc          #+#    #+#             */
/*   Updated: 2022/03/08 20:13:01 by lucisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	take_fork(t_philo philo, pthread_mutex_t *fork)
{
	pthread_mutex_lock(fork);
	print_status(philo, PHILO_FORK, 0);
}

void	philo_eat(t_philo philo)
{
	print_status(philo, PHILO_EAT, 0);
	ft_usleep(philo.tt_eat * 1000);
	pthread_mutex_unlock(philo.left_fork);
	pthread_mutex_unlock(philo.right_fork);
}

void	philo_sleep(t_philo philo)
{
	print_status(philo, PHILO_SLEEP, 0);
	ft_usleep(philo.tt_sleep * 1000);
}

void	philo_think(t_philo philo)
{
	print_status(philo, PHILO_THINK, 0);
}

void	*main_loop(void *p_philo)
{
	t_philo	*ref;

	ref = (t_philo *)p_philo;
	if (ref->id % 2 == 1)
		usleep(1000 * (ref->tt_eat / 2));
	while (ref->remaining_meals != 0)
	{
		take_fork(*ref, ref->left_fork);
		take_fork(*ref, ref->right_fork);
		ref->last_ate = get_time();
		philo_eat(*ref);
		philo_sleep(*ref);
		philo_think(*ref);
		if (ref->remaining_meals > 0)
			ref->remaining_meals--;
	}
	ref->finished_eating = 1;
	return ((void *)ref);
}
