/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucisanc <lucisanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:02:03 by lucisanc          #+#    #+#             */
/*   Updated: 2022/03/08 20:12:40 by lucisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// int	tern(int condition, int yes, int no)
// {
// 	if (condition)
// 		return (yes);
// 	else
// 		return (no);
// }

// void	ft_usleep(useconds_t time_val)
// {
// 	time_t		start_time;
// 	useconds_t	to_wait;
// 	useconds_t	sleep_val;

// 	start_time = get_time();
// 	to_wait = (start_time * 1000 + time_val) - get_time() * 1000;
// 	sleep_val = tern(to_wait > 500, 500, to_wait);
// 	while (to_wait > 0)
// 	{
// 		usleep(sleep_val);
// 		to_wait = (start_time * 1000 + time_val) - get_time() * 1000;
// 		sleep_val = tern(to_wait > 500, 500, to_wait);
// 	}
// }

void	ft_usleep(useconds_t time_val)
{
	time_t		start_time;
	useconds_t	to_wait;
	useconds_t	sleep_val;

	start_time = get_time();
	to_wait = (start_time * 1000 + time_val) - get_time() * 1000;
	if (to_wait > 500)
		sleep_val = 500;
	else
		sleep_val = to_wait;
	while (to_wait > 0)
	{
		usleep(sleep_val);
		to_wait = (start_time * 1000 + time_val) - get_time() * 1000;
		if (to_wait > 500)
			sleep_val = 500;
		else
			sleep_val = to_wait;
	}
}

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

// void	print_status(t_philo philo, char *msg, int death)
// {
// 	static int	has_died = 0;

// 	if (death)
// 		has_died = death;
// 	pthread_mutex_lock(philo.print);
// 	if (death || !has_died)
// 		printf("%-7ld %-2d %s\n",
// 			get_time() - philo.start_time, philo.id, msg);
// 	pthread_mutex_unlock(philo.print);
// }

void	print_status(t_philo philo, char *msg, int death)
{
	static int	has_died = 0;

	if (death)
		has_died = death;
	pthread_mutex_lock(philo.print);
	if (death || !has_died)
		printf("%-7ld %-2d %s\n",
			get_time() - philo.start_time, philo.id, msg);
	pthread_mutex_unlock(philo.print);
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

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * (time_t)1000) + (tv.tv_usec / 1000));
}

int	ft_atoi(const char *str)
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