/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 14:35:07 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/08/06 12:43:38 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void    check_rectangle(char *line, char ret, t_map *map)
{
    if (map->width == 0)
        map->width  = ft_strlen(line);
    if (map->width != ft_strlen(line))
        error_map_rectangle();
    map->height++;
}

void    check_line(char *line, char ret, t_map *map)
{
    int i;
    static int n = 0;
    
    i = 0;
    check_wall(line);
    if (n++ == 0)
        check_last_first_line(line);
    while (ret == 1 && line[i])
    {
        if (!valide_char(line[i]))
            error_char();
        check_element(line[i], i, map);
        i++;
    }
    i = 0;
    if (ret == 0)
    {
    check_last_first_line(line);
    if (map->exit == 0 || map->player != 1 || map->collec == 0)
    error_nb_element();
    }
}

void check_taille_map(t_map *map)
{
    if ((map->width * 60) > 1920)
    error_taille();
    if ((map->height * 60) > 1020)
    error_taille();
}

void check_map(char *map_file, t_map *map)
{
    int ret;
    int fd;
    char *line;
    
    check_name_map(map_file);
    fd = open(map_file, O_RDONLY);
    if (fd < 0)
        ft_putstr_fd("Error :\nBad file descriptor.\n", 2);
    ret = 1;
    while(ret)
    {
        ret = get_next_line(fd, &line);
        if(ret == -1)
            exit(1);
        check_line(line, ret, map);
        check_rectangle(line, ret, map);
        free(line);
        line = NULL;
    }
    check_taille_map(map);
    close (fd);
}