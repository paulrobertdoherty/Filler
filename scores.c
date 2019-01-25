/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scores.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 22:11:45 by pdoherty          #+#    #+#             */
/*   Updated: 2018/12/14 16:43:43 by pdoherty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static float	sqrt_squared(int x)
{
	float	s;
	float	m;
	float	mm;
	float	e;

	s = 0;
	m = x / 2.0;
	e = x;
	while (e - s > PRECISION)
	{
		m = (s + e) / 2.0;
		mm = m * m;
		if (mm > x)
			e = m;
		else if (mm < x)
			s = m;
		else
			return (m);
	}
	return (m * m);
}

static int		squared(int x)
{
	return (x * x);
}

static float	get_for_pieces(t_coords *i, t_piece *p, t_coords *c)
{
	float	tr;
	int		y;
	int		x;

	tr = 0;
	y = 0;
	while (y < p->height)
	{
		x = 0;
		while (x < p->width)
		{
			if (p->piece[y][x] == '*')
			{
				tr += 2158487.0 / sqrt_squared(squared(i->y - (y + c->y)) +
						squared(i->x - (x + c->x)));
			}
			x++;
		}
		y++;
	}
	return (tr);
}

static int		is_opponent_edge(t_map *map, t_coords *i, char ou, char ol)
{
	int		y;
	int		x;
	char	c;

	if (map->map[i->y][i->x] != ou && map->map[i->y][i->x] != ol)
		return (0);
	y = i->y - 1;
	while (y <= i->y + 1)
	{
		x = i->x - 1;
		while (x <= i->x + 1)
		{
			if (y >= 0 && y < map->height && x > 0 && x < map->width &&
				!(x == i->x && y == i->y))
			{
				c = map->map[y][x];
				if (c != ou && c != ol)
					return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

t_score			*get_score(t_coords *c, t_map *map, t_piece *piece,
				int player)
{
	t_coords	*i;
	t_score		*tr;
	char		ou;
	char		ol;

	tr = (t_score *)malloc(sizeof(t_score));
	i = (t_coords *)ft_memcpy(malloc(sizeof(c)), c, sizeof(c));
	tr->score = 0;
	tr->spot = (t_coords *)ft_memcpy(malloc(sizeof(c)), c, sizeof(c));
	ou = get_player(!player);
	ol = to_lower_case(ou);
	i->y = 0;
	while (i->y < map->height)
	{
		i->x = 0;
		while (i->x < map->width)
		{
			if (is_opponent_edge(map, i, ou, ol))
				tr->score += get_for_pieces(i, piece, c);
			(i->x)++;
		}
		(i->y)++;
	}
	free(i);
	return (tr);
}
