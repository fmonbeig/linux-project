/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 17:11:35 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/08/04 18:28:36 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void move_up(t_game *g)
{
    if (g->map[g->player_height - 1][g->player_width] != '1')
    {
        if ((g->map[g->player_height][g->player_width] == 'E'))
        mlx_put_image_to_window(g->mlx, g->win, g->exit->img,
            60 * g->player_width, 60 * g->player_height);
        else if ((g->map[g->player_height][g->player_width] == 'C'))
        {
            mlx_put_image_to_window(g->mlx, g->win, g->floor->img,
                60 * g->player_width, 60 * g->player_height);
            g->collec_nb--;
            g->map[g->player_height][g->player_width] == '0';
        }
        else
            mlx_put_image_to_window(g->mlx, g->win, g->floor->img,
                60 * g->player_width, 60 * g->player_height);
            g->player_height--;
            printf("--------------- \n");
            printf("player height == %d \n", g->player_height); // a supp
            printf("player width == %d \n", g->player_width); // a supp
            mlx_put_image_to_window(g->mlx, g->win, g->player->img,
                60 * g->player_width, 60 * g->player_height);
            g->move++;
            ft_putstr_fd("UP -> Move number = ", 1);
            ft_putnbr_fd(g->move, 1);
            ft_putstr_fd("\n", 1);
            win_game(g);
    }
}
void move_down(t_game *g)
{
    if (g->map[g->player_height + 1][g->player_width] != '1')
    {
        if ((g->map[g->player_height][g->player_width] == 'E'))
        mlx_put_image_to_window(g->mlx, g->win, g->exit->img,
            60 * g->player_width, 60 * g->player_height);
        else if ((g->map[g->player_height][g->player_width] == 'C'))
        {
            mlx_put_image_to_window(g->mlx, g->win, g->floor->img,
                60 * g->player_width, 60 * g->player_height);
            g->collec_nb--;
            g->map[g->player_height][g->player_width] == '0';
        }
        else
            mlx_put_image_to_window(g->mlx, g->win, g->floor->img,
                60 * g->player_width, 60 * g->player_height);
            g->player_height++;
            printf("--------------- \n");
            printf("player height == %d \n", g->player_height); // a supp
            printf("player width == %d \n", g->player_width); // a supp
            mlx_put_image_to_window(g->mlx, g->win, g->player->img,
                60 * g->player_width, 60 * g->player_height);
            g->move++;
            ft_putstr_fd("UP -> Move number = ", 1);
            ft_putnbr_fd(g->move, 1);
            ft_putstr_fd("\n", 1);
            win_game(g);
    }
}

void move_left(t_game *g)
{
    if (g->map[g->player_height][g->player_width - 1] != '1')
    {
        if ((g->map[g->player_height][g->player_width] == 'E'))
        mlx_put_image_to_window(g->mlx, g->win, g->exit->img,
            60 * g->player_width, 60 * g->player_height);
        else if ((g->map[g->player_height][g->player_width] == 'C'))
        {
            mlx_put_image_to_window(g->mlx, g->win, g->floor->img,
                60 * g->player_width, 60 * g->player_height);
            g->collec_nb--;
            g->map[g->player_height][g->player_width] == '0';
        }
        else
            mlx_put_image_to_window(g->mlx, g->win, g->floor->img,
                60 * g->player_width, 60 * g->player_height);
            g->player_width--;
            printf("--------------- \n");
            printf("player height == %d \n", g->player_height); // a supp
            printf("player width == %d \n", g->player_width); // a supp
            mlx_put_image_to_window(g->mlx, g->win, g->player->img,
                60 * g->player_width, 60 * g->player_height);
            g->move++;
            ft_putstr_fd("UP -> Move number = ", 1);
            ft_putnbr_fd(g->move, 1);
            ft_putstr_fd("\n", 1);
            win_game(g);
    }
}

void move_right(t_game *g)
{
    if (g->map[g->player_height][g->player_width + 1] != '1')
    {
        if ((g->map[g->player_height][g->player_width] == 'E'))
        mlx_put_image_to_window(g->mlx, g->win, g->exit->img,
            60 * g->player_width, 60 * g->player_height);
        else if ((g->map[g->player_height][g->player_width] == 'C'))
        {
            mlx_put_image_to_window(g->mlx, g->win, g->floor->img,
                60 * g->player_width, 60 * g->player_height);
            g->collec_nb--;
            g->map[g->player_height][g->player_width] == '0';
        }
        else
            mlx_put_image_to_window(g->mlx, g->win, g->floor->img,
                60 * g->player_width, 60 * g->player_height);
            g->player_width++;
            printf("--------------- \n");
            printf("player height == %d \n", g->player_height); // a supp
            printf("player width == %d \n", g->player_width); // a supp
            mlx_put_image_to_window(g->mlx, g->win, g->player->img,
                60 * g->player_width, 60 * g->player_height);
            g->move++;
            ft_putstr_fd("UP -> Move number = ", 1);
            ft_putnbr_fd(g->move, 1);
            ft_putstr_fd("\n", 1);
            win_game(g);
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

/*
        mlx_put_image_to_window(g->mlx, g->win, g->wall->img, 60*w, 60*h);
        else if (line[j] == '0')
        mlx_put_image_to_window(g->mlx, g->win, g->floor->img, 60*w, 60*h);
        else if (line[j] == 'P')
        mlx_put_image_to_window(g->mlx, g->win, g->player->img, 60*w, 60*h);
        else if (line[j] == 'C')
        mlx_put_image_to_window(g->mlx, g->win, g->collec->img, 60*w, 60*h);
        else if (line[j] == 'E')
        mlx_put_image_to_window(g->mlx, g->win, g->exit->img, 60*w, 60*h);
*/