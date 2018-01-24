/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 21:32:39 by ttran             #+#    #+#             */
/*   Updated: 2018/01/23 21:32:40 by ttran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void    freeall(t_fill *ted)
{
    int i;

    i = 0;
    free(ted->ptr);
    while (ted->map[i])
        free(ted->map[i++]);
    free(ted->map);
    i = 0;
    while (ted->token[i])
        free(ted->token[i++]);
    free(ted->token);
}
