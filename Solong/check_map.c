/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 14:35:07 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/08/04 18:02:05 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    check_rectangle(char *line, char ret, t_map *map)
{
    if (map->width == 0)
        map->width  = ft_strlen(line);
    if (map->width != ft_strlen(line))
        error_map();
    map->height++;
}

void    check_line(char *line, char ret, t_map *map)
{
    int i;
    static int n = 0;
    
    i = 0;
    if (n++ == 0)
        check_last_first_line(line);
    while (ret == 1 && line[i])
    {
        if (!valide_char(line[i]) && !check_wall(line))
            error_map();
        check_element(line[i], i, map);
        i++;
    }
    i = 0;
    if (ret == 0)
    {
    check_last_first_line(line);
    if (map->exit == 0 || !map->player == 1 || map->collec == 0)
    error_map(); // faire un error map special not enough element
    if (map->width < 3 || map->width < 3)
    error_map();
    }
}

void check_taille_map(t_map *map)
{
    if ((map->width * 60) > 2560)
    error_taille();
    if ((map->height * 60) > 1440)
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
        ft_putstr_fd(line,1); // a virer pour le rendu
        printf("ret = %d\n", ret); // ca aussi
        free(line);
        line = NULL;
    }
    check_taille_map(map);
    close (fd);
}