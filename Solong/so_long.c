/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 12:01:41 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/07/29 18:14:14 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "so_long.h"

//int offset = (y * line_length + x * (bits_per_pixel / 8));
/*
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
*/

int	key_hook(int keycode, void *param)
{
	if (keycode == 65307)
	exit(1);
	return(1);
}

/*
int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_img	player;
	//char path_player = "./images/player.xpm";

	mlx = mlx_init(); // initialisation de la mlx
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!"); // creation de la fenetre
	
	player.img = mlx_xpm_file_to_image(mlx, "./images/player.xpm", &player.width, &player.height);

	mlx_put_image_to_window(mlx, mlx_win, player.img, 0, 0); // ici on affiche l'image
	mlx_key_hook(mlx_win, key_hook, (void *)0);
	
	mlx_loop(mlx);

	return (0);
}
*/
/*
Map
1 - Rajouter GNL -->OK
2 - Faire le parsing de la map avec GNL
3 - Creer l'image de la map en assemblant les sprites lors du parsing
3.5 - Check de la map : rectangle ? // .ber ? // exit ? // map fermé ??
4 - Afficher la map

5- Definir les keys et leur actions : ESC // Deplacement //
*/


int	main(int argc, char **argv)
{
	void	*mlx;
	void	*mlx_win;
	t_game	*game;

	if (argc == 2)
	{
	mlx = mlx_init(); // initialisation de la mlx
	mlx_win = mlx_new_window(mlx, 1920, 1080, "LOL"); // creation de la fenetre
	display_map(argv, game);
	
	mlx_loop(mlx);
	}
	return (0);
}

/*
	t_img	img;
	int x;
	int y;
	
	x = 5;
	y = 5;

	img.img = mlx_new_image(mlx, 1920, 1080); // creation d une image (void*)
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian); // creation de l adress et setup des parametres
	
	//ici on va creer son image grace a my_mlx_pixel_put
	while(x < 500)
	my_mlx_pixel_put(&img, x++, y, 0x00FF0000);
	while(y < 500)
	my_mlx_pixel_put(&img, x, y++, 0x00FF0000);
	x = 5;
	y = 5;
	while(y < 500)
	my_mlx_pixel_put(&img, x, y++, 0x00FF0000);
	*/