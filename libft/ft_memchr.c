/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarlier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:26:33 by bcarlier          #+#    #+#             */
/*   Updated: 2018/12/14 15:49:06 by bcarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *use_s;

	use_s = (unsigned char*)s;
	while (n--)
	{
		if (*use_s != (unsigned char)c)
			use_s++;
		else
			return (use_s);
	}
	return (NULL);
}
