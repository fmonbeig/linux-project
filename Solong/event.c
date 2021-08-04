/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 15:15:40 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/08/04 18:30:26 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(int keycode, t_game *g)
{
	if (keycode == XK_Escape)
    {
       // game_end(g);
        exit(1);
    }
}

int	red_cross(int keycode, t_game *g)
{
    exit(1);
	return(1);
}

void win_game(t_game *g)
{
    printf("collec = %d\n", g->collec_nb); // a supprimer
    if (g->map[g->player_height][g->player_width] == 'E'
            && g->collec_nb == 0)
            {
                ft_putstr_fd("VICTORY ! \n", 1);
                ft_putstr_fd("move number = ", 1);
                ft_putnbr_fd(g->move, 1);
                ft_putstr_fd("\n", 1);
                if (g->move <= 20)
                    ft_putstr_fd("Rank S \n", 1);
                else if (g->move >= 21 && g->move <= 30)
                    ft_putstr_fd("Rank A \n", 1);
                else if (g->move >= 31 && g->move <= 40)
                    ft_putstr_fd("Rank B \n", 1);
                else
                    ft_putstr_fd("Rank C \n", 1);
                mlx_clear_window(g->mlx, g->win);
                mlx_destroy_window(g->mlx, g->win);
                exit(1); // TOUT FREE ????
            }
}

void event(t_game *g)
{
    mlx_hook(g->win, KeyRelease, KeyReleaseMask, close_window, g);
    mlx_hook(g->win, 17, 0L, red_cross, (void*)0);
    // minimize window
    mlx_hook(g->win, KeyPress, KeyPressMask, move, g);
}