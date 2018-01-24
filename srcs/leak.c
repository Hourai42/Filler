/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leak.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 01:49:27 by ttran             #+#    #+#             */
/*   Updated: 2018/01/24 01:49:28 by ttran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	calc_dist(t_maptemp *h, int enemy_x, int enemy_y, int *tempdist)
{
	int		tmp;

	tmp = ((h->starposx - enemy_x) * (h->starposx - enemy_x)) +
	((h->starposy - enemy_y) * (h->starposy - enemy_y));
	if (tmp < *tempdist)
		*tempdist = tmp;
}

static void	leak(t_fill *ted, int token_x, int token_y)
{
	if (ted->ptr->run == 0)
	{
		ted->ptr->norm_x = ted->ptr->map_x - token_x;
		ted->ptr->norm_y = ted->ptr->map_y - token_y;
	}
	ted->ptr->starposx = ted->ptr->norm_x + token_x;
	ted->ptr->starposy = ted->ptr->norm_y + token_y;
	ted->ptr->run++;
}

void		leak_token(t_fill *ted, int enemy_x, int enemy_y, int *tempdist)
{
	int		i;
	int		n;

	i = 0;
	n = 0;
	ted->ptr->run = 0;
	while (ted->token[n])
	{
		while (ted->token[n][i])
		{
			if (ted->token[n][i] == '*')
			{
				leak(ted, i, n);
				calc_dist(ted->ptr, enemy_x, enemy_y, tempdist);
			}
			i++;
		}
		i = 0;
		n++;
	}
}
