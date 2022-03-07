/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucisanc <lucisanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:02:03 by lucisanc          #+#    #+#             */
/*   Updated: 2022/03/07 20:27:12 by lucisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_putstr_fd(char *str, int fd)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	write(fd, str, len);
}

int	error_exit(char *msg, int exit_code)
{
	ft_putstr_fd("Error: ", STDERR_FILENO);
	ft_putstr_fd(msg, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	return (exit_code);
}

void	print_status(t_philo philo, char *msg, int death)
{
	static int	has_died = 0;

	if (death)
		has_died = death;
	pthread_mutex_lock(philo.printer);
	if (death || !has_died)
		printf("%-7ld %-2d %s\n",
			get_time() - philo.born_time, philo.id, msg);
	pthread_mutex_unlock(philo.printer);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	if (!str)
		return (len);
	while (str[len])
		len++;
	return (len);
}

time_t	get_time(void)
{
	static struct timeval	tv;

	if (gettimeofday(&tv, NULL) == -1)
		error_exit(GET_TIME_FAIL, -1);
	return ((tv.tv_sec * (time_t)1000) + (tv.tv_usec / 1000));
}

int	ft_atoi(char *str)
{
	int	sign;
	int	ret;

	ret = 0;
	sign = 1;
	while (((*str) >= 9 && (*str) <= 13) || (*str) == ' ')
		str++;
	if ((*str) == '-' || (*str) == '+')
	{
		if ((*str) == '-')
			sign *= -1;
		str++;
	}
	while ((*str) >= '0' && (*str) <= '9')
	{
		ret = (ret * 10) + ((*str) - '0');
		str++;
	}
	return (ret * sign);
}