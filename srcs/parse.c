/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucisanc <lucisanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:54:30 by lucisanc          #+#    #+#             */
/*   Updated: 2022/03/07 20:47:19 by lucisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	parse_data(int ac, char **av, t_data *data)
{
	data->nb_philos = ft_atoi(av[1]);
	if (data->nb_philos <= 0)
		return (error_exit(INVALID_N_PHILOS, -1));
	data->tt_die = ft_atoi(av[2]);
	data->tt_eat = ft_atoi(av[3]);
	data->tt_sleep = ft_atoi(av[4]);
	data->max_meals = -1;
	if (data->tt_die <= 0 || data->tt_eat <= 0 || data->tt_sleep <= 0)
		return (error_exit(INVALID_SPECS, -1));
	if (ac == 6)
	{
		data->max_meals = ft_atoi(av[5]);
		if (data->max_meals <= 0)
			return (error_exit(INVALID_SPECS, -1));
	}
	data->start_time = get_time();
	return (0);
}

int		init_philos(t_philo *ref_philo, t_data *data)
{
	t_philo		ref;

	// ref.last_ate = get_time();
	ref.nb_philos = data->nb_philos;
	ref.born_time = data->start_time;
	ref.remaining_meals = data->max_meals;
	ref.finished_eating = 0;
	// ref.data = data;
	*ref_philo = ref;
	return (0);
}

// void	copy_data(t_data **dest, t_data *src)
// {
// 	*dest = (t_data *)malloc(sizeof(t_data));
// 	(*dest)->max_meals = src->max_meals;
// 	(*dest)->nb_philos = src->nb_philos;
// 	(*dest)->tt_die = src->tt_die;
// 	(*dest)->tt_eat = src->tt_eat;
// 	(*dest)->tt_sleep = src->tt_eat;
// }

void	copy_philos(t_philo *dest, t_philo *src, int i)
{
	dest->id = i + 1;
	dest->nb_philos = src->nb_philos;
	dest->born_time = src->born_time;
	dest->last_ate = src->last_ate;
	dest->remaining_meals = src->remaining_meals;
	dest->finished_eating = src->finished_eating;
}

int		init(int ac, char **av, t_philo **p_philos, t_data *data)
{
	t_philo	ref;
	int		i;

	i = -1;
	if (ac != 5 && ac != 6)
		return (error_exit(ERROR_ARGS, -1));
	if (parse_data(ac, av, data) == -1)
		return (error_exit(PARSING_ERROR, -1));
	init_philos(&ref, data);
	*p_philos = (t_philo *)malloc(sizeof(t_philo) * (data->nb_philos + 1));
	if (!(*p_philos))
		error_exit(MALLOC_FAIL, -1);
	while (++i < data->nb_philos)
		copy_philos((*p_philos + i), &ref, i);
	return (0);
}