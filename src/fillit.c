/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmansou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 17:34:59 by ahmansou          #+#    #+#             */
/*   Updated: 2019/07/19 18:21:49 by ahmansou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		if_it_fits(char *t, char c, char *board, int i)
{
	int x;
	int xb;
	int tmpi;
	int board_sz;

	x = -1;
	xb = 0;
	tmpi = i;
	board_sz = 0;
	while (board[board_sz] != '\n')
		board_sz++;
	while (t[++x])
	{
		if (t[x] == '\n')
		{
			xb = 0 * (x++);
			i += board_sz + 1;
		}
		if (t[x] == c && (board[i + xb] != '.' ||
					i + xb >= (int)ft_strlen(board)))
			return (0);
		xb++;
	}
	it_sits(t, c, board, tmpi);
	return (1);
}

void	it_sits(char *t, char c, char *board, int i)
{
	int x;
	int xb;
	int board_sz;

	x = 0;
	xb = 0;
	board_sz = 0;
	while (board[board_sz] != '\n')
		board_sz++;
	while (t[x])
	{
		if (t[x] == '\n')
		{
			xb = 0;
			i += board_sz + 1;
			x++;
		}
		if (t[x] == c)
			board[i + xb] = c;
		xb++;
		x++;
	}
}

void	reset_b(char *t, char c, char *board, int i)
{
	int x;
	int xb;
	int board_sz;

	x = 0;
	xb = 0;
	board_sz = 0;
	while (board[board_sz] != '\n')
		board_sz++;
	while (t[x])
	{
		if (t[x] == '\n')
		{
			xb = 0;
			i += board_sz + 1;
			x++;
		}
		if (t[x] == c)
			board[i + xb] = '.';
		xb++;
		x++;
	}
}

int		fillit(char *board, int board_sz, char **t, int n)
{
	int x;
	int y;
	int i;

	x = 0;
	y = 0;
	while (y <= board_sz)
	{
		i = x + y * board_sz;
		if (if_it_fits(t[n], 'A' + n, board, i))
		{
			if (t[n + 1] == NULL || fillit(board, board_sz, t, n + 1) != 0)
				return (1);
			else
				reset_b(t[n], 'A' + n, board, i);
		}
		if (x == board_sz)
		{
			x = 0;
			y++;
		}
		x++;
	}
	return (0);
}
