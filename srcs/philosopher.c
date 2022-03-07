#include "philosophers.h"

void	take_fork(t_philo philo, pthread_mutex_t *fork)
{
	pthread_mutex_lock(fork);
	print_status(philo, PHILO_FORK, 0);
}

void	philo_eat(t_philo philo, t_data data)
{
	print_status(philo, PHILO_EAT, 0);
	ft_usleep(data.tt_eat * 1000);
	pthread_mutex_unlock(philo.left_fork);
	pthread_mutex_unlock(philo.right_fork);
}

void	philo_sleep(t_philo philo, t_data data)
{
	print_status(philo, PHILO_SLEEP, 0);
	ft_usleep(data.tt_sleep * 1000);
}

void	philo_think(t_philo philo)
{
	print_status(philo, PHILO_THINK, 0);
}

void	*main_loop(void *p_info)
{
	t_info	info;
	t_philo	philo;
	t_info	*info2;
	t_philo	*p_philo;
	t_data	data;

	info = *(t_info *)p_info;
	philo = info.philo;
	data = info.data;
	info2 = (t_info *)p_info;
	p_philo = &(info2->philo);
	if (philo.id % 2 == 1)
	{
		usleep(1000 * (data.tt_eat / 2));
	}
	while (data.max_meals != 0)
	{
		take_fork(philo, philo.left_fork);
		take_fork(philo, philo.right_fork);
		p_philo->last_ate = get_time();
		philo_eat(philo, data);
		philo_sleep(philo, data);
		philo_think(philo);
		if (philo.remaining_meals > 0)
			philo.remaining_meals--;
	}
	p_philo->finished_eating = 1;
	return (0);
}
