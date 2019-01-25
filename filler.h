/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 16:37:00 by pdoherty          #+#    #+#             */
/*   Updated: 2018/12/13 22:09:08 by pdoherty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft/libft.h"
# include "filler_types.h"

#include <stdio.h>

char		get_player(int player);
char		to_lower_case(char c);
t_coords	*get_coords(t_map *map, t_piece *piece, int player);
t_map		*new_t_map(void);
void		free_t_map(t_map *map);
void		free_t_piece(t_piece *piece);
t_piece		*new_t_piece(void);
void		free_structs(t_map *map, t_piece *piece, t_coords *coords);
t_score		*get_score(t_coords *c, t_map *map, t_piece *piece, int player); 
void		add_to_spots(t_list **spots, t_score *ta);
t_coords	*find_best_spot(t_list **spot);

#endif
