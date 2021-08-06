/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 12:23:07 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/08/06 17:44:29 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	error_name(void)
{
	ft_putstr_fd("Error :\n Bad Map Extension \n", 2);
	exit(1);
}

void	error_taille(void)
{
	ft_putstr_fd("Error :\n Width or Height is too big\n", 2);
	ft_putstr_fd("       Column Max = 32 // Line Max = 17\n", 2);
	exit(1);
}

void	error_argument_nb(void)
{
	ft_putstr_fd("Error :\n You just need a map.ber in argument\n", 2);
	exit(1);
}

void	error_malloc(t_game *g)
{
	ft_putstr_fd("Error :\n Malloc Failed \n", 2);
	game_end(g);
}

void	error_malloc_early(t_game *g, t_map *map)
{
	ft_putstr_fd("Error :\n Malloc Failed \n", 2);
	game_end_early(g, map);
}
