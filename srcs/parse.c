/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucisanc <lucisanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:54:30 by lucisanc          #+#    #+#             */
/*   Updated: 2022/03/08 19:54:39 by lucisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	parse_data(int ac, char **av, t_philo *p_ref)
{
	p_ref->nb_philos = ft_atoi(av[1]);
	if (p_ref->nb_philos <= 0)
		return (error_exit(INVALID_N_PHILOS, -1));
	p_ref->tt_die = ft_atoi(av[2]);
	p_ref->tt_eat = ft_atoi(av[3]);
	p_ref->tt_sleep = ft_atoi(av[4]);
	if (p_ref->tt_die <= 0 || p_ref->tt_eat <= 0 || p_ref->tt_sleep <= 0)
		return (error_exit(INVALID_SPECS, -1));
	p_ref->start_time = get_time();
	p_ref->last_ate = p_ref->start_time;
	p_ref->finished_eating = 0;
	p_ref->remaining_meals = -1;
	if (ac == 6)
	{
		p_ref->remaining_meals = ft_atoi(av[5]);
		if (p_ref->remaining_meals < 0)
			p_ref->remaining_meals = 0;
			// return (error_exit(INVALID_SPECS, -1));
	}
	return (0);
}

void	copy_philos(t_philo *dest, t_philo src, int i)
{
	dest->id = i + 1;
	dest->nb_philos = src.nb_philos;
	dest->tt_die = src.tt_die;
	dest->tt_eat = src.tt_eat;
	dest->tt_sleep = src.tt_sleep;
	dest->remaining_meals = src.remaining_meals;
	dest->finished_eating = src.finished_eating;
	dest->last_ate = src.last_ate;
	dest->start_time = src.start_time;
	// printf("st time : %ld\n", dest->start_time);
}

int		init(int ac, char **av, t_philo **p_philos)
{
	t_philo	ref;
	int		i;

	if (ac != 5 && ac != 6)
		return (error_exit(ERROR_ARGS, -1));
	if (parse_data(ac, av, &ref) == -1)
		return (error_exit(PARSING_ERROR, -1));
	*p_philos = (t_philo *)malloc(sizeof(t_philo) * (ref.nb_philos + 1));
	if (!(*p_philos))
		error_exit(MALLOC_FAIL, -1);
	i = -1;
	while (++i < ref.nb_philos)
		copy_philos((*p_philos + i), ref, i);
	return (0);
}