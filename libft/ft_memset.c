/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarlier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 11:57:17 by bcarlier          #+#    #+#             */
/*   Updated: 2018/12/14 14:42:02 by bcarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memset(void *b, int c, size_t n)
{
	size_t			i;
	char			*btemp;
	unsigned char	ctemp;

	ctemp = c;
	btemp = b;
	i = 0;
	while (i < n)
	{
		btemp[i] = ctemp;
		i++;
	}
	return (b);
}
