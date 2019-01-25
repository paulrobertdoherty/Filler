/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coords.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 14:58:45 by pdoherty          #+#    #+#             */
/*   Updated: 2018/12/13 22:26:02 by pdoherty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char		to_lower_case(char c)
{
	if (c == 'X')
		return 'x';
	return 'o';
}

static int	is_valid_position(t_coords *coords, t_map *map, t_piece *piece,
			char p)
{
	int		c;
	int		x;
	int		y;
	int		v;
	char	lp;

	lp = to_lower_case(p);
	c = 0;
	x = coords->x;
	y = coords->y;
	while (y < piece->height + coords->y)
	{
		x = coords->x;
		while (x < piece->width + coords->x)
		{
			v = y >= map->height || x >= map->width;
			if ((v || map->map[y][x] != '.') &&
				piece->piece[y - coords->y][x - coords->x] == '*')
			{
				if (v || !(map->map[y][x] == p || map->map[y][x] == lp))
					return (0);
				else
					c++;
			}
			x++;
		}
		y++;
	}
	return (c == 1);
}

char		get_player(int player)
{
	if (player)
		return ('X');
	return ('O');
}

t_coords	*get_coords(t_map *map, t_piece *piece, int player)
{
	t_list		*spots;
	t_coords	*c;
	char		p;

	p = get_player(player);
	spots = NULL;
	c = (t_coords *)malloc(sizeof(t_coords));
	c->y = 0;
	while (c->y < map->height)
	{
		c->x = 0;
		while (c->x < map->width)
		{
			if (is_valid_position(c, map, piece, p))
				add_to_spots(&spots, get_score(c, map, piece, player));
			(c->x)++;
		}
		(c->y)++;
	}
	free(c);
	return (find_best_spot(&spots));
}
