/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharkush <vharkush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 11:04:38 by vharkush          #+#    #+#             */
/*   Updated: 2023/06/10 12:01:54 by vharkush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

int	ft_isdigit(int a)
{
	if (a <= '9' && a >= '0')
		return (1);
	return (0);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*res;

	i = 0;
	if (!s)
		return (NULL);
	res = (char *)s;
	while (res[i])
	{
		if (res[i] == (unsigned char)c)
			return (res + i);
		i++;
	}
	if ((unsigned char)c == '\0')
		return (res + i);
	return (NULL);
}

long	ft_atol(char *str)
{
	int		i;
	int		sign;
	long	my_long;

	i = 0;
	my_long = 0;
	sign = 0;
	if (!str)
		return (0);
	while (str[i] == ' ')
		i++;
	if (str[i] == '-')
		sign++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
	{
		my_long = my_long * 10 + str[i] - '0';
		i++;
	}
	if (sign)
		my_long *= -1;
	return (my_long);
}
