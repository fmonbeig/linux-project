/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 17:11:35 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/08/09 13:41:29 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_up(t_game *g)
{
	if (g->map[g->player_height - 1][g->player_width] != '1')
	{
		replace_image(g);
		g->player_height--;
		move_player(g);
	}
}

void	move_down(t_game *g)
{
	if (g->map[g->player_height + 1][g->player_width] != '1')
	{
		replace_image(g);
		g->player_height++;
		move_player(g);
	}
}

void	move_left(t_game *g)
{
	if (g->map[g->player_height][g->player_width - 1] != '1')
	{
		replace_image(g);
		g->player_width--;
		move_player(g);
	}
}

void	move_right(t_game *g)
{
	if (g->map[g->player_height][g->player_width + 1] != '1')
	{
		replace_image(g);
		g->player_width++;
		move_player(g);
	}
}

int	move(int keycode, t_game *g)
{
	if (keycode == XK_w)
		move_up(g);
	if (keycode == XK_s)
		move_down(g);
	if (keycode == XK_a)
		move_left(g);
	if (keycode == XK_d)
		move_right(g);
	return (1);
}
