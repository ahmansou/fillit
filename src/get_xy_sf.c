/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_xy_sf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmansou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 09:46:45 by ahmansou          #+#    #+#             */
/*   Updated: 2019/06/28 13:05:48 by ahmansou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	int	get_xstart(char *t)
{
	int start;
	int i;
	int x;
	int y;

	i = 0;
	x = 0;
	y = 0;
	start = 3;
	while (t[i])
	{
		if (t[i] == '\n')
			y++;
		if (t[i] == '#')
		{
			x = i - y * 5;
			if (x < start)
				start = x;
		}
		i++;
	}
	return (start);
}

static	int	get_xfinish(char *t)
{
	int finish;
	int i;
	int x;
	int y;

	i = 0;
	x = 0;
	y = 0;
	finish = 0;
	while (t[i])
	{
		if (t[i] == '\n')
			y++;
		if (t[i] == '#')
		{
			x = i - y * 5;
			if (x > finish)
				finish = x;
		}
		i++;
	}
	return (finish);
}

static	int	get_ystart(char *t)
{
	int i;
	int y;
	int start;

	i = 0;
	y = 0;
	start = 3;
	while (t[i])
	{
		y = i / 5;
		if (t[i] == '#')
			if (y < start)
				start = y;
		i++;
	}
	return (start);
}

static	int	get_yfinish(char *t)
{
	int i;
	int y;
	int finish;

	i = 0;
	y = 0;
	finish = 0;
	while (t[i])
	{
		y = i / 5;
		if (t[i] == '#')
			if (y > finish)
				finish = y;
		i++;
	}
	return (finish);
}

int			*get_yx_sf(char *t)
{
	int *sf;

	if (!(sf = (int*)malloc(sizeof(int) * 4)))
		return (0);
	sf[0] = get_xstart(t);
	sf[1] = get_xfinish(t);
	sf[2] = get_ystart(t);
	sf[3] = get_yfinish(t);
	return (sf);
}
