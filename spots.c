/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spots.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 21:13:10 by pdoherty          #+#    #+#             */
/*   Updated: 2018/12/13 21:47:09 by pdoherty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		delete_list(t_list *list)
{
	if (list == NULL)
		return ;
	if (list->next != NULL)
		delete_list(list->next);
	free((t_coords *)(((t_score *)list->content)->spot));
	free(list->content);
	free(list);
}

static t_coords	*new_zero(void)
{
	t_coords	*tr;

	tr = (t_coords *)malloc(sizeof(t_coords));
	tr->y = 0;
	tr->x = 0;
	return (tr);
}

void			add_to_spots(t_list **spots, t_score *ta)
{
	t_list	*l;

	l = (t_list *)malloc(sizeof(t_list));
	l->content = ta;
	l->content_size = sizeof(ta);
	l->next = NULL;
	if (*spots == NULL)
		*spots = l;
	else
		ft_lstadd(spots, l);
}

t_coords		*find_best_spot(t_list **spots)
{
	t_coords	*b;
	t_coords	*tr;
	t_list		*i;
	t_score		*current;
	float		best;

	i = *spots;
	b = NULL;
	while (i)
	{
		current = (t_score *)i->content;
		if (b == NULL || best < current->score)
		{
			best = current->score;
			b = current->spot;
		}
		i = i->next;
	}
	if (b != NULL)
		tr = (t_coords *)ft_memcpy(malloc(sizeof(b)), b, sizeof(b));
	else
		tr = new_zero();
	delete_list(*spots);
	return (tr);
}
