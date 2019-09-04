/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarlier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 11:55:35 by bcarlier          #+#    #+#             */
/*   Updated: 2018/12/14 14:41:34 by bcarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*dsttemp;
	const char	*srctemp;
	size_t		i;

	i = 0;
	dsttemp = dst;
	srctemp = src;
	while (i < n)
	{
		dsttemp[i] = srctemp[i];
		i++;
	}
	return (dst);
}
