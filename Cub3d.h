/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andreamargiacchi <andreamargiacchi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:37:01 by amargiac          #+#    #+#             */
/*   Updated: 2023/09/13 16:15:24 by andreamargi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
#define CUBE3D_H

#include "get_next_line/get_next_line.h"
#include "libft/libft.h"
#include <unistd.h>
#include <math.h>
#include <stdlib.h>
//#include "mlx_linux/mlx.h"
#include <stdio.h>

typedef struct s_player
{
	int		x;
	int		y;
	char	dir;

}	t_player;

typedef struct s_cube
{
	char 		**map;
	t_player	player;
	char 		NO;
	char		SO;
	char		WE;
	char		EA;
	char		F; //floor
	char		C; //ceiling
	int			R[2]; //color
	int			map_width;
	int			map_height;
	void		*mlx;
	void		*win;
}	t_cube;

//utils
int		ft_strcmp(char *s1, char *s2);
char	*rev_string(char *s);

//controls1
int		map_format(char *argv);
int		checkbordes_top_down(char **map);
int		checkbordes_left_right(char **map);
int		checkbordes_mid(t_cube *cube);

//controls2
int		checkelements(t_cube *cube);
int		check_argc(int argc);

//parser
void	init_player(t_cube *cube);
void	read_input(t_cube *cube);
//void	game_init(t_cube *cube);
void	init_cube(t_cube *cube);



#endif
