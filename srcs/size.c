/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 21:30:17 by ttran             #+#    #+#             */
/*   Updated: 2018/01/23 21:30:28 by ttran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	size(t_fill *ted)
{
	char *line;

	line = 0;
	get_next_line(STDIN_FILENO, &line);
	while (!(*line >= '0' && *line <= '9'))
		line++;
	ted->row = p_atoi(&line);
	ted->col = p_atoi(&line);
	get_next_line(STDIN_FILENO, &line);
}
