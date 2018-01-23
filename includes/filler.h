/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 13:57:31 by ttran             #+#    #+#             */
/*   Updated: 2018/01/22 13:58:45 by ttran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include <libft.h>

typedef struct  s_maptemp
{
    int map_x;
    int map_y;
    int norm_x;
    int norm_y;
    int run;
    int connection;
}               t_maptemp;

typedef struct s_fill
{
    char player;
    char enemy;
    char **map;
    char **token;
    int distance;
    int row;
    int col;
    int X;
    int Y;
    struct s_maptemp *ptr;
}   t_fill;

int main(int argc, char **argv);
void    ez_win(t_fill *ted);

#endif
