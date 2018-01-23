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

int		p_atoi(char **line)
{
	int num;

    num = 0;
	while (**line == ' ')
		(*line)++;
	while (**line >= '0' && **line <= '9')
	{
		num = num * 10 + (**line - '0');
		(*line)++;
	}
	return (num);
}

void	set_token(char *line, t_fill *ted, int tokenCol)
{
	char *row;
	int i;

	i = 0;
	if (*line != '\0')
	{	
		row = malloc(sizeof(char) * (tokenCol + 1));
		while (i < tokenCol)
		{
			row[i] = line[i];
			i++;
		}
		row[i] = '\0';
		ted->token[ted->distance++] = row;
	}
}

void	token(char *line, t_fill *ted, int fd)
{
	int tokenRow;
	int tokenCol;

	ted->distance = 0;
	while (!(*line >= '0' && *line <= '9'))
    	line++;
	tokenRow = p_atoi(&line);
	tokenCol = p_atoi(&line);
	ted->token = (char **)malloc(sizeof(char *) * (tokenRow + 1));
	ted->token[tokenRow] = 0;
	while (get_next_line(fd, &line) == 1)
		set_token(line, ted, tokenCol);
}

void	set_board(char *line, t_fill *ted)
{
	char *row;
	int i;

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
** Going to use distance as a tally for the map and tokens. Bad practice, blah blah blah
*/
void    board(int fd, t_fill *ted)
{
    char *line;

    line = 0;
    ted->distance = 0;
    ted->map =(char **)malloc(sizeof(char *) * (ted->row + 1));
	ted->map[ted->row] = 0;
	while (line == 0 || ft_isdigit(line[0]) == 1)
	{
		get_next_line(fd, &line);
		if (line[0] == 'P')
			token(line, ted, fd);
		else
			set_board(line, ted);
	}
}

void    player_and_size(int fd, t_fill *ted)
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

int main(int argc, char **argv)
{
    t_fill *ted;
    int fd;

    argc = 0;
    ted = malloc(sizeof(t_fill));
    player_and_size(fd = open(argv[1], O_RDONLY), ted);
    board(fd, ted);
	ez_win(ted);
    close(fd);
    //free line and ted
    return (0);
}
