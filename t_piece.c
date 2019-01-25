/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_piece.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 11:36:54 by pdoherty          #+#    #+#             */
/*   Updated: 2018/12/08 15:54:51 by pdoherty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	free_t_piece(t_piece *piece)
{
	int	i;

	i = 0;
	while (i < piece->height)
	{
		free(piece->piece[i]);
		i++;
	}
	free(piece->piece);
	free(piece);
}

t_piece	*new_t_piece(void)
{
	t_piece	*tr;
	char	*line;
	char	**split;
	char	**piece;

	tr = (t_piece *)malloc(sizeof(t_piece));
	get_next_line(0, &line);
	split = ft_strsplit(line, ' ');
	free(line);
	tr->height = ft_atoi(split[1]);
	tr->width = ft_atoi(split[2]);
	free(split[0]);
	free(split[1]);
	free(split[2]);
	free(split);
	piece = (char **)malloc(sizeof(char *) * (tr->height + 1));
	piece[tr->height] = NULL;
	tr->piece = piece;
	return (tr);
}
