/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucisanc <lucisanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 21:25:49 by lucisanc          #+#    #+#             */
/*   Updated: 2022/03/08 21:56:01 by lucisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	init_mutex(t_philo **p_philo)
{
	int		i;
	t_philo	*ref;

	i = -1;
	ref = *p_philo;
	while (++i < ref->nb_philos)
	{
		ref[i].fork = malloc(sizeof(pthread_mutex_t));
		if (!ref[i].fork)
			return (error_exit(MUTEX_INIT_FAIL, -1));
		if (pthread_mutex_init(ref[i].fork, NULL) == -1)
			return (error_exit(MUTEX_INIT_FAIL, -1));
	}
	*p_philo = ref;
	return (0);
}
