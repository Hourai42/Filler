/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 23:53:49 by ttran             #+#    #+#             */
/*   Updated: 2018/01/22 23:53:50 by ttran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			main(void)
{
	t_fill	*ted;
	t_player *p;

	p = malloc(sizeof(t_player));
	player(p);
	while (42)	
	{
		ted = malloc(sizeof(t_fill));
		ted->player = p->player;
		ted->enemy = p->enemy;
		size(ted);
		board(ted);
		if (ez_win(ted) == 0)
			break;
		freeall(ted);
		free(ted);
	}
	free(p);
	freeall(ted);
	free(ted);
	return (0);
}
