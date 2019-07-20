/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmansou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 12:36:44 by ahmansou          #+#    #+#             */
/*   Updated: 2019/07/19 17:18:48 by ahmansou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

char	**get_tets(char *input);
int	count_tets(char **t);
int	validate_t(char **ts);
char	**only_dash(char **t);
void	assign_l(char **t);
int	if_it_fits(char *t, char c, char *board, int i);
void	it_sits(char *t, char c, char *board, int i);
void	reset_b(char *t, char c, char *board, int i);
int	fillit(char *board, int board_size, char **t, int n);
char	*build_board(char **tetriminos);
void	free2d(char **s);
int	*get_yx_sf(char *t);
void	print_t(char **t);
void	ft_putchar(char c);
void	ft_putstr(char const *s);
void	ft_putendl(char const *s);
char	*ft_strnew(size_t size);
char	*ft_strdup(const char *s);
char	**ft_strsplit(char const *s, char c);
size_t	ft_strlen(const char *s);
void	ft_putnbr(int n);

#endif
