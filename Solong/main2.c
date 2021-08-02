/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 12:01:41 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/08/02 17:41:57 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "so_long.h"

int	key_hook(int keycode, void *param)
{
	if (keycode == 65307)
    {
		exit(1);
    }
    
	return(1);
}

int	main(void)
{
	t_game *g;

	g = malloc(sizeof(t_game));
	g->player = malloc(sizeof(t_img));
	

	g->mlx = mlx_init(); // initialisation de la mlx
	g->win = mlx_new_window(g->mlx, 1920, 1080, "LOL"); // creation de la fenetre
	
	g->player->img = mlx_xpm_file_to_image(g->mlx, "./images/blitz.xpm", &g->player->width, &g->player->height);
    /*
    g.floor.img = mlx_xpm_file_to_image(mlx, "./images/floor_lol.xpm", &g.floor.width, &g.floor.height);
    g.wall.img = mlx_xpm_file_to_image(mlx, "./images/bush.xpm", &g.wall.width, &g.wall.height);
    x =g.floor.width;
    
    printf("floor width %d", g.floor.width);
    printf("floor height %d", g.floor.height);
    printf("floor width %d", g.player.width);
    printf("floor height %d", g.player.height);
    
    
    mlx_put_image_to_window(mlx, mlx_win, g.floor.img, 0, 0);
    
	mlx_put_image_to_window(mlx, mlx_win, g.player.img, 0, 0);
    while(++i < 10)
    {
    mlx_put_image_to_window(mlx, mlx_win, g.floor.img, 0, x); // ici on affiche l'image
    x += g.floor.width;
    }
    x = 0;
    while(++j < 10)
    */
   mlx_put_image_to_window(g->mlx, g->win, g->player->img, 60, 60); // ici on affiche l'image
   // x += g.floor.width;
    
   // mlx_destroy_image(mlx, g.player.img); // destroy a la fin les images
    //mlx_put_image_to_window(mlx, mlx_win, g.player.img, 0, 180);
	mlx_key_hook(g->win, key_hook, (void *)0);
	
	mlx_loop(g->mlx);
    
	return (0);
}

/*
.c.o:
			${CC} ${CFLAGS} -Imlx -Ibass -c $< -o ${<:.c=.o}
            */