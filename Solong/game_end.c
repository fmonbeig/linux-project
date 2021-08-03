/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_end.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 15:21:19 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/08/03 18:59:05 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void game_end(t_game *g, t_map *map)
{
	while (map->height >= 0)
			free(g->map[map->height--]);
	free(g->map);
    free(g->player);
	free(g->collec);
	free(g->wall);
	free(g->floor);
	free(g->exit);
	free(g);
    free(map);    
}