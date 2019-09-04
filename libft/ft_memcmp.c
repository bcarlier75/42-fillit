/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarlier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 16:01:11 by bcarlier          #+#    #+#             */
/*   Updated: 2018/12/14 14:41:21 by bcarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*s1temp;
	const unsigned char	*s2temp;
	size_t				i;

	s1temp = s1;
	s2temp = s2;
	i = 0;
	while (i < n)
	{
		if (*s1temp != *s2temp)
			return (*s1temp - *s2temp);
		else
		{
			s1temp++;
			s2temp++;
			i++;
		}
	}
	return (0);
}
