/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_and_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarlier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 10:45:33 by bcarlier          #+#    #+#             */
/*   Updated: 2019/09/04 10:53:36 by bcarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static inline int		check_connect(char const *str)
{
	unsigned char	i;
	unsigned char	cconnect;

	i = 0;
	cconnect = 0;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			if (i - 1 >= 0 && str[i - 1] == '#')
				cconnect++;
			if (i + 1 < 20 && str[i + 1] == '#')
				cconnect++;
			if (i - 5 >= 0 && str[i - 5] == '#')
				cconnect++;
			if (i + 5 < 20 && str[i + 5] == '#')
				cconnect++;
		}
		i++;
	}
	return (cconnect == 6 || cconnect == 8);
}

static inline int		check_tetro(char const *str, int const count)
{
	unsigned char	i;
	unsigned char	sharp;

	sharp = 0;
	i = 0;
	while (i < 20)
	{
		if (i % 5 != 4)
		{
			if (str[i] == '#')
				sharp++;
			if (str[i] != '.' && str[i] != '#')
				return (0);
		}
		else if (str[i] != '\n')
			return (0);
		i++;
	}
	if (count == 21 && str[20] != '\n')
		return (0);
	if (sharp != 4 || check_connect(str) == 0)
		return (0);
	return ((count == 21) ? 1 : 2);
}

static inline void		find_area(char const *buff, unsigned char *area)
{
	unsigned char	i;

	i = 0;
	area[0] = 3;
	area[1] = 0;
	area[2] = 3;
	area[3] = 0;
	while (i < 20)
	{
		if (buff[i] == '#')
		{
			if (i % 5 < area[0])
				area[0] = i % 5;
			if (i % 5 > area[1])
				area[1] = i % 5;
			if (i / 5 < area[2])
				area[2] = i / 5;
			if (i / 5 > area[3])
				area[3] = i / 5;
		}
		i++;
	}
}

static inline t_tetro	*get_tetro(t_tetro *tetris2, char const *buff,
		char const letter)
{
	unsigned char	x;
	unsigned char	y;
	unsigned char	*area;

	if (!(area = (unsigned char *)malloc(sizeof(unsigned char) * 4)))
		return (NULL);
	find_area(buff, area);
	tetris2->letter = letter;
	tetris2->width = area[1] - area[0] + 1;
	tetris2->height = area[3] - area[2] + 1;
	tetris2->value = 0LL;
	y = 0;
	while (y < tetris2->height)
	{
		x = 0;
		while (x < tetris2->width)
		{
			if (buff[5 * (area[2] + y) + (area[0] + x)] == '#')
				tetris2->value |= 1LL << (16 * y + x);
			x++;
		}
		y++;
	}
	ft_memdel((void **)&area);
	return (tetris2);
}

char					read_input(int const fd, t_tetro *tetris1)
{
	char		currentl;
	char		buff[21];
	char		end;
	int			counter;

	currentl = 'A';
	while ((counter = (int)read(fd, buff, 21)) >= 20)
	{
		if (currentl - 'A' >= 26
				|| (end = check_tetro((char const *)buff, counter)) == 0)
			return (0);
		if (!(get_tetro(tetris1++, (char const *)buff,
						(char const)currentl)))
			return (0);
		currentl++;
	}
	if (counter != 0)
		return (0);
	else
		return ((currentl > 'A' && end == 2) ? currentl - 1 : 0);
}
