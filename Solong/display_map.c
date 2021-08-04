/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 14:35:07 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/08/04 17:57:22 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void display_line(char *line, t_game *g)
{
    static int h = 0;
    static int k = 0;
    int j;
    int w;
    
    w = 0;
    j = -1;
    while(line[++j])
    {
        if (line[j] == '1')
            mlx_put_image_to_window(g->mlx, g->win, g->wall->img, 60*w, 60*h);
        else if (line[j] == '0')
            mlx_put_image_to_window(g->mlx, g->win, g->floor->img, 60*w, 60*h);
        else if (line[j] == 'P')
            mlx_put_image_to_window(g->mlx, g->win, g->player->img, 60*w, 60*h);
        else if (line[j] == 'C')
            mlx_put_image_to_window(g->mlx, g->win, g->collec->img, 60*w, 60*h);
        else if (line[j] == 'E')
            mlx_put_image_to_window(g->mlx, g->win, g->exit->img, 60*w, 60*h);
        w++;
        g->map[k][j] = line[j];
    }
    g->map[k][j] = 0;
    k++;
    h++;
}


void display_map(char *map_file, t_game *g)
{
    int ret;
    int fd;
    char *line;
    
    fd = open(map_file, O_RDONLY);
    if (fd < 0)
        ft_putstr_fd("Error :\nBad file descriptor.\n", 2);
    ret = 1;
    while(ret)
    {
        ret = get_next_line(fd, &line);
        if(ret == -1)
            exit(1);
        display_line(line,g);
        free(line);
        line = NULL;
    }
    close (fd);
}
