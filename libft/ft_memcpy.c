/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenyse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 13:29:34 by mdenyse           #+#    #+#             */
/*   Updated: 2021/04/17 13:29:36 by mdenyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*d;

	if (dst == NULL && src == NULL)
		return (0);
	if (dst == src)
		return (dst);
	i = 0;
	d = dst;
	while (i < n)
	{
		d[i] = *((unsigned char *)(src + i));
		i++;
	}
	return (dst);
}
