/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenyse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 10:28:24 by mdenyse           #+#    #+#             */
/*   Updated: 2021/04/18 10:28:25 by mdenyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_count(long n)
{
	int	count;

	count = 1;
	if (n > 0)
	{
		while (n > 9)
		{
			count++;
			n = n / 10;
		}
	}
	else
	{
		while (n < -9)
		{
			count++;
			n = n / 10;
		}
	}
	return (count);
}

void	ft_putnbr_fd(long n, int fd)
{
	int		i;
	int		count;
	long	del;

	if (n < 0)
		ft_putchar_fd('-', fd);
	i = 1;
	del = 1;
	count = ft_get_count(n);
	while (i++ < count)
		del = del * 10;
	i = 0;
	while (i < count)
	{
		if (n > 0)
			ft_putchar_fd(n / del + '0', fd);
		else
			ft_putchar_fd(n / del * -1 + '0', fd);
		n = n % del;
		del = del / 10;
		i++;
	}
}
