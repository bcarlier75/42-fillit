/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarlier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 09:38:19 by bcarlier          #+#    #+#             */
/*   Updated: 2019/09/04 10:54:19 by bcarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static inline void	display_board(t_tetro *t, char letter,
		unsigned char const size)
{
	char		*board;
	uint32_t	y;
	uint32_t	x;

	board = ft_str_init(size * (size + 1), '.');
	while ((y = 0) || letter-- >= 'A')
	{
		while (y < t->height)
		{
			x = 0;
			while (x < t->width)
			{
				if ((t->value >> (16 * y + x)) & 1LL)
					board[(t->y + y) * (size + 1) + t->x + x] = t->letter;
				x++;
			}
			y++;
		}
		t++;
	}
	y = 0;
	while (y < size)
		board[y++ * (size + 1) + size] = '\n';
	ft_putstr(board);
	ft_strdel(&board);
}

static inline int	display_error(char const *str)
{
	ft_putendl(str);
	return (-1);
}

int					main(int argc, char **argv)
{
	int				fd;
	char			letter;
	t_tetro			*tetris;
	unsigned char	size;

	if (argc != 2)
		return (display_error("usage : ./fillit input_tetraminos"));
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (display_error("error"));
	if (!(tetris = (t_tetro *)malloc(sizeof(t_tetro) * 27)))
		return (display_error("error"));
	ft_bzero(tetris, sizeof(t_tetro) * 27);
	if (!(letter = read_input(fd, tetris)))
		return (display_error("error"));
	if (close(fd) == -1)
		return (display_error("error"));
	if (!(size = main_solving(tetris, letter)))
		return (display_error("error"));
	display_board(tetris, letter, size);
	ft_memdel((void **)&tetris);
	return (0);
}
