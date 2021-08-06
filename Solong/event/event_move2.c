/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_move2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 17:11:35 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/08/06 16:58:00 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void replace_image(t_game *g)
{
        if (g->temp == 'E')
        {
        mlx_put_image_to_window(g->mlx, g->win, g->exit->img,
            60 * g->player_width, 60 * g->player_height);
        g->map[g->player_height][g->player_width] = 'E';
            g->temp = '0';
        }
        else if (g->temp == 'C')
        {
            put_floor(g);
            g->collec_nb--;
            g->map[g->player_height][g->player_width] = '0';
            g->temp = '0';
        }
         else if ((g->map[g->player_height][g->player_width] == 'P'))
        {
            put_floor(g);
            g->map[g->player_height][g->player_width] = '0';
        }
         else if ((g->map[g->player_height][g->player_width] == '0'))
        {
            put_floor(g);
            g->map[g->player_height][g->player_width] = '0';
        }
}

void put_floor(t_game *g)
{
    mlx_put_image_to_window(g->mlx, g->win, g->floor->img,
        60 * g->player_width, 60 * g->player_height);
}

void move_player(t_game *g)
{
            if ((g->map[g->player_height][g->player_width] == 'E'))
                g->temp = 'E';
            else if ((g->map[g->player_height][g->player_width] == 'C'))
                g->temp = 'C'; 
            g->map[g->player_height][g->player_width] = 'P';
            mlx_put_image_to_window(g->mlx, g->win, g->player->img,
                60 * g->player_width, 60 * g->player_height);
            g->move++;
            ft_putstr_fd("Move number = ", 1);
            ft_putnbr_fd(g->move, 1);
            ft_putstr_fd("\n", 1);
            win_game(g);
}
