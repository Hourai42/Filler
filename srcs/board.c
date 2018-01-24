/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 09:49:08 by ttran             #+#    #+#             */
/*   Updated: 2018/01/23 09:49:09 by ttran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	set_token(char *line, t_fill *ted, int tokencol)
{
	char	*row;
	int		i;

	i = 0;
	row = malloc(sizeof(char) * (tokencol + 1));
	while (i < tokencol)
	{
		row[i] = line[i];
		i++;
	}
	row[i] = '\0';
	ted->token[ted->distance++] = row;
}

static void	token(char *line, t_fill *ted)
{
	int		tokenrow;
	int		tokencol;
	int		i;

	i = 0;
	ted->distance = 0;
	while (!(*line >= '0' && *line <= '9'))
		line++;
	tokenrow = p_atoi(&line);
	tokencol = p_atoi(&line);
	ted->token = (char **)malloc(sizeof(char *) * (tokenrow + 1));
	ted->token[tokenrow] = 0;
	while (i < tokenrow)
	{
		get_next_line(STDIN_FILENO, &line);
		set_token(line, ted, tokencol);
		i++;
	}
}

static void	set_board(char *line, t_fill *ted)
{
	char	*row;
	int		i;

	i = 0;
	row = malloc(sizeof(char) * (ted->col + 1));
	line += 4;
	while (i < ted->col)
	{
		row[i] = line[i];
		i++;
	}
	row[i] = '\0';
	ted->map[ted->distance++] = row;
}

/*
** Going to use distance as a tally for the map and tokens.
** Bad practice, blah blah blah
*/

void		board(t_fill *ted)
{
	char	*line;

	line = 0;
	ted->distance = 0;
	ted->map = (char **)malloc(sizeof(char *) * (ted->row + 1));
	ted->map[ted->row] = 0;
	while (line == 0 || ft_isdigit(line[0]) == 1)
	{
		get_next_line(STDIN_FILENO, &line);
		if (line[0] == 'P')
			token(line, ted);
		else
			set_board(line, ted);
	}
}
