/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_l.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmansou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 10:25:44 by ahmansou          #+#    #+#             */
/*   Updated: 2019/07/19 14:13:48 by ahmansou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	void	cpy_dash(char *t, char *od, int *sf)
{
	int	x;
	int i;
	int ix;
	int iy;

	x = 0;
	i = 0;
	iy = 0;
	while (t[i])
	{
		if (t[i] == '\n')
			iy++;
		ix = i - iy * 5;
		if (ix >= sf[0] && ix <= sf[1] && iy >= sf[2] && iy <= sf[3])
			od[x++] = t[i];
		if (ix == sf[1] && iy >= sf[2] && iy < sf[3])
			od[x++] = '\n';
		i++;
	}
	od[x] = '\0';
	free(t);
}

char			**only_dash(char **t)
{
	char	**od;
	int		*sf;
	int		y;
	int		tsz;

	y = 0;
	if (!(od = (char **)malloc(sizeof(char*) * (count_tets(t) + 1))))
		return (NULL);
	while (t[y])
	{
		sf = get_yx_sf(t[y]);
		tsz = (sf[1] - sf[0] + 1) * (sf[3] - sf[2] + 1) + 2;
		if (!(od[y] = (char*)malloc(sizeof(char) * tsz)))
			return (NULL);
		cpy_dash(t[y], od[y], sf);
		free(sf);
		y++;
	}
	free(t[y]);
	od[y] = NULL;
	return (od);
}

void			assign_l(char **t)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (t[y])
	{
		x = 0;
		while (t[y][x])
		{
			if (t[y][x] == '#')
				t[y][x] = 'A' + y;
			x++;
		}
		y++;
	}
}
