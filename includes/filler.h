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

typedef struct s_fill
{
    char player;
    char **map;
    char **token;
    struct s_tc *stars;
    int distance;
    int row;
    int col;
}   t_fill;

/*
** The coordinates of each token's *. 
*/
typedef struct s_tc
{
    int x;
    int y;
    struct s_tc *next;
}       t_tc;

int main(int argc, char **argv);

#endif
