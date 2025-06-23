/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharkush <vharkush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 11:33:04 by vharkush          #+#    #+#             */
/*   Updated: 2023/07/01 11:55:10 by vharkush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

int	ft_dead(int daytime, t_philo *philo)
{
	if (daytime - philo->last_ate >= philo->input->die)
	{
		printf("%lld %d died\n", ft_time_of_day(), philo->philo_ind);
		return (1);
	}
	return (0);
}

int	ft_eat(t_philo *philo)
{
	long long	start_eating;

	start_eating = ft_time_of_day();
	printf("%lld %d is eating\n", start_eating, philo->philo_ind);
	while (1)
	{
		if (ft_dead(ft_time_of_day(), philo))
			return (1);
		if (ft_time_of_day() - start_eating >= philo->input->eat)
			break;
	}
	return (0);
}

int ft_sleep(t_philo *philo)
{
	long long	start_sleeping;

	start_sleeping = ft_time_of_day();
	printf("%lld %d is sleeping\n", start_sleeping, philo->philo_ind);
	while (1)
	{
		if (ft_dead(ft_time_of_day(), philo))
			return (1);
		if (ft_time_of_day() - start_sleeping >= philo->input->sleep)
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
			return (NULL);
		if (philo->my_turn)
		{
			if (ft_eat(philo))
				return (NULL);
			philo->last_ate = ft_time_of_day();
			if (ft_sleep(philo))
				return (NULL);
			printf("%lld %d is thinking\n", ft_time_of_day(), philo->philo_ind);
		}
	}
	return (NULL);
}

int	ft_create(t_input *input)
{
	int	i;

	i = -1;
	input->err = 0;
	printf("DEBUG: input->philos = %d\n", input->philos);
	input->philo = malloc(input->philos * sizeof(t_philo));
	if (!input->philo)
		return (write(2, "Error\nMalloc failed\n", 20));
	input->start = ft_time_of_day();
	if (pthread_mutex_init(&input->print, NULL))
		input->err = 2;
	while ((++i < input->philos) && !input->err)
	{
		input->philo[i].input = input;
		input->philo[i].philo_ind = i;
		if (pthread_mutex_init(&input->philo[i].my_turn_m, NULL))
		{
			input->err = 1;
			break ;
		}
		if(pthread_create(&input->philo[i].phi, NULL, &routine, &(input->philo[i])))
		{
			input->err= 1;
			break ;
		}
	}
	if (input->err)
		input->philos = i;
	i = -1;
	while (++i < input->philos)
	{
		pthread_join(input->philo[i].phi, NULL);
		pthread_mutex_destroy(&input->philo[i].my_turn_m);
	}
	if (input->err != 2)
		pthread_mutex_destroy(&input->print);
	free (input->philo);
	if (input->err)
		return (write(2, "Error\nPthrerad or mutex creating failed\n", 40));
	return (0);
}
