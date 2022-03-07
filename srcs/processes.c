/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucisanc <lucisanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:54:21 by lucisanc          #+#    #+#             */
/*   Updated: 2022/03/07 20:14:13 by lucisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	take_fork(t_philo philo, pthread_mutex_t *fork)
{
	pthread_mutex_lock(fork);
	print_message(philo, PHILO_FORK, 0);
}
