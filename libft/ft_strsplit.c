/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 19:14:00 by pdoherty          #+#    #+#             */
/*   Updated: 2018/12/06 16:06:34 by pdoherty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	deinc(int *m, int *st, int i)
{
	*m = 1;
	*st = i;
}

static char	**create_array(char const *s, char c)
{
	if (s == NULL)
		return (NULL);
	return (char **)malloc(sizeof(char **) *
			(ft_num_of_splits(s, c) + 1));
}

static char	*get_split(char const *s, int st, int e, int *m)
{
	*m = 0;
	return (ft_strsub(s, (unsigned)st, (size_t)e));
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tr;
	int		i;
	int		st;
	int		m;
	int		j;

	if ((tr = create_array(s, c)) == NULL)
		return (NULL);
	i = 0;
	st = 0;
	m = 0;
	j = -1;
	while (s[i])
	{
		if (s[i] == c && m)
			tr[++j] = get_split(s, st, i - st, &m);
		else if (s[i + 1] == 0 && m)
			tr[++j] = get_split(s, st, 1 + i - st, &m);
		else if (s[i] != c && !m)
			deinc(&m, &st, i);
		i++;
	}
	tr[++j] = NULL;
	return (tr);
}
