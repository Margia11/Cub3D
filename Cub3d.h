/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpecci <gpecci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:37:01 by amargiac          #+#    #+#             */
/*   Updated: 2023/10/04 14:44:07 by gpecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
#define CUBE3D_H

#include "get_next_line/get_next_line.h"
#include "libft/libft.h"
#include <unistd.h>
#include <math.h>
#include <stdlib.h>
#include "mlx/mlx.h"
#include <stdio.h>
#include <fcntl.h>
#include <limits.h>

typedef struct s_player
{
	char	view;
	double	pos_x;
	double	pos_y;
	double	cam_side;
	double	dir_x;
	double	dir_y;
	double	plane_x; //camera x
	double	plane_y; // camera y
}	t_player;

typedef struct s_ray
{
	int		pos[2];
	int		draw[2];
	int		incr[2];
	int		ray_id;
	int		side;
	int		wall_height;
	int		lenght;
	int		texx;
	double	dir[2];
	double	side_dist[2];
	double	delta_dist[2];
	double	wallx;
	double	step;
	double	texpos;
	double	wall_dist;
}	t_ray;

typedef struct s_img
{
	void	*img;
	char	*path;
	int		bits_per_pixel;
	int		line_lenght;
	int		endian;
	int		w;
	int		h;
}	t_img;

typedef struct s_object
{
	char			type;
	int				x;
	int				y;
	double			dist;
	t_img			img;
	struct s_object	*next;
	struct s_object	*sort;
}	t_object;

typedef struct s_cube
{
	void			*mlx;
	void			*win;
	int				map_w;
	int				map_h;
	char 			**map;
	char			**tmp_map;
	char			*f_temp;
	char			*c_temp;
	int				F[3]; //floor
	int				C[3]; //ceiling soffitto
	t_img			no;
	t_img			so;
	t_img			ea;
	t_img			we;
	t_player		*player;
	t_ray			*ray;
	t_object		*objs;
	t_object		*sort;
}	t_cube;

# define KEY_ESC 53
# define KEY_Q 12
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define WINDOW_W 1280
# define WINDOW_H 960
# define ROTSPEED 0.06
# define MOVSPEED 0.04
# define MOUSESPEED 0.01

//controls1.c
int		checkbordes_first(char **map);
int		checkbordes_last(char **map);
int		checkbordes_left(char **map);
int		checkbordes_right(char **map);
int		checkbordes_mid_zero(t_cube *cube);

//controls2.c
int		checkelements(t_cube *cube);
int		check_textures(t_cube *textures);
int		checkposition(t_cube *cube);
int		checknplayer(char **map);
int		argv_check(char *argv);

//controls3.c
int		checkbordes_mid_north(t_cube *cube);
int		checkbordes_mid_south(t_cube *cube);
int		checkbordes_mid_east(t_cube *cube);
int		checkbordes_mid_west(t_cube *cube);
int		map_ctrl(t_cube *cube);

//parser.c
void	read_map(char *str, t_cube *cube);
void	parse_texture(char *line, t_cube *cube);
int		line_texture(char *line);
void	fill_map(t_cube *cube);
void	fill_textures(t_cube *cube);

//init.c
int		my_strchr(char *s, int n);
void	init_textures(t_cube *cube);
void	init_map(char *str, t_cube *cube);
int		ft_matlen(char **mat);
void	ctrl_ftemp(t_cube *cube);
void	ctrl_ctemp(t_cube *cube);
void	ctrl_comma(char *str, t_cube *cube);
void	init_rgb(t_cube *cube);
void	init_game(t_cube *cube);

//cube.c
void	free_map(char **mat);
void	print_map(t_cube *cube);
int		exit_game(t_cube *cube);
int		keypress(int keycode, t_cube *cube);
void	gameplay(t_cube *cube);

//raycasting.c
void	init_ray(t_ray *ray, t_player *player, int x);
void	dda(t_ray *ray, t_cube *cube);
void	calc_line_height(t_ray *ray, t_cube *cube);

//player.c
void	set_player(t_cube *cube);
void	move_up_down(t_cube *cube, double dir);
void	move_left_right(t_cube *cube, double dir);
void	move_cam(t_cube *cube, double dir, double speed);
void	open_door(t_cube *cube);
int		mouse_filter(int x, t_cube *cube);

//game.c
int		game_loop(t_cube *cube);

#endif
