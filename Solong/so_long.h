/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 14:58:28 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/07/29 18:14:53 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

typedef struct	s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}				t_img;

typedef struct	s_game {
	void	*mlx;
	char	*win;
	t_img floor;
	t_img player;
	t_img wall;
	t_img collec;
	t_img floor;
	t_img exit;
}				t_game;

// exemple utilisation : game->mlx // game->floor->img

void	ft_putstr_fd(char *s, int fd);

int get_next_line(int fd, char **line);



#endif