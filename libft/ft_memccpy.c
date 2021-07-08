/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenyse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 14:11:44 by mdenyse           #+#    #+#             */
/*   Updated: 2021/04/17 14:11:45 by mdenyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*d;

	i = 0;
	d = dst;
	while (i < n)
	{
		d[i] = *((unsigned char *)(src + i));
		if (d[i] == (unsigned char)c)
			return (dst + i + 1);
		i++;
	}
	return (0);
}
