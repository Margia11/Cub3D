/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andreamargiacchi <andreamargiacchi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 12:10:07 by andreamargi       #+#    #+#             */
/*   Updated: 2023/09/20 12:10:35 by andreamargi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

void init_player(t_cube *cube)
{
	int	x;
	int	y;

	x = -1;
	while(cube->map[++x] != NULL)
	{
		y = -1;
		while(cube->map[x][++y] != '\0')
		{
			if(cube->map[x][y] == 'N' || cube->map[x][y] == 'S'
				|| cube->map[x][y] == 'E' || cube->map[x][y] == 'W')
			{
				cube->player.pos_x = x;
				cube->player.pos_y = y;
				cube->player.dir = cube->map[x][y];
				cube->map[x][y] = '0';
			}
		}
	}
}

void init_cube(t_cube *cube)
{
	cube->map = malloc(sizeof(char *) * 100);
	cube->player.pos_x = 0;
	cube->player.pos_y = 0;
	cube->player.dir = '0';
}

void game_init(t_cube *cube)
{
	cube->mlx = mlx_init();
	cube->win = mlx_new_window(cube->mlx, 640, 480, "Cub3d");
}
