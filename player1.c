/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpecci <gpecci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 15:48:58 by gpecci            #+#    #+#             */
/*   Updated: 2023/10/16 14:47:30 by gpecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

static void	set_view_player(t_cube *cube, t_player *player)
{
	int	i;
	int	j;

	i = 0;
	while (cube->map[i])
	{
		j = 0;
		while (cube->map[i][j])
		{
			if (cube->map[i][j] == 'W' || cube->map[i][j] == 'N'
				|| cube->map[i][j] == 'S' || cube->map[i][j] == 'E')
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
	if (cube->map[(int) npos_x][(int) npos_y] == 'F')
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
	if (cube->map[(int) npos_x][(int) npos_y] == 'F')
		return ;
	cube->player->pos[0] = npos_x;
	cube->player->pos[1] = npos_y;
}
