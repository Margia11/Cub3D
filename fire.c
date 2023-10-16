/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fire.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpecci <gpecci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:53:22 by gpecci            #+#    #+#             */
/*   Updated: 2023/10/13 15:17:06 by gpecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

t_object	*add_front_object(t_cube *cube, t_object **objs, double dist,
	t_tex *tex)
{
	t_object	*new;

	new = malloc(sizeof(t_object));
	if (!new)
		return (NULL);
	new->x = cube->player->pos[0];
	new->y = cube->player->pos[1];
	new->dist = dist;
	new->next = *objs;
	new->tex = tex;
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
	while (cube->map[++y])
	{
		x = -1;
		while (cube->map[y][++x] != '\0')
		{
			if (cube->map[y][x] == 'F')
			{
				d = INT16_MAX;
				objs = add_front_object(cube, &objs, d,
						&cube->tex->fire1);
				objs->x = y;
				objs->y = x;
				objs->type = cube->map[y][x];
			}
		}
	}
	cube->objs = objs;
}

t_object	*add_sorted_object(t_object **sorted, t_object *obj)
{
	t_object	*first;
	t_object	*previous;

	if (!*sorted)
		return ((*sorted = obj));
	first = *sorted;
	previous = NULL;
	while (*sorted && obj->dist < (*sorted)->dist)
	{
		previous = *sorted;
		*sorted = (*sorted)->sort;
	}
	if (!previous)
	{
		obj->sort = *sorted;
		*sorted = obj;
	}
	else
	{
		obj->sort = previous->sort;
		previous->sort = obj;
		*sorted = first;
	}
	return (obj);
}

t_object	*sort_objects(t_cube *cube)
{
	t_object	*sorted;
	t_object	*objs;

	sorted = NULL;
	objs = cube->objs;
	while (objs)
	{
		objs->dist = powf(objs->y - cube->player->pos[1], 2.)
			+ powf(objs->x - cube->player->pos[0], 2.);
		objs->sort = NULL;
		add_sorted_object(&sorted, objs);
		objs = objs->next;
	}
	return (sorted);
}
