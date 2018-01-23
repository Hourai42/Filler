/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ezwin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 00:55:37 by ttran             #+#    #+#             */
/*   Updated: 2018/01/23 00:55:39 by ttran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int     token_checker(t_fill *ted, t_maptemp *h, int token_x, int token_y)
{
    int X;
    int Y;

    if (run == 0)
    {
        h->norm_x = h->map_x - token_x;
        y->norm_y = h->map_y - token_y;
    }
    X = token_x + h->norm_x;
    Y = token_y + h->norm_y;
    if (X < 0 || X >= ted->col  || Y < 0 || Y >= ted->row ||
    ted->map[X][Y] == ted->enemy || ted->map[X][Y] == ted->enemy - 32)
        return (0);
    if (ted->map[X][Y] == ted->player || ted->map[X][Y] == ted->player - 32)
        h->connection++;
    run++;
    return (1);
}

int     valid_placement(t_fill *ted, t_maptemp *h)
{
    int i;
    int n;

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

void    losing_alg(t_fill *ted, t_maptemp *h)
{

}

void    pls_win(t_fill *ted, int map_x, int map_y)
{
    t_maptemp *h;

    h = malloc(sizeof(t_maptemp));
    h->map_x = map_x;
    h->map_y = map_y;
    ted->ptr = h;
    if (valid_placement(ted, h) == 1)
        losing_alg(ted, h);
}

/*
** A distance of zero means none of the pieces can be placed. 
*/
void    ez_win(t_fill *ted)
{
    int i;
    int n;

    i = 0;
    n = 0;
    ted->distance = 0;
    while (ted->arr[n])
    {
        while (ted->arr[n][i])
        {
            pls_win(ted, i, n);
            i++;
        }
        i = 0;
        n++;
    }
    if (ted->distance != 0)
        ft_put_coordinates(ted);
}

void    ft_put_coordinates(t_fill *ted)
{
        ft_putnbr(ted->X);
        write(1, " ", 1);
        ft_putnbr(ted->Y);
        write(1, "\n", 1);
}