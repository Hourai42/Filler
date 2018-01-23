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

	ted = malloc(sizeof(t_fill));
	player_and_size(STDIN_FILENO, ted);
	board(STDIN_FILENO, ted);
	ez_win(ted);
	return (0);
}
