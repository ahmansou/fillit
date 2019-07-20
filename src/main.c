/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmansou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 15:13:11 by ahmansou          #+#    #+#             */
/*   Updated: 2019/07/19 18:21:54 by ahmansou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				main(int argc, char **argv)
{
	char	**t;
	char	**od;
	char	*board;

	if (argc == 2)
	{
		t = get_tets(argv[1]);
		if (validate_t(t))
		{
			od = only_dash(t);
			assign_l(od);
			board = build_board(od);
			ft_putendl(board);
			free2d(od);
			free(board);
		}
		else
			ft_putendl("error");
		free(t);
	}
	else
		ft_putendl("usage: ./fillit <filename>");
	return (0);
}
