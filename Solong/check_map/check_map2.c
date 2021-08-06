/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 16:31:09 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/08/06 15:24:42 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int valide_char(char c)
{
    if (c == '1' || c == '0' || c == 'C' || c == 'P' || c == 'E')
        return (1);
    return (0);    
}

void check_wall(char *line)
{
    if (line[0] != '1')
        error_wall();
    if (line[ft_strlen(line) - 1] != '1')
         error_wall();
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

void check_element(char c, int i, t_map *map)
{ 
    if (c == 'E')
    map->exit++;
    if (c == 'C')
    map->collec++;
    if (c == 'P')
    {
        map->player++;
        map->player_start_height = map->height;
        map->player_start_width = i;
    }
    
}

void check_name_map(char *map)
{
    int i;

    i = 0;
    while(map[i])
    i++;
    if (map[--i] != 'r')
    error_name();
    if (map[--i] != 'e')
    error_name();
    if (map[--i] != 'b')
    error_name();
    if (map[--i] != '.')
    error_name();
    if (ft_strlen(map) <= 4)
    error_name();
}