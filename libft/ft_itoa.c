/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenyse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 10:26:53 by mdenyse           #+#    #+#             */
/*   Updated: 2021/04/18 10:26:54 by mdenyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_count(int n)
{
	int	count;

	count = 1;
	if (n < 0)
		count++;
	while (n < -9 || n > 9)
	{
		count++;
		n = n / 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*num;
	int		count;
	int		znak;

	znak = n;
	count = ft_get_count(n);
	num = (char *)malloc(sizeof(char) * (count + 1));
	if (!num)
		return (0);
	num[count] = '\0';
	while (count-- > 1)
	{
		if (n < 0)
			num[count] = (n % 10) * -1 + '0';
		else
			num[count] = n % 10 + '0';
		n = n / 10;
	}
	if (znak < 0)
		num[0] = '-';
	else
		num[0] = n % 10 + '0';
	return (num);
}
