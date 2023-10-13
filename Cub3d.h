/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpecci <gpecci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:37:01 by amargiac          #+#    #+#             */
/*   Updated: 2023/10/13 17:07:52 by gpecci           ###   ########.fr       */
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
# define MOVSPEED 0.10
# define MOUSESPEED 0.01
# define PLAYER_R 10
# define ANISPEED 6

typedef struct s_drawsprite
{
	int				drawx[2];
	int				drawy[2];
	double			pos[2];
	double			transf[2];
	double			inv_det;
	int				spr_screen_x;
	int				spr_h;
	int				spr_w;
}				t_drawsprite;

typedef struct s_player
{
	char	view;
	double	pos[2];
	double	cam_side;
	double	dir[2];
	double	plane[2];
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

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_tex {
	t_img	xpm;
	int		w;
	int		h;
}	t_tex;

typedef struct s_object
{
	char			type;
	int				x;
	int				y;
	double			dist;
	t_tex			*tex;
	struct s_object	*next;
	struct s_object	*sort;
}	t_object;

typedef struct s_textures {
	t_tex			no;
	t_tex			so;
	t_tex			we;
	t_tex			ea;
	t_tex			door;
	t_tex			knight1;
	t_tex			knight2;
	t_tex			knight3;
	t_tex			knight4;

}	t_textures;

typedef struct s_cube
{
	int				ani;
	void			*mlx;
	void			*win;
	int				map_w;
	int				map_h;
	int				max;
	char 			**map;
	char			**tmp_map;
	char			*f_temp;
	char			*c_temp;
	int				F[3]; //floor
	int				C[3]; //ceiling soffitto
	char			*nopath;
	char			*sopath;
	char			*eapath;
	char			*wepath;
	t_textures		*tex;
	t_img			*img;
	t_player		*player;
	t_ray			*ray;
	t_object		*objs;
	t_object		*sorted;
}	t_cube;


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
void	init_game(t_cube *cube, t_img *img, t_player *player, t_textures *tex);

//cube.c
void	my_mlx_pixel_put(t_img *data, int x, int y, unsigned int color);
void	free_map(char **mat);
void	print_map(char **map);
int		exit_game(t_cube *cube);
int		keypress(int keycode, t_cube *cube);
void	gameplay(t_cube *cube);

//player.c
void	set_player(t_cube *cube, t_player *player);
void	move_up_down(t_cube *cube, double dir);
void	move_left_right(t_cube *cube, double dir);
void	move_cam(t_cube *cube, double dir, double speed);
void	open_door(t_cube *cube);
int		mouse_filter(int x, t_cube *cube);

//game.c
int		raycast(t_cube *cube, t_img *img, t_ray *ray);
int		game_loop(t_cube *cube);
void	engine(t_cube *cube, t_img *img, t_ray *ray);

//raycasting.c
double	absf(double i);
void	dda(t_cube *cube, t_ray *ray);
void	draw_ray_text(t_cube *cube, int x, t_ray *ray, t_img *img);
unsigned long	get_pixel(t_img *img, int x, int y);

//minimap.c
void	render_minimap(t_cube *cube);

//animation.c
void	update_animation(t_cube *cube);
void	draw_knights(t_cube *cube, double *zbuff);

//knight.c
void		get_all_objects(t_cube *cube);
t_object	*sort_objects(t_cube *cube);
t_object	*add_front_object(t_cube *cube, t_object **objs, double dist,
	t_tex *tex);
t_object	*add_sorted_object(t_object **sorted, t_object *obj);

#endif
