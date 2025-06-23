/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharkush <vharkush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 10:42:54 by vharkush          #+#    #+#             */
/*   Updated: 2023/06/30 13:02:40 by vharkush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <stdio.h>
# include <stdbool.h>

typedef struct s_philo
{
	bool			my_turn;
	int				last_ate;
	int				philo_ind;
	pthread_t		phi;
	struct s_input	*input;
	pthread_mutex_t	my_turn_m;
}		t_philo;

typedef struct s_input
{
	pthread_mutex_t	print;
	long long	start;
	int			philos;
	int			die;
	int			eat;
	int			sleep;
	int			opt_n_eat;
	int			err;
	t_philo		*philo;
}		t_input;

int			ft_input(t_input *input, int ac, char **av);
int			ft_create(t_input *input);
long long	ft_time_of_day(void);
long		ft_atol(char *str);
char		*ft_strchr(const char *s, int c);

#endif
