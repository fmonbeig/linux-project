/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 15:15:40 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/08/09 13:39:37 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	close_window(int keycode, t_game *g)
{
	if (keycode == XK_Escape)
		game_end(g);
	if (keycode == XK_m)
		show_map(g);
}

void	win_game(t_game *g)
{
	if (g->temp == 'E' && g->collec_nb == 0)
	{
		ft_putstr_fd("\n*****************\n*****************\n\n", 1);
		ft_putstr_fd("      VICTORY ! \n\n", 1);
		ft_putstr_fd("  Move = ", 1);
		ft_putnbr_fd(g->move, 1);
		ft_putstr_fd("\n", 1);
		if (g->move <= 30)
			ft_putstr_fd("  Rank S \n\n", 1);
		else if (g->move >= 31 && g->move <= 40)
			ft_putstr_fd("  Rank A \n\n", 1);
		else if (g->move >= 41 && g->move <= 50)
			ft_putstr_fd("  Rank B \n\n", 1);
		else
			ft_putstr_fd("  Rank C \n\n", 1);
		ft_putstr_fd("*****************\n*****************\n\n", 1);
		game_end(g);
	}
}

void	event(t_game *g)
{
	mlx_hook(g->win, 12, 1L << 15, display_map_hook, g);
	mlx_hook(g->win, KeyRelease, KeyReleaseMask, close_window, g);
	mlx_hook(g->win, 33, 1L << 5, game_end, g);
	mlx_hook(g->win, KeyPress, KeyPressMask, move, g);
	mlx_loop(g->mlx);
}
