/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucisanc <lucisanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 13:36:17 by lucisanc          #+#    #+#             */
/*   Updated: 2022/02/26 14:12:42 by lucisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include <stdbool.h>

# include <sys/time.h>
# include <pthread.h>

typedef struct	s_philo
{
	bool	has_fork;
	
}				t_philo;


/*
 *	utils.c
 */

int		ft_atoi(char *str);


/*
 *	ft_pthread
 */

int		ft_pthread(int ac, char **av);

#endif