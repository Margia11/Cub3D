/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpecci <gpecci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 15:48:58 by gpecci            #+#    #+#             */
/*   Updated: 2023/10/02 17:00:44 by gpecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

static void	set_we(t_cube *cube)
{
	if (cube->player.view == 'W')
	{
		cube->player.dir_x = -1.0;
		cube->player.dir_y = 0.0;
		cube->player.plane_x = 0.0;
		cube->player.plane_y = -0.66;
	}
	else
	{
		cube->player.dir_x = 1.0;
		cube->player.dir_y = 0.0;
		cube->player.plane_x = 0.0;
		cube->player.plane_y = 0.66;
	}
}

void	set_player(t_cube *cube)
{
	if (cube->player.view == 'N')
	{
		cube->player.dir_x = 0.0;
		cube->player.dir_y = -1.0;
		cube->player.plane_x = 0.66;
		cube->player.plane_y = -0.0;
	}
	else if (cube->player.view == 'S')
	{
		cube->player.dir_x = 0.0;
		cube->player.dir_y = 1.0;
		cube->player.plane_x = -0.66;
		cube->player.plane_y = 0.0;
	}
	else
		set_we(cube);
}

t_object	*add_front_object(t_cube *cube, t_object **objs, double dist,
	t_img img)
{
	t_object	*new;

	new = malloc(sizeof(t_object));
	if (!new)
		return (NULL);
	new->x = cube->player.pos_x;
	new->y = cube->player.pos_y;
	new->dist = dist;
	new->next = *objs;
	new->img = img;
	*objs = new;
	return (new);
}

void	get_all_objects(t_cube *cube)
{
	int			x;
	int			y;
	double		d;
	t_object	*objs;

	y = -1;
	objs = NULL;
	while (cube->map[++x])
	{
		x = -1;
		while (cube->map[x][++y] != '\0')
		{
			if (cube->map[y][x] == '1' || cube->map[y][x] == '2')
			{
				d = INT16_MAX;
				objs = add_front_object(cube, &objs, d, );
				objs->x = x;
				objs->y = y;
				objs->type = cube->map[y][x];
			}
		}
	}
	cube->objs = objs;
}
