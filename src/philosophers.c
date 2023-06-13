/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharkush <vharkush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 10:43:53 by vharkush          #+#    #+#             */
/*   Updated: 2023/06/13 20:02:56 by vharkush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

int	main(int ac, char **av)
{
	t_input	input;

	if (av[5] && ft_atol(av[5]) == 0)
		return (0);
	if (ft_input(&input, ac, av))
		return (1);
	return (0);
}
