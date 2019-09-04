/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarlier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 10:15:48 by bcarlier          #+#    #+#             */
/*   Updated: 2019/09/04 10:55:18 by bcarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft.h"
# include <string.h>
# include <fcntl.h>

typedef struct		s_tetro
{
	char			letter;
	unsigned char	width;
	unsigned char	height;
	unsigned char	x;
	unsigned char	y;
	long long		value;
	struct s_tetro	*previous;
}					t_tetro;

/*
** 
*/

unsigned char		main_solving(t_tetro *tetris, char const letter);
char				read_input(int const fd, t_tetro *tetris);

#endif
