/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_end.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 15:21:19 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/08/09 13:56:40 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	game_end(t_game *g)
{
	int	i;

	i = -1;
	mlx_clear_window(g->mlx, g->win);
	destroy_image(g);
	while (g->map[++i])
		free(g->map[i]);
	if (g->map)
		free(g->map);
	if (g->win)
		mlx_destroy_window(g->mlx, g->win);
	if (g->mlx)
		mlx_destroy_display(g->mlx);
	if (g)
		free(g);
	ft_putstr_fd("Thanks for playing !!\n\n", 1);
	exit(1);
}

void	destroy_image(t_game *g)
{
	if (g->player->img)
		mlx_destroy_image(g->mlx, g->player->img);
	if (g->floor->img)
		mlx_destroy_image(g->mlx, g->floor->img);
	if (g->collec->img)
		mlx_destroy_image(g->mlx, g->collec->img);
	if (g->wall->img)
		mlx_destroy_image(g->mlx, g->wall->img);
	if (g->exit->img)
		mlx_destroy_image(g->mlx, g->exit->img);
	if (g->player)
		free(g->player);
	if (g->collec)
		free(g->collec);
	if (g->wall)
		free(g->wall);
	if (g->floor)
		free(g->floor);
	if (g->exit)
		free(g->exit);
}

void	game_end_early(t_game *g, t_map *map)
{
	int	i;

	i = -1;
	destroy_image(g);
	while (g->map[++i])
		free(g->map[i]);
	if (g->map)
		free(g->map);
	if (g->win)
		mlx_destroy_window(g->mlx, g->win);
	if (g->mlx)
		mlx_destroy_display(g->mlx);
	if (map)
		free(map);
	if (g)
		free(g);
	exit(1);
}
