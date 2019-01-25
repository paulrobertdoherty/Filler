/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_map.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 11:35:02 by pdoherty          #+#    #+#             */
/*   Updated: 2018/12/08 16:23:34 by pdoherty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	free_t_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		free(map->map[i]);
		i++;
	}
	free(map->map);
	free(map);
}

t_map	*new_t_map(void)
{
	t_map	*tr;
	char	*line;
	char	**split;
	char	**map;

	tr = (t_map *)malloc(sizeof(t_map));
	get_next_line(0, &line);
	split = ft_strsplit(line, ' ');
	free(line);
	get_next_line(0, &line);
	free(line);
	tr->height = ft_atoi(split[1]);
	tr->width = ft_atoi(split[2]);
	free(split[0]);
	free(split[1]);
	free(split[2]);
	free(split);
	map = (char **)malloc(sizeof(char *) * (tr->height + 1));
	map[tr->height] = NULL;
	tr->map = map;
	return (tr);
}
