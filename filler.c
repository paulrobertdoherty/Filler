/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 20:46:52 by pdoherty          #+#    #+#             */
/*   Updated: 2018/12/12 21:38:06 by pdoherty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static t_map	*get_map(void)
{
	char	*line;
	t_map	*tr;
	int		i;

	tr = new_t_map();
	i = 0;
	while (i < tr->height)
	{
		get_next_line(0, &line);
		tr->map[i] = ft_strdup(&ft_strchr(line, ' ')[1]);
		free(line);
		i++;
	}
	return (tr);
}

static t_piece	*get_piece(void)
{
	char	*line;
	t_piece	*tr;
	int		i;

	tr = new_t_piece();
	i = 0;
	while (i < tr->height)
	{
		get_next_line(0, &line);
		tr->piece[i] = line;
		i++;
	}
	return (tr);
}

static void		print_coords(t_coords *coords)
{
	ft_putnbr(coords->y);
	ft_putchar(' ');
	ft_putnbr(coords->x);
	ft_putchar('\n');
}

static int		get_player_number(void)
{
	int		player;
	char	*line;

	get_next_line(0, &line);
	player = ft_atoi(&line[10]) - 1;
	free(line);
	return (player);
}

int				main(void)
{
	t_map		*map;
	t_piece		*piece;
	t_coords	*coords;
	int			player;

	player = get_player_number();
	map = NULL;
	piece = NULL;
	coords = NULL;
	while (1)
	{
		free_structs(map, piece, coords);
		map = get_map();
		piece = get_piece();
		coords = get_coords(map, piece, player);
		print_coords(coords);
		if (!coords->x && !coords->y)
			break ;
	}
	free_structs(map, piece, coords);
	return (0);
}
