/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 15:34:12 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/07/29 16:36:40 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int get_next_line(int fd, char **line)
{
    int i;
    int r;
    int c;

    i = 0;
    c = 0;
    
    if (!line)
    return (-1);
    *line = malloc(1234567);
    if (!(*line))
    return (NULL);
    **line = 0;
    while ((r = read(fd, &c, 1)) > 0)
    {
        if (c == '\n')
        break;
        (*line)[i] = c;
        i++;
        c = 0;
    }
    (*line)[i] = 0;
    if ( r == -1)
    **line = 0;
    return (r);
}