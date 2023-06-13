/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharkush <vharkush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 10:42:54 by vharkush          #+#    #+#             */
/*   Updated: 2023/06/10 11:33:28 by vharkush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>


typedef struct s_input
{
	int		philos;
	int		die;
	int		eat;
	int		sleep;
	int		opt_n_eat;
}		t_input;

int		ft_input(t_input *input, int ac, char **av);
long	ft_atol(char *str);
char	*ft_strchr(const char *s, int c);

#endif
