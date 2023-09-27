/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andreamargiacchi <andreamargiacchi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:37:01 by amargiac          #+#    #+#             */
/*   Updated: 2023/09/27 14:30:31 by andreamargi      ###   ########.fr       */
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
	void		*win;
	char 		**map;
	char		**tmp_map;
	t_player	player;
	t_ray		ray;
	char		*NO;
	char		*SO;
	char		*WE;
	char		*EA;
	char		*F; //floor
	char		*C; //ceiling soffitto
	int			R[2]; //color
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

//utils.c
int		ft_strcmp(char *s1, char *s2);
char	*rev_string(char *s);
void	gnl(char *line, int fd);
void	free_mat(char **mat);

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
void	init_textures(t_cube *cube);

//cube.c
void	free_map(char **mat);
void	print_map(t_cube *cube);


//raycasting.c
void	init_ray(t_ray *ray, t_player *player, int x);
void	dda(t_ray *ray, t_cube *cube);
void	calc_line_height(t_ray *ray, t_cube *cube);

#endif
