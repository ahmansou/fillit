/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_board.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmansou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 15:57:49 by ahmansou          #+#    #+#             */
/*   Updated: 2019/07/19 18:21:51 by ahmansou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		sqrts(int nb)
{
	int	sqrtee;

	sqrtee = 2;
	while (sqrtee * sqrtee < nb)
		sqrtee++;
	return (sqrtee);
}

static	char	*init_board(int sz)
{
	int		i;
	int		rsz;
	int		tmp_sz;
	char	*board;

	i = 0;
	tmp_sz = sz;
	rsz = (sz + 1) * sz;
	board = ft_strnew(rsz);
	board[i++] = '.';
	while (i < rsz - 1)
	{
		if (i % tmp_sz == 0)
		{
			tmp_sz += sz + 1;
			board[i] = '\n';
		}
		else
			board[i] = '.';
		i++;
	}
	board[i] = '\0';
	return (board);
}

char			*build_board(char **t)
{
	int		board_sz;
	char	*board;

	board_sz = sqrts(count_tets(t) * 4);
	board = init_board(board_sz);
	while (fillit(board, board_sz, t, 0) == 0)
	{
		free(board);
		board_sz = board_sz + 1;
		board = init_board(board_sz);
	}
	return (board);
}
