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

typedef struct			s_maptemp
{
	int					map_x;
	int					map_y;
	int					norm_x;
	int					norm_y;
	int					connection;
}						t_maptemp;

typedef struct			s_fill
{
	char				player;
	char				enemy;
	char				**map;
	char				**token;
	int					distance;
	int					row;
	int					col;
	int					x;
	int					y;
	struct s_maptemp	*ptr;
}						t_fill;

typedef struct			s_player
{
	char				player;
	char				enemy;
}						t_player;
int						main(void);
int						p_atoi(char **line);
void					board(t_fill *ted);
void					player(t_player *p);
void					size(t_fill *ted);
int						valid_placement(t_fill *ted, t_maptemp *h);
void					ft_put_coordinates(t_fill *ted);
int						ez_win(t_fill *ted);
void    				freeall(t_fill *ted);
#endif
