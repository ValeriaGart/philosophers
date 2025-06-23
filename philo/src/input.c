/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharkush <vharkush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 10:45:04 by vharkush          #+#    #+#             */
/*   Updated: 2023/06/10 12:00:36 by vharkush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

void	ft_store_input_num(int cur, t_input *input, long num)
{
	switch (cur) {
		case 0: input->philos = (int)num; break;
		case 1: input->die = (int)num; break;
		case 2: input->eat = (int)num; break;
		case 3: input->sleep = (int)num; break;
		case 4: input->opt_n_eat = (int)num; break;
	}
}

int	ft_store_input(t_input *input, int ac, char **av, int cur)
{
	long	num;

	if (cur == ac - 1)
		return (0);
	num = ft_atol(av[cur + 1]);
	if (num > 2147483647)
		return (write(2, "Error\nOne of input nums overflows\n", 34));
	ft_store_input_num(cur, input, num);
	return (ft_store_input(input, ac, av, cur + 1));
}

int	ft_rdigits(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	while(++i < ac)
	{
		j = -1;
		if (!av[i][j + 1])
			return (write(2, "Error\nFound empty arg\n", 22));
		while (av[i][++j])
		{
			if (!ft_strchr("0123456789", av[i][j]))
				return (write(2, "Error\nWrong input\n", 18));
		}
	}
	return (0);
}

int	ft_input(t_input *input, int ac, char **av)
{
	if (ac != 5 && ac != 6)
		return (write(2, "Error\nWrong amount of args\n", 27));
	if (ac == 5)
		input->opt_n_eat = -1;
	if (ft_rdigits(ac, av))
		return (1);
	if (ft_store_input(input, ac, av, 0))
		return (1);
	return (0);
}
