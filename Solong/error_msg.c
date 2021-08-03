/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 12:23:07 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/08/03 18:45:42 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void error_map()
{
  ft_putstr_fd("Error :\n Bad Map Format \n", 2);
  exit(1);
}

void error_malloc()
{
  ft_putstr_fd("Error :\n Malloc Failed \n", 2);
  exit(1);
}