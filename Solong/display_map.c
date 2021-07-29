/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 14:35:07 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/07/29 18:59:04 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int valide_char(char c)
{
    if (c == '1' || c == '0' || c == 'C' || c == 'P' || c == 'E')
    return (1);
    return(0);    
}

void check_rectangle(char *line, char ret)
{
    static int check_line;
    static int height;
    
    if (!check_line) // est ce que ca marche ???
    check_line = ft_strlen(line); //rajout de strlen
    if (check_line != ft_strlen(line))
    {
    ft_putstr_fd("Error :\nBad Map format.\n", 2);
    exit(1);
    }
    if (!height)
    height = 0;
    height++;
    if (ret == 0 && height == check_line)
    {
    ft_putstr_fd("Error :\nBad Map format.\n", 2);
    exit(1);
    }
}

void check_line(char *line, char ret)
{
    int i;

    i = 0;
    while (ret == 1 && line[i])
    {
        if (!valide_char(line[i]))        
        {
        ft_putstr_fd("Error :\nBad Map format.\n", 2);
        exit(1);
        }
        i++;
    }
    i = 0;
    if (ret == 0)
    check_last_first_line(line);
}

void check_last_first_line(char *line)
{
    int i;

    i = 0;
    while (line[i])
    {
        if (line[i] != '1')        
        {
        ft_putstr_fd("Error :\nBad Map format.\n", 2);
        exit(1);
        }
        i++;
    }
}



void display_line(char *line, char ret, t_game *game)
{
    
// afficher a l ecran en fonction des données dans t_game ( trouver comment mettre les données avant)
// faire un check de la map avant ou dans cette fonction ??
}

void display_map(char **argv, t_game *game)
{
    int ret;
    int fd;
    char *line;
    int n;
    
    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
    ft_putstr_fd("Error :\nBad file descriptor.\n", 2); // rajouter libft ??
    n = -1;
    ret = 1;
    while(ret)
    {
     ret = get_next_line(fd, &line);
     if(ret == -1)
         exit(1);
    check_rectangle(line, ret);
    if (++n == 0)
    check_last_first_line(line);
    display_line(line, ret, game);
    free(line);
    line = NULL;
    }
    close (fd);
}