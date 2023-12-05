/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharkush <vharkush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 10:43:53 by vharkush          #+#    #+#             */
/*   Updated: 2023/12/05 23:45:25 by vharkush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

/*
	Here I first of all check if times_to_eat or time_to_die is set to 0.
	Sending to checking input function and catching the error if it occures
	Sending to the main process, catching error if occures
	Exit accordingly
*/
int	main(int ac, char **av)
{
	t_input	input;

	if ((av[5] && ft_atol(av[5]) == 0) || ft_atol(av[1]) == 0)
		return (0);
	if (ft_input(&input, ac, av))
		return (1);
	if (ft_create(&input))
		return (1);
	return (0);
}
