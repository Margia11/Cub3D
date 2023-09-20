/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andreamargiacchi <andreamargiacchi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:37:01 by amargiac          #+#    #+#             */
/*   Updated: 2023/09/20 16:11:51 by andreamargi      ###   ########.fr       */
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

typedef struct s_player
{
	int		pos_x;
	int		pos_y;
	char	dir;
	double	dir_x;
	double	dir_y;
	double	plane_x; //camera x
	double	plane_y; // camera y
	int		screen_width;
	int		screen_height;
}	t_player;

typedef struct s_ray
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x; //perpendicular distance to a wall
	double	side_dist_y;
	double	delta_dist_x; //length of ray from one x or y-side to next x or y-side
	double	delta_dist_y;
	double	perp_wall_dist; //length of ray from current position to next x or y-side
	int		step_x; //what direction to step in x or y-direction (either +1 or -1)
	int		step_y;
	int		hit; //was there a wall hit?
	int		side; //was a NS or a EW wall hit?
	int		line_height; //height of line to draw on screen
	int		draw_start;
	int		draw_end;
}	t_ray;

typedef struct s_cube
{
	void		*mlx;
	void		*mlx_win;
	char 		**map;
	t_player	player;
	t_ray		ray;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	char		F; //floor
	char		C; //ceiling soffitto
	int			R[2]; //color
	int			map_width;
	int			map_height;
	void		*mlx;
	void		*win;
}	t_cube;

//utils.c
int		ft_strcmp(char *s1, char *s2);
char	*rev_string(char *s);
void	gnl(char *line, int fd);
void	free_mat(char **mat);

//controls1.c
int		map_format(char *argv);
int		checkbordes_top_down(char **map);
int		checkbordes_left_right(char **map);
int		checkbordes_mid(t_cube *cube);

//controls2.c
int		checkelements(t_cube *cube);
int		check_textures(t_cube *textures);
int		check_argc(int argc);

//parser.c
void	read_input(t_cube *textures, char **line, int fd);
int		parse_texture(char *line, t_cube *textures);
int		parse_map(t_cube *textures, char **line, int fd);


//init.c
//void	game_init(t_cube *cube);
void	init_cube(t_cube *cube);
void	init_player(t_cube *cube);

//cube.c
int		end_game(t_cube *cube);

//raycasting.c
void	init_ray(t_ray *ray, t_player *player, int x);
void	dda(t_ray *ray, t_cube *cube);
void	calc_line_height(t_ray *ray, t_cube *cube);

#endif
