/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarlier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 12:49:12 by bcarlier          #+#    #+#             */
/*   Updated: 2018/12/14 14:40:42 by bcarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char *mem;
	char *temp;

	if (!(mem = (char *)malloc(size)))
		return (0);
	temp = mem;
	while (size--)
		*temp++ = '\0';
	return (mem);
}
