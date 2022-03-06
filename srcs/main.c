/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucisanc <lucisanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 13:36:14 by lucisanc          #+#    #+#             */
/*   Updated: 2022/03/06 22:48:33 by lucisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int		n_meals_loop(t_philo **philos, int amount)
{
	int		i;

	i = 0;
	while (i < amount)
	{
		i++;
	}
	return (0);
}

int		start_threads(t_philo **philos, int amount)
{
	
}

int		main(int ac, char **av)
{
	t_philo		*philos;
	int			amount;

	amount = parse_args(ac, av, &philos);
	if (amount == -1)
		return (1);
	if (start_threads(&philos, amount) == -1)
	{
		free(philos);
		return (1);
	}
	// if (ac == 6)
	// 	n_meals_loop(&philos, amount);
	
	free(philos);
	return (0);
}