/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 21:26:04 by pdoherty          #+#    #+#             */
/*   Updated: 2018/12/05 11:16:38 by pdoherty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		free_structs(t_map *map, t_piece *piece, t_coords *coords)
{
	if (map)
		free_t_map(map);
	if (piece)
		free_t_piece(piece);
	if (coords)
		free(coords);
}
