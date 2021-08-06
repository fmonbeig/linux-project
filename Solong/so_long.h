/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 14:58:28 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/08/06 17:47:31 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include "mlx.h"
# define BUFFER_SIZE 10

typedef struct s_map {
	int		exit;
	int		collec;
	int		player;
	int		width;
	int		height;
	int		player_start_height;
	int		player_start_width;
}				t_map;

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}				t_img;

typedef struct s_game {
	void	*mlx;
	char	*win;
	t_img	*floor;
	t_img	*player;
	t_img	*wall;
	t_img	*collec;
	t_img	*exit;
	int		map_height;
	int		map_width;
	int		collec_nb;
	int		move;
	int		player_height;
	int		player_width;
	char	**map;
	t_map	*map_adr;
	char	*map_name;
	char	temp;
}				t_game;

// utils + GNL
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *s);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(const char *s1, const char *s2);
int		get_next_line(int fd, char **line);
// game init + end
t_game	*game_init(t_map *map);
void	img_init(t_game *g);
t_map	*map_init(void);
void	map_mem(t_game *g, t_map *map);
void	player_start(t_game *g, t_map *map);
// game end
int		game_end(t_game *g);
void	game_end_early(t_game *g, t_map *map);
void	destroy_image(t_game *g);
//check map
int		valide_char(char c);
void	check_rectangle(char *line, char ret, t_map *map);
void	check_line(char *line, char ret, t_map *map);
void	check_last_first_line(char *line);
void	check_wall(char *line);
void	check_map(char *map_file, t_map *map);
void	check_element(char c, int i, t_map *map);
void	check_name_map(char *map);
/*display map*/
void	display_line(char *line, t_game *game);
int		display_map(char *map, t_game *game);
int		display_map_hook(t_game *g);
void	display_line_hook(char *line, t_game *g, int h);
void	show_map(t_game *g);
void	put_floor(t_game *g);
//error message
void	error_map(void);
void	error_map_rectangle(void);
void	error_wall(void);
void	error_char(void);
void	error_nb_element(void);
void	error_name(void);
void	error_taille(void);
void	error_argument_nb(void);
void	error_malloc(t_game *g);
void	error_malloc_early(t_game *g, t_map *map);
// Keyhook
int		close_window(int keycode, t_game *g);
void	event(t_game *g);
// Event
void	win_game(t_game *g);
int		move(int keycode, t_game *g);
void	move_up(t_game *g);
void	move_down(t_game *g);
void	move_left(t_game *g);
void	move_right(t_game *g);
void	replace_image(t_game *g);
void	move_player(t_game *g);

#endif
