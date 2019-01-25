/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_types.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 16:34:16 by pdoherty          #+#    #+#             */
/*   Updated: 2018/12/14 15:57:10 by pdoherty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_TYPES_H
# define FILLER_TYPES_H

# define PRECISION 0.1

typedef struct	s_map
{
	int			width;
	int			height;
	char		**map;
}				t_map;

typedef struct	s_piece
{
	int			width;
	int			height;
	char		**piece;
}				t_piece;

typedef struct	s_coords
{
	int			x;
	int			y;
}				t_coords;

typedef struct	s_score
{
	float		score;
	t_coords	*spot;
}				t_score;

#endif
