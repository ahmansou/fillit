/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tets.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmansou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 12:37:59 by ahmansou          #+#    #+#             */
/*   Updated: 2019/07/19 17:03:40 by ahmansou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	int		get_inputsz(char *input)
{
	char	buff;
	int		sz;
	int		fd;

	sz = 1;
	fd = open(input, O_RDONLY);
	while (read(fd, &buff, 1) != '\0')
		sz++;
	close(fd);
	return (sz);
}

static	char	*get_input(char *input)
{
	int		fd;
	int		x;
	char	*fc;
	char	buff;

	if (get_inputsz(input) % 21 != 0)
		return (NULL);
	fd = open(input, O_RDONLY);
	fc = ft_strnew(get_inputsz(input));
	x = 0;
	while (read(fd, &buff, 1) != '\0')
	{
		if (buff != '#' && buff != '.' && buff != '\n')
		{
			free(fc);
			return (NULL);
		}
		fc[x] = buff;
		x++;
	}
	fc[x] = '\0';
	close(fd);
	return (fc);
}

static	int		check_separators(char *fc)
{
	int	x;

	x = 20;
	if (!fc)
		return (0);
	while (fc[x])
	{
		if (fc[x] != '\n')
			return (0);
		if (fc[x] == '\n' && fc[x + 1] == '\0')
			return (0);
		x += 21;
	}
	return (1);
}

char			**get_tets(char *input)
{
	char	**ts;
	char	*fc;
	int		x;

	x = -1;
	if (!(fc = get_input(input)))
		return (NULL);
	if (!check_separators(fc))
		return (0);
	while (fc[++x])
		if (fc[x] == '\n' && fc[x - 1] == '\n')
			fc[x] = '1';
	ts = ft_strsplit(fc, '1');
	free(fc);
	return (ts);
}
