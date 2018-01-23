/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_and_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 09:47:08 by ttran             #+#    #+#             */
/*   Updated: 2018/01/23 09:47:10 by ttran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	player_and_size(int fd, t_fill *ted)
{
	char *line;

	line = 0;
	get_next_line(fd, &line);
	ted->player = (line[10] == '1' ? 'o' : 'x');
	ted->enemy = (line[10] == '1' ? 'x' : 'o');
	get_next_line(fd, &line);
	while (!(*line >= '0' && *line <= '9'))
		line++;
	ted->row = p_atoi(&line);
	ted->col = p_atoi(&line);
	get_next_line(fd, &line);
}
