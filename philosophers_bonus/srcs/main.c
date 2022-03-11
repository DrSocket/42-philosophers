/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucisanc <lucisanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 13:36:14 by lucisanc          #+#    #+#             */
/*   Updated: 2022/03/11 18:15:03 by lucisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

sem_t	*ft_seminit(char *str, int nb)
{
	sem_unlink(str);
	return (sem_open(str, O_CREAT | O_EXCL, 0644, nb));
}

static int	init_threads(t_philo *philos, sem_t **forks)
{
	int				i;
	int				amount;
	pthread_t		th;

	amount = philos->nb_philos;
	i = -1;
	while (++i < amount)
	{
		philos[i].fork = *forks;
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
	sem_t		*forks;

	if (parse(ac, av, &philos) == -1)
		return (1);
	forks = ft_seminit("forks", philos->nb_philos);
	philos->print = ft_seminit("print", 1);
	if (init_threads(philos, &forks) == -1)
		return (1);
	check_alive(philos);
	free(philos);
	return (0);
}
