#include "philosophers.h"

void    parse_philos(int ac, char **av, t_philo *philos)
{
    philos->death_time = ft_atoi(av[2]);
    philos->eat_time = ft_atoi(av[3]);
    philos->sleep_time = ft_atoi(av[4]);
    if (ac == 6)
        philos->remaining_meals = ft_atoi(av[5]);
    if (philos->death_time <= 0 || philos->eat_time <= 0 || philos->sleep_time <= 0)
        error_exit(INVALID_TIME_SPEC, -1);
    // philos->born_time = get_time();
}

void    copy_philos(t_philo dest, t_philo src, int i)
{
    dest.id = i + 1;
}

int     parse_args(int ac, char **av, t_philo **p_philos)
{
    t_philo *philos;
    int     n_philos;
    int     i;

    i = 0;
    if (ac != 5 && ac != 6)
        error_exit(ERROR_ARGS, -1);
    n_philos = av[1];
    if (n_philos <= 0)
        error_exit(INVALID_N_PHILOS, -1);
    if (n_philos == 1)
        ft_putstr_fd(PHILO_DIED + '\n', 1);
    parse_philos(ac, av, philos);
    printf("%d\n", philos->death_time);
    philos = (t_philo *)malloc(sizeof(t_philo) * (n_philos + 1));
    if (!philos)
        error_exit(MALLOC_FAIL, -1);
    // while (i < n_philos)
        // copy_philos(&(philos[i]), philos, i);
}