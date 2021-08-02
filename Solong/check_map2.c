/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 16:31:09 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/08/02 16:32:08 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int valide_char(char c)
{
    if (c == '1' || c == '0' || c == 'C' || c == 'P' || c == 'E')
        return (1);
    return (0);    
}

int check_wall(char *line)
{
    if (line[0] != 1)
        return (1);
    if (line[ft_strlen(line) - 1] != 1)
        return (1);
    return (0);
}

void    check_last_first_line(char *line)
{
    int i;

    i = 0;
    while (line[i])
    {
        if (line[i] != '1')
            error_map();
        i++;
    }
}

void check_element(char c, t_map *map)
{ 
    if (c == 'E')
    map->exit = 1;
    if (c == 'C')
    map->collec = 1;
    if (c == 'P')
    map->player = 1;
}