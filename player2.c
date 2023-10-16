/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andreamargiacchi <andreamargiacchi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 12:01:37 by andreamargi       #+#    #+#             */
/*   Updated: 2023/10/16 12:02:06 by andreamargi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

void	close_door(t_cube *cube)
{
	int	x;
	int	y;

	y = (int) cube->player->pos[0];
	x = (int) cube->player->pos[1];
	if (cube->map[(y) + 1][x] == 'o')
		cube->map[(y) + 1][x] = 'c';
	else if (cube->map[(y) - 1][x] == 'o')
		cube->map[(y) - 1][x] = 'c';
	else if (cube->map[(y)][(x) + 1] == 'o')
		cube->map[(y)][(x) + 1] = 'c';
	else if (cube->map[(y)][(x) - 1] == 'o')
		cube->map[(y)][(x) - 1] = 'c';
	else if (cube->map[(y) + 1][x] == 'o')
		cube->map[(y) + 1][x] = 'c';
	else if (cube->map[(y) - 1][x] == 'o')
		cube->map[(y) - 1][x] = 'c';
	else if (cube->map[(y)][(x) + 1] == 'o')
		cube->map[(y)][(x) + 1] = 'c';
	else if (cube->map[(y)][(x) - 1] == 'o')
		cube->map[(y)][(x) - 1] = 'c';
}

void	open_door(t_cube *cube)
{
	int	x;
	int	y;

	y = (int) cube->player->pos[0];
	x = (int) cube->player->pos[1];
	if (cube->map[(y) + 1][x] == 'c')
		cube->map[(y) + 1][x] = 'o';
	else if (cube->map[(y) - 1][x] == 'c')
		cube->map[(y) - 1][x] = 'o';
	else if (cube->map[(y)][(x) + 1] == 'c')
		cube->map[(y)][(x) + 1] = 'o';
	else if (cube->map[(y)][(x) - 1] == 'c')
		cube->map[(y)][(x) - 1] = 'o';
	else if (cube->map[(y) + 1][x] == 'c')
		cube->map[(y) + 1][x] = 'o';
	else if (cube->map[(y) - 1][x] == 'c')
		cube->map[(y) - 1][x] = 'o';
	else if (cube->map[(y)][(x) + 1] == 'c')
		cube->map[(y)][(x) + 1] = 'o';
	else if (cube->map[(y)][(x) - 1] == 'c')
		cube->map[(y)][(x) - 1] = 'o';
	else
		close_door(cube);
}

int	mouse_filter(int x, int y, t_cube *cube)
{
	mlx_mouse_get_pos(cube->win, &x, &y);
	if (x < WINDOW_W / 2 && y > WINDOW_H / 2)
		move_cam(cube, -1.0, MOUSESPEED / 2);
	else if (x >= WINDOW_W / 2 && y > WINDOW_H / 2)
		move_cam(cube, 1.0, MOUSESPEED / 2);
	return (0);
}
