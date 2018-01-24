/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_placement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 09:54:46 by ttran             #+#    #+#             */
/*   Updated: 2018/01/23 09:54:49 by ttran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	token_checker(t_fill *ted, t_maptemp *h, int token_x, int token_y)
{
	int		x;
	int		y;

	if (h->run == 0)
	{
		h->norm_x = h->map_x - token_x;
		h->norm_y = h->map_y - token_y;
	}
	x = h->norm_x + token_x;
	y = h->norm_y + token_y;
	if (x < 0 || x >= ted->col || y < 0 || y >= ted->row ||
	ted->map[y][x] == ted->enemy || ted->map[y][x] == ted->enemy - 32)
		return (0);
	if (ted->map[y][x] == ted->player || ted->map[y][x] == ted->player - 32)
		h->connection++;
	h->run++;
	return (1);
}

int			valid_placement(t_fill *ted, t_maptemp *h)
{
	int		i;
	int		n;

	i = 0;
	n = 0;
	h->connection = 0;
	h->run = 0;
	while (ted->token[n])
	{
		while (ted->token[n][i])
		{
			if (ted->token[n][i] == '*')
				if (token_checker(ted, h, i, n) == 0)
					return (0);
			i++;
		}
		i = 0;
		n++;
	}
	if (h->connection != 1)
		return (0);
	return (1);
}
