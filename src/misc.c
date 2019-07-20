/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeme.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmansou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 15:19:23 by ahmansou          #+#    #+#             */
/*   Updated: 2019/07/19 14:11:58 by ahmansou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	free2d(char **s)
{
	int x;

	x = 0;
	while (s[x])
		free(s[x++]);
	free(s);
	s = NULL;
}

int		count_tets(char **t)
{
	int i;

	i = 0;
	while (t[i])
		i++;
	return (i);
}

void	print_t(char **t)
{
	int i;

	i = 0;
	while (t[i])
		ft_putendl(t[i++]);
}
