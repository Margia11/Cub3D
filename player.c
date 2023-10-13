/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpecci <gpecci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 15:48:58 by gpecci            #+#    #+#             */
/*   Updated: 2023/10/13 16:57:55 by gpecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

static void set_view_player(t_cube *cube, t_player *player)
{
	int	i;
	int	j;

	i = 0;
	while (cube->map[i])
	{
		j = 0;
		while (cube->map[i][j])
		{
			if (cube->map[i][j] == 'W' || cube->map[i][j] == 'N' || cube->map[i][j] == 'S' || cube->map[i][j] == 'E')
			{
				player->view = cube->map[i][j];
				player->pos[0] = i + 0.5;
				player->pos[1] = j + 0.5;
				cube->player = player;
				return ;
			}
			j++;
		}
		i++;
	}
}

static void	set_we(t_player *player)
{
	if (player->view == 'W')
	{
		player->dir[0] = -1.0;
		player->dir[1] = 0.0;
		player->plane[0] = 0.0;
		player->plane[1] = -0.66;
	}
	else
	{
		player->dir[0] = 1.0;
		player->dir[1] = 0.0;
		player->plane[0] = 0.0;
		player->plane[1] = 0.66;
	}
}

void	set_player(t_cube *cube, t_player *player)
{
	set_view_player(cube, player);
	if (player->view == 'N')
	{
		player->dir[0] = 0.0;
		player->dir[1] = -1.0;
		player->plane[0] = 0.66;
		player->plane[1] = -0.0;
	}
	else if (player->view == 'S')
	{
		player->dir[0] = 0.0;
		player->dir[1] = 1.0;
		player->plane[0] = -0.66;
		player->plane[1] = 0.0;
	}
	else
		set_we(player);
}

void	move_up_down(t_cube *cube, double dir)
{
	double	npos_x;
	double	npos_y;
	double	pos_x;
	double	pos_y;

	pos_x = cube->player->pos[0];
	pos_y = cube->player->pos[1];
	npos_x = pos_x + (cube->player->dir[0] * MOVSPEED * dir);
	npos_y = pos_y + (cube->player->dir[1] * MOVSPEED * dir);
	if (cube->map[(int) npos_x][(int) npos_y] == '1')
		return ;
	if (cube->map[(int) npos_x][(int) npos_y] == 'c')
		return ;
	if (cube->map[(int) npos_x][(int) npos_y] == 'K')
		return ;
	cube->player->pos[0] = npos_x;
	cube->player->pos[1] = npos_y;
}

void	move_left_right(t_cube *cube, double dir)
{
	double	npos_x;
	double	npos_y;

	npos_x = cube->player->pos[0]
		+ (cube->player->plane[0] * MOVSPEED * dir);
	npos_y = cube->player->pos[1]
		+ (cube->player->plane[1] * MOVSPEED * dir);
	if (cube->map[(int) npos_x][(int) npos_y] == '1')
		return ;
	if (cube->map[(int) npos_x][(int) npos_y] == 'c')
		return ;
	if (cube->map[(int) npos_x][(int) npos_y] == 'K')
		return ;
	cube->player->pos[0] = npos_x;
	cube->player->pos[1] = npos_y;
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

static void	close_door(t_cube *cube)
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

int	mouse_filter(int x, t_cube *cube)
{
	if (x < WINDOW_W / 2)
		move_cam(cube, -1.0, MOUSESPEED);
	else
		move_cam(cube, 1.0, MOUSESPEED);
	return (0);
}
