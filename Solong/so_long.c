/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 12:01:41 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/08/03 18:37:42 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, void *param)
{
	if (keycode == 65307)
		exit(1);
	return(1);
}

int	main(int argc, char **argv)
{
	t_game	*g;
	t_map *map;

	if (argc == 2)
	{
		//checkname_map --> fonction check_extension pour savoir si on a bien a un .ber // et si on a bien quelque chose dans map !map
		map = map_init();
		check_map(argv[1], map);
		g = game_init(map);
		display_map(argv[1], g);
		mlx_key_hook(g->win, key_hook, (void *)0);
		mlx_loop(g->mlx);
	}
	//game_end(g, map);
	return (0);
}

/*
Map
1 - Rajouter GNL -->OK
2 - Faire le parsing de la map avec GNL
3 - Creer l'image de la map en assemblant les sprites lors du parsing OK
3.5 - Check de la map : rectangle OK // .ber ? // exit OK // map fermé OK
3.7 - Realiser tous les checks d'erreur !
4 - Afficher la map
5- Definir les keys et leur actions : ESC // Deplacement //

Rajouter dans le parsing les collectibles
Faire le checkname_map
Stocker map dans un tableau a deux dimensions
Faire une 
*/