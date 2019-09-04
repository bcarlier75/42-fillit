/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarlier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 12:44:16 by bcarlier          #+#    #+#             */
/*   Updated: 2018/12/14 14:40:55 by bcarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char			*dsttemp;
	const	char	*srctemp;
	char			*ptr;
	size_t			i;

	dsttemp = (char *)dst;
	srctemp = (char *)src;
	ptr = 0;
	i = 0;
	while (i < n && ptr == 0)
	{
		dsttemp[i] = srctemp[i];
		if (srctemp[i] == ((char)c))
			ptr = dsttemp + i + 1;
		i++;
	}
	return (ptr);
}
