/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmansou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 14:01:55 by ktbatou           #+#    #+#             */
/*   Updated: 2019/07/19 17:18:24 by ahmansou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	int	verify_links(char *t)
{
	int	i;
	int	a;

	a = 0;
	i = 0;
	while (t[i] != '\0')
	{
		if (t[i] == '#')
		{
			if (t[i + 5] == '#')
				a++;
			if (t[i - 1] == '#')
				a++;
			if (t[i + 5] == '#')
				a++;
			if (t[i - 1] == '#')
				a++;
		}
		i++;
	}
	if (a == 6 || a == 8)
		return (1);
	return (0);
}

static	int	verify4_12(char *t)
{
	int	octo;
	int	point;
	int i;

	i = 0;
	octo = 0;
	point = 0;
	while (t[i] != '\0')
	{
		if (t[i] == '.')
			point++;
		if (t[i] == '#')
			octo++;
		i++;
	}
	if (octo == 4 && point == 12)
		return (1);
	return (0);
}

int		validate_t(char **ts)
{
	int i;

	i = 0;
	if (!ts || count_tets(ts) > 26)
		return (0);
	while (ts[i])
	{
		if (!verify4_12(ts[i]) || !verify_links(ts[i]))
			return (0);
		i++;
	}
	return (1);
}
