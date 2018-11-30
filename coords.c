/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coords.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 14:58:45 by pdoherty          #+#    #+#             */
/*   Updated: 2018/11/30 13:32:33 by pdoherty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_coords	*get_coords(t_map *map, t_piece *piece)
{
	t_coords	*tr;

	tr = (t_coords *)malloc(sizeof(t_coords));
	tr->y = 0;
	tr->x = 0;

}
