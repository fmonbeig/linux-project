/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_end.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 15:21:19 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/08/02 15:22:46 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void game_end(t_game *g, t_map *map)
{
    free(g->player);
	free(g->collec);
	free(g->wall);
	free(g->floor);
	free(g->exit);
	free(g);
    free(map);    
}