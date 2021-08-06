/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 12:41:52 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/08/06 17:16:04 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_map *map_init(void)
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
		g->player = malloc(sizeof(t_img));
	if (!g->player)
		error_malloc(g);
	g->floor = malloc(sizeof(t_img));
	if (!g->floor)
		error_malloc(g);
	g->collec = malloc(sizeof(t_img));
	if (!g->collec)
		error_malloc(g);
	g->wall = malloc(sizeof(t_img));
	if (!g->wall)
		error_malloc(g);
	g->exit = malloc(sizeof(t_img));
	if (!g->exit)
		error_malloc(g);
		g->player->img = mlx_xpm_file_to_image(g->mlx, "./images/player.xpm", &g->player->width, &g->player->height);
		g->collec->img = mlx_xpm_file_to_image(g->mlx, "./images/collec_potion.xpm", &g->collec->width, &g->collec->height);
		g->wall->img = mlx_xpm_file_to_image(g->mlx, "./images/wall.xpm", &g->wall->width, &g->wall->height);
		g->floor->img = mlx_xpm_file_to_image(g->mlx, "./images/floor_lol.xpm", &g->floor->width, &g->floor->height);
		g->exit->img = mlx_xpm_file_to_image(g->mlx, "./images/exit.xpm", &g->exit->width, &g->exit->height);
}

void map_mem(t_game *g, t_map *map)
{
	int i;

	i = -1;
	g->map = malloc(sizeof(char *) * (map->height));
	if (!g->map)
	error_malloc_early(g,map);
	while(++i < map->height)
	{
		g->map[i] = malloc(sizeof(char) * ((map->width) + 1));
		if (!g->map[i])
		error_malloc_early(g,map);
	}
}

void data_recuperation(t_game *g, t_map *map)
{
	g->move = 0;
	g->player_height = map->player_start_height;
	g->player_width = map->player_start_width;
	g->collec_nb = map->collec;
	g->map_height = map->height;
	g->map_height = map ->width;
	free(map);
}

t_game *game_init(t_map *map)
{
	t_game *g;
	
	g = malloc(sizeof(t_game));
	if (!g)
		error_malloc_early(g,map);
	map_mem(g, map);
	data_recuperation(g, map);
	g->mlx = mlx_init();
	if (!g->mlx)
		error_malloc(g);
	g->win = mlx_new_window(g->mlx, map->width*60, map->height*60, "LOL");
	if (!g->win)
		error_malloc(g);
	img_init(g);
	return(g);
}
