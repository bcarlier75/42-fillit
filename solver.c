/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarlier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 09:56:11 by bcarlier          #+#    #+#             */
/*   Updated: 2019/09/27 14:15:28 by bcarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static inline void	connect(t_tetro *tetris)
{
	unsigned char	i;
	unsigned char	j;

	i = 0;
	while ((tetris[i]).letter != 0)
	{
		tetris[i].previous = NULL;
		j = i;
		while (j - 1 >= 0)
		{
			j--;
			if ((tetris[j].value ^ tetris[i].value) == 0LL)
			{
				tetris[i].previous = &(tetris[j]);
				j = 0;
			}
		}
		i++;
	}
}

static inline void	starting_point(t_tetro *tetris)
{
	if (tetris->previous == NULL)
	{
		tetris->x = 0;
		tetris->y = 0;
	}
	else
	{
		tetris->x = tetris->previous->x + tetris->width - 1;
		tetris->y = tetris->previous->y;
	}
}

static inline int	solve_board(t_tetro *tetris, unsigned char const size,
		int16_t *board)
{
	if (tetris->letter == 0)
		return (1);
	starting_point(tetris);
	while (tetris->y + tetris->height <= size)
	{
		while (tetris->x + tetris->width <= size)
		{
			if (!(*(int64_t *)(board + tetris->y) & tetris->value << tetris->x))
			{
				*(int64_t *)(board + tetris->y) ^= tetris->value << tetris->x;
				if (solve_board(tetris + 1, size, board) == 1)
					return (1);
				*(int64_t *)(board + tetris->y) ^= tetris->value << tetris->x;
			}
			(tetris->x)++;
		}
		tetris->x = 0;
		(tetris->y)++;
	}
	return (0);
}

static inline int	save_and_retry(t_tetro *tetris, t_tetro *current,
		char letter)
{
	while (letter-- >= 'A')
	{
		current->x = tetris->x;
		current->y = tetris->y;
		tetris->x = 0;
		tetris->y = 0;
		current->width = tetris->width;
		current->height = tetris->height;
		current->letter = tetris->letter;
		current++;
		tetris++;
	}
	return (0);
}

unsigned char		main_solving(t_tetro *tetris, char const letter)
{
	unsigned char	size;
	int16_t			*board;
	t_tetro			*current;

	size = 13;
	if (!(current = (t_tetro *)malloc(sizeof(t_tetro) * (letter - 'A' + 1))))
		return (0);
	if (!(board = (int16_t *)malloc(sizeof(int16_t) * 16)))
		return (0);
	ft_bzero(board, sizeof(int16_t) * 16);
	connect(tetris);
	while (size * size >= ((letter + 1 - 'A') * 4) && solve_board(tetris,
				size, board) == 1)
	{
		size--;
		ft_bzero(board, sizeof(int16_t) * 16);
		save_and_retry(tetris, current, letter);
	}
	save_and_retry(current, tetris, letter);
	ft_memdel((void **)&board);
	ft_memdel((void **)&current);
	return (size + 1);
}
