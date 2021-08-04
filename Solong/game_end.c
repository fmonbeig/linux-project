/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_end.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 15:21:19 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/08/04 15:58:18 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void game_end(t_game *g)
{
	mlx_destroy_image(g->mlx,g->player->img); // que se passe t-il lors du destroy ???
	mlx_destroy_image(g->mlx,g->floor->img);
	mlx_destroy_image(g->mlx,g->collec->img);
	mlx_destroy_image(g->mlx,g->wall->img);
	mlx_destroy_image(g->mlx,g->exit->img);
	while (g->map_height >= 0)
			free(g->map[g->map_height--]);
	mlx_destroy_window(g->mlx, g->win); //
	free(g->map);
    free(g->player);
	free(g->collec);
	free(g->wall);
	free(g->floor);
	free(g->exit);
	free(g);
    free(g->map_adr);    
}