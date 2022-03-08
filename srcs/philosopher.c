#include "philosophers.h"

void	take_fork(t_philo philo, pthread_mutex_t fork)
{
	pthread_mutex_lock(&fork);
	print_status(philo, PHILO_FORK, 0);
}

void	philo_eat(t_philo philo, pthread_mutex_t fork)
{
	print_status(philo, PHILO_EAT, 0);
	ft_usleep(philo.tt_eat * 1000);
	pthread_mutex_unlock(&fork);
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
	t_philo ref2;


	ref = (t_philo *)p_philo;
	ref2 = *(t_philo *)p_philo;
// printf("HELLO \tphilo: %d\n", ref2.id);
	while (ref->max_meals != 0)
	{
// printf("1\tphilo: %d rem meals: %d\n", ref->id, ref->remaining_meals);
		take_fork(*ref, *ref->left_fork);
		take_fork(*ref, *ref->right_fork);
		ref->last_ate = get_time();
		philo_eat(*ref, *ref->left_fork);
		philo_eat(*ref, *ref->right_fork);
		philo_sleep(*ref);
		philo_think(*ref);
		if (ref->remaining_meals > 0)
			ref->remaining_meals--;
		else
			break;
	}
	ref->finished_eating = 1;
	return ((void *)ref);
}
