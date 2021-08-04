/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 12:01:41 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/08/04 15:52:05 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int	main(int argc, char **argv)
{
	t_game	*g;
	t_map *map;

	if (argc == 2)
	{
		map = map_init();
		check_map(argv[1], map);
		g = game_init(map);
		display_map(argv[1], g);
		event(g);
		mlx_loop(g->mlx);
	}
	game_end(g);
	return (0);
}

/*
Map
1 - Rajouter GNL -->OK
2 - Faire le parsing de la map avec GNL
3 - Creer l'image de la map en assemblant les sprites lors du parsing OK
3.5 - Check de la map : rectangle OK // .ber ? // exit OK // map fermé OK
3.7 - Realiser tous les checks d'erreur !
4 - Recuperer la map dans un tableau OK

5- Definir les keys et leur actions : ESC // Deplacement //

Rajouter dans le parsing les collectibles OK dans la struct map->collec
Chopper la start position du character -> OK
Faire le checkname_map

*/