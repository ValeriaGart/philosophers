/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharkush <vharkush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 11:33:04 by vharkush          #+#    #+#             */
/*   Updated: 2023/06/30 13:01:15 by vharkush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

int	ft_dead(int daytime, t_philo *philo)
{
	if (daytime - philo->last_ate >= philo->input->die)
	{
		printf("%ld %d died\n", ft_time_of_day, philo->philo_ind);
		return (1);
	}
	return (0);
}

int	ft_eat(t_philo *philo)
{
	int	start_eating;

	start_eating = ft_time_of_day();
	printf("%ld %d is eating\n", start_eating, philo->philo_ind);
	while (1)
	{
		if (ft_dead)
			return (1);
		if (ft_time_of_day - start_eating >= philo->input->eat)
			break;
	}
	return (0);
}

int ft_sleep(t_philo *philo)
{
	long	start_sleeping;

	start_sleeping = ft_time_of_day();
	printf("%ld %d is sleeping\n", start_sleeping, philo->philo_ind);
	while (1)
	{
		if (ft_dead)
			return (1);
		if (ft_time_of_day - start_sleeping >= philo->input->sleep)
			break;
	}
	return (0);
}

void	*routine(void *param)
{
	t_philo	*philo;

	if (!param)
		return (NULL);
	philo = (t_philo *)param;
	philo->last_ate = ft_time_of_day();
	if (philo->philo_ind % 2)
		usleep(5);
	while (1)
	{
		if (ft_dead(ft_time_of_day(), philo))
			return (1);
		if (philo->my_turn)
		{
			if (ft_eat(philo))
				return (1);
			philo->last_ate = ft_time_of_day();
			if (ft_sleep(philo))
				return (1);
			printf("%ld %d is thinking\n", ft_time_of_day, philo->philo_ind);
		}
	}
	return (NULL);
}

int	ft_create(t_input *input)
{
	int	i;

	i = -1;
	input->err = 0;
	input->philo = malloc(input->philos * sizeof(t_philo));
	if (!input->philo)
		return (write(2, "Error\nMalloc failed\n", 20));
	input->philo->input = input;
	input->start = ft_time_of_day();
	while (++i < input->philos)
	{
		input->philo->philo_ind = i;
		if (pthread_mutex_init(&input->philo[i].my_turn_m, NULL))
		{
			//destroy mutexes
			input->philos = i;
			input->err++;
			break ;
		}
		if(pthread_create(&input->philo[i].phi, NULL, &routine, &(input->philo[i])))
		{
			//destroy mutexes
			input->philos = i;
			input->err++;
			break ;
		}
	}
	i = -1;
	while (++i < input->philos)
		pthread_join(input->philo[i].phi, NULL);
	free (input->philo);
	if (input->err)
		return (write(2, "Error\nPthrerad creating failed\n", 31));
	return (0);
}
