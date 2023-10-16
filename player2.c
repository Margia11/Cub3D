/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpecci <gpecci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 12:01:37 by andreamargi       #+#    #+#             */
/*   Updated: 2023/10/16 14:47:34 by gpecci           ###   ########.fr       */
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

void	move_cam(t_cube *cube, double dir, double speed)
{
	double	o_dirx;
	double	o_cam_dirx;
	double	rot_dir;

	rot_dir = speed * dir;
	o_dirx = cube->player->dir[0];
	cube->player->dir[0] = o_dirx * cos(rot_dir)
		- cube->player->dir[1] * sin(rot_dir);
	cube->player->dir[1] = o_dirx * sin(rot_dir)
		+ cube->player->dir[1] * cos(rot_dir);
	o_cam_dirx = cube->player->plane[0];
	cube->player->plane[0] = o_cam_dirx * cos(rot_dir)
		- cube->player->plane[1] * sin(rot_dir);
	cube->player->plane[1] = o_cam_dirx * sin(rot_dir)
		+ cube->player->plane[1] * cos(rot_dir);
}
