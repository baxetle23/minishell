/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenyse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 12:28:06 by mdenyse           #+#    #+#             */
/*   Updated: 2021/04/17 12:28:11 by mdenyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	res;
	int	znak;

	i = 0;
	res = 0;
	znak = 1;
	while ((str[i] == ' ') || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		znak = znak * -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
		res = res * 10 + (str[i++] - '0');
	return (res * znak);
}

double	ft_atod(const char *str)
{
	int		i;
	int		del;
	double	res;

	i = 0;
	del = 10;
	res = ft_atoi(str);
	while ((str[i] == ' ') || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] != '.' && str[i] != '\n')
		i++;
	while (ft_isdigit(str[++i]))
	{
		if (res < 0 || str[0] == '-')
			res = res - (double)(str[i] - '0') / del;
		else
			res = res + (double)(str[i] - '0') / del;
		del = del * 10;
	}
	return (res);
}
