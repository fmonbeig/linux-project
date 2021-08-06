/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 12:23:07 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/08/06 17:19:41 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	error_map(void)
{
	ft_putstr_fd("Error :\n Bad Map Format \n", 2);
	exit(1);
}

void	error_map_rectangle(void)
{
	ft_putstr_fd("Error :\n Not a rectangle \n", 2);
	exit(1);
}

void	error_wall(void)
{
	ft_putstr_fd("Error :\n The map is not close by wall \n", 2);
	exit(1);
}

void	error_char(void)
{
	ft_putstr_fd("Error :\n Wrong char in the map\n", 2);
	exit(1);
}

void	error_nb_element(void)
{
	ft_putstr_fd("Error :\n Wrong number of element\n", 2);
	exit(1);
}
