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

    if (h->run == 0)
    {
        h->norm_x = h->map_x - token_x;
        h->norm_y = h->map_y - token_y;
    }
    X = token_x + h->norm_x;
    Y = token_y + h->norm_y;
    if (X < 0 || X >= ted->col  || Y < 0 || Y >= ted->row ||
    ted->map[Y][X] == ted->enemy || ted->map[Y][X] == ted->enemy - 32)
        return (0);
    if (ted->map[Y][X] == ted->player || ted->map[Y][X] == ted->player - 32)
        h->connection++;
    h->run++;
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

void    calc_dist(t_maptemp *h, int enemy_x, int enemy_y, int *tempDist)
{
    int tmp;

    tmp = ((h->map_x - enemy_x) * (h->map_x - enemy_x)) +
    ((h->map_y - enemy_y) * (h->map_y - enemy_y));
    if (tmp < *tempDist)
        *tempDist = tmp;
}

int     closest_distance(t_fill *ted, t_maptemp *h)
{
    int i;
    int n;
    int tempDistance;

    tempDistance = 999999999;
    n = 0;
    i = 0;
    while (ted->map[n])
    {
        while (ted->map[n][i])
        {
            if (ted->map[n][i] == ted->enemy || ted->map[n][i] == ted->enemy - 32)
                calc_dist(h, i, n, &tempDistance);
            i++;
        }
        i = 0;
        n++;
    }
    return (tempDistance);
}

void    losing_alg(t_fill *ted, t_maptemp *h)
{
    int tmp;

    if (ted->distance == 0)
    {
        ted->X = h->map_x;
        ted->Y = h->map_y;
        ted->distance = closest_distance(ted, h);
    }
    else
    {
        tmp = closest_distance(ted, h);
        if (tmp < ted->distance)
        {
            ted->X = h->map_x;
            ted->Y = h->map_y;
            ted->distance = tmp; 
        }
    }
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

void    ft_put_coordinates(t_fill *ted)
{
        ft_putnbr(ted->X);
        write(1, " ", 1);
        ft_putnbr(ted->Y);
        write(1, "\n", 1);
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
    while (ted->map[n])
    {
        while (ted->map[n][i])
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