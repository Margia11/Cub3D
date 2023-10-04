/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpecci <gpecci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 15:48:58 by gpecci            #+#    #+#             */
/*   Updated: 2023/10/04 14:43:44 by gpecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

static void	set_we(t_cube *cube)
{
	if (cube->player->view == 'W')
	{
		cube->player->dir_x = -1.0;
		cube->player->dir_y = 0.0;
		cube->player->plane_x = 0.0;
		cube->player->plane_y = -0.66;
	}
	else
	{
		cube->player->dir_x = 1.0;
		cube->player->dir_y = 0.0;
		cube->player->plane_x = 0.0;
		cube->player->plane_y = 0.66;
	}
}

void	set_player(t_cube *cube)
{
	if (cube->player->view == 'N')
	{
		cube->player->dir_x = 0.0;
		cube->player->dir_y = -1.0;
		cube->player->plane_x = 0.66;
		cube->player->plane_y = -0.0;
	}
	else if (cube->player->view == 'S')
	{
		cube->player->dir_x = 0.0;
		cube->player->dir_y = 1.0;
		cube->player->plane_x = -0.66;
		cube->player->plane_y = 0.0;
	}
	else
		set_we(cube);
}

// t_object	*add_front_object(t_cube *cube, t_object **objs, double dist,
// 	t_img img)
// {
// 	t_object	*new;

// 	new = malloc(sizeof(t_object));
// 	if (!new)
// 		return (NULL);
// 	new->x = cube->player.pos_x;
// 	new->y = cube->player.pos_y;
// 	new->dist = dist;
// 	new->next = *objs;
// 	new->img = img;
// 	*objs = new;
// 	return (new);
// }

// void	get_all_objects(t_cube *cube)
// {
// 	int			x;
// 	int			y;
// 	double		d;
// 	t_object	*objs;

// 	y = -1;
// 	objs = NULL;
// 	while (cube->map[++x])
// 	{
// 		x = -1;
// 		while (cube->map[x][++y] != '\0')
// 		{
// 			if (cube->map[y][x] == '1' || cube->map[y][x] == '2')
// 			{
// 				d = INT16_MAX;
// 				objs = add_front_object(cube, &objs, d, );
// 				objs->x = x;
// 				objs->y = y;
// 				objs->type = cube->map[y][x];
// 			}
// 		}
// 	}
// 	cube->objs = objs;
// }

void	move_up_down(t_cube *cube, double dir)
{
	double	npos_x;
	double	npos_y;
	double	pos_x;
	double	pos_y;

	pos_x = cube->player->pos_x;
	pos_y = cube->player->pos_y;
	npos_x = pos_x + (cube->player->dir_x * MOVSPEED * dir);
	npos_y = pos_y + (cube->player->dir_y * MOVSPEED * dir);
	if (cube->map[(int) npos_y][(int) npos_x] == '1')
		return ;
	if (cube->map[(int) npos_y][(int) npos_x] == '2')
		return ;
	cube->player->pos_x = npos_x;
	cube->player->pos_y = npos_y;
}

void	move_left_right(t_cube *cube, double dir)
{
	double	npos_x;
	double	npos_y;

	npos_x = cube->player->pos_x
		+ (cube->player->plane_x * MOVSPEED * dir);
	npos_y = cube->player->pos_y
		+ (cube->player->plane_y * MOVSPEED * dir);
	if (cube->map[(int) npos_y][(int) npos_x] == '1')
		return ;
	if (cube->map[(int) npos_y][(int) npos_x] == '2')
		return ;
	cube->player->pos_x = npos_x;
	cube->player->pos_y = npos_y;
}

void	move_cam(t_cube *cube, double dir, double speed)
{
	double	o_dirx;
	double	o_cam_dirx;
	double	rot_dir;

	rot_dir = speed * dir;
	o_dirx = cube->player->dir_x;
	cube->player->dir_x = o_dirx * cos(rot_dir)
		- cube->player->dir_y * sin(rot_dir);
	cube->player->dir_y = o_dirx * sin(rot_dir)
		+ cube->player->dir_y * cos(rot_dir);
	o_cam_dirx = cube->player->plane_x;
	cube->player->plane_x = o_cam_dirx * cos(rot_dir)
		- cube->player->plane_y * sin(rot_dir);
	cube->player->plane_y = o_cam_dirx * sin(rot_dir)
		+ cube->player->plane_y * cos(rot_dir);
}

void	open_door(t_cube *cube)
{
	int	x;
	int	y;

	x = (int) cube->player->pos_x;
	y = (int) cube->player->pos_y;
	if (cube->map[(y) + 1][x] == '2')
		cube->map[(y) + 1][x] = 'o';
	else if (cube->map[(y) - 1][x] == '2')
		cube->map[(y) - 1][x] = 'o';
	else if (cube->map[(y)][(x) + 1] == '2')
		cube->map[(y)][(x) + 1] = 'o';
	else if (cube->map[(y)][(x) - 1] == '2')
		cube->map[(y)][(x) - 1] = 'o';
	else if (cube->map[(y) + 1][x] == '2')
		cube->map[(y) + 1][x] = 'o';
	else if (cube->map[(y) - 1][x] == '2')
		cube->map[(y) - 1][x] = 'o';
	else if (cube->map[(y)][(x) + 1] == '2')
		cube->map[(y)][(x) + 1] = 'o';
	else if (cube->map[(y)][(x) - 1] == '2')
		cube->map[(y)][(x) - 1] = 'o';
}

int	mouse_filter(int x, t_cube *cube)
{
	if (x < WINDOW_W / 2)
		move_cam(cube, -1.0, MOUSESPEED);
	else
		move_cam(cube, 1.0, MOUSESPEED);
	return (0);
}
