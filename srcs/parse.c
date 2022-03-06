#include "philosophers.h"

int	parse_philos(int ac, char **av, t_philo *ref_philo)
{
	t_philo	ref;

	ref.to_die = ft_atoi(av[2]);
	ref.to_eat = ft_atoi(av[3]);
	ref.to_sleep = ft_atoi(av[4]);
	ref.last_ate = get_time();
	ref.born_time = ref.last_ate;
	ref.finished_eating = 0;
	ref.n_of_meals = -1;
	if (ref.to_die <= 0 || ref.to_eat <= 0 || ref.to_sleep <= 0 || ref.last_ate <=0)
		return (error_exit(INVALID_TIME_SPEC, -1));
	if (ac == 6)
	{
		ref.n_of_meals = ft_atoi(av[5]);
		if (ref.n_of_meals < 0)
			ref.n_of_meals = 0;
	}
	*ref_philo = ref;
	return (0);
}

void	copy_philos(t_philo *dest, t_philo *src, int i)
{
	dest->id = i + 1;
	dest->to_die = src->to_die;
	dest->to_eat = src->to_eat;
	dest->to_sleep = src->to_sleep;
	dest->last_ate = src->last_ate;
	dest->born_time = src->born_time;
	dest->finished_eating = src->finished_eating;
}

int		parse_args(int ac, char **av, t_philo **p_philos)
{
	t_philo	ref;
	int		amount;
	int		i;

	i = -1;
	if (ac != 5 && ac != 6)
		return (error_exit(ERROR_ARGS, -1));
	amount = ft_atoi(av[1]);
	if (amount <= 0)
		return (error_exit(INVALID_N_PHILOS, -1));
	if (parse_philos(ac, av, &ref) == -1)
		return (error_exit(PARSING_ERROR, -1));
	*p_philos = (t_philo *)malloc(sizeof(t_philo) * (amount + 1));
	if (!(*p_philos))
		error_exit(MALLOC_FAIL, -1);
	while (++i < amount)
		copy_philos((*p_philos + i), &ref, i);
	return (amount);
}