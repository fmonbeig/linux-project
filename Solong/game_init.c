/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 12:41:52 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/08/02 18:39:30 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map *map_init()
{
	t_map *map;
	
	map = malloc(sizeof(t_map));
	map->collec = 0;
	map->exit = 0;
	map->player = 0;
	map->height = 0;
	map->width = 0;
	return (map);
}

void img_init(t_game *g)
{
		g->player->img = mlx_xpm_file_to_image(g->mlx, "./images/blitz.xpm", &g->player->width, &g->player->height);
		g->collec->img = mlx_xpm_file_to_image(g->mlx, "./images/blitz.xpm", &g->collec->width, &g->collec->height);
		g->wall->img = mlx_xpm_file_to_image(g->mlx, "./images/wall.xpm", &g->wall->width, &g->wall->height);
		g->floor->img = mlx_xpm_file_to_image(g->mlx, "./images/floor.xpm", &g->floor->width, &g->floor->height);
		g->exit->img = mlx_xpm_file_to_image(g->mlx, "./images/floor.xpm", &g->exit->width, &g->exit->height);
}

t_game *game_init(t_map *map)
{
	t_game *g;
	
	g = malloc(sizeof(t_game));
	if (!g)
		exit(1);
	g->mlx = mlx_init();
	g->win = mlx_new_window(g->mlx, map->height*60, map->width*60, "LOL");
	g->player = malloc(sizeof(t_img));
	g->floor = malloc(sizeof(t_img));
	g->collec = malloc(sizeof(t_img));
	g->wall = malloc(sizeof(t_img));
	g->exit = malloc(sizeof(t_img));
	if (!g->player || !g->collec || !g->wall || !g->floor
		|| !g->exit)
		{
		free(g->player);
		free(g->collec);
		free(g->wall);
		free(g->floor);
		free(g->exit);
		free(g);
		exit(1);  // faire un error malloc
		}
	img_init(g);
	return(g);
}
