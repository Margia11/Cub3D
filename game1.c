/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andreamargiacchi <andreamargiacchi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 12:37:33 by gpecci            #+#    #+#             */
/*   Updated: 2023/10/16 12:15:53 by andreamargi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

double	abs_value(double i)
{
	if (i < 0)
		return (i * -1.0);
	else
		return (i);
}

void	init_ray(t_cube *cube, t_ray *ray)
{
	cube->player->cam_side = (2.0 * ((double) ray->ray_id)
			/ ((double) WINDOW_W)) - 1;
	ray->dir[0] = cube->player->dir[0]
		+ cube->player->plane[0] * cube->player->cam_side;
	ray->dir[1] = cube->player->dir[1]
		+ cube->player->plane[1] * cube->player->cam_side;
	ray->pos[0] = (int) cube->player->pos[0];
	ray->pos[1] = (int) cube->player->pos[1];
	if (ray->dir[0] == 0)
		ray->delta_dist[0] = 1e30;
	else
		ray->delta_dist[0] = abs_value(1.0 / ray->dir[0]);
	if (ray->dir[1] == 0)
		ray->delta_dist[1] = 1e30;
	else
		ray->delta_dist[1] = abs_value(1.0 / ray->dir[1]);
}

void	calc_incr(t_cube *cube, t_ray *ray)
{
	if (ray->dir[0] < 0)
	{
		ray->incr[0] = -1;
		ray->side_dist[0] = (cube->player->pos[0]
				- ((double) ray->pos[0])) * ray->delta_dist[0];
	}
	else
	{
		ray->incr[0] = 1;
		ray->side_dist[0] = (((double) ray->pos[0]) + 1.0
				- cube->player->pos[0]) * ray->delta_dist[0];
	}
	if (ray->dir[1] < 0)
	{
		ray->incr[1] = -1;
		ray->side_dist[1] = (cube->player->pos[1]
				- ((double) ray->pos[1])) * ray->delta_dist[1];
	}
	else
	{
		ray->incr[1] = 1;
		ray->side_dist[1] = (((double) ray->pos[1]) + 1.0
				- cube->player->pos[1]) * ray->delta_dist[1];
	}
}

void	init_draw(t_cube *cube, t_ray *ray)
{
	if (ray->side == 0)
		ray->wall_dist = ray->side_dist[0] - ray->delta_dist[0];
	else
		ray->wall_dist = ray->side_dist[1] - ray->delta_dist[1];
	ray->wall_height = (int) WINDOW_H / (ray->wall_dist);
	ray->draw[0] = (WINDOW_H / 2) - (ray->wall_height / 2);
	ray->draw[1] = (WINDOW_H / 2) + (ray->wall_height / 2);
	if (ray->draw[0] < 0)
		ray->draw[0] = 0;
	if (ray->wall_dist <= 0)
	{
		ray->wall_height = WINDOW_H;
		ray->wall_dist = 0;
	}
	if (ray->draw[1] >= WINDOW_H)
		ray->draw[1] = WINDOW_H - 1;
	cube->ray = ray;
}

void	init_wall_vars(t_cube *cube, t_ray *ray)
{
	if (ray->side == 0)
		ray->wallx = cube->player->pos[1] + ray->wall_dist * ray->dir[1];
	else
		ray->wallx = cube->player->pos[0] + ray->wall_dist * ray->dir[0];
	ray->wallx -= floor(ray->wallx);
	ray->texx = (int)(ray->wallx * 64.0);
	if (ray->side == 0 && ray->dir[0] > 0)
		ray->texx = 64 - ray->texx - 1;
	if (ray->side == 1 && ray->dir[1] < 0)
		ray->texx = 64 - ray->texx - 1;
	ray->step = 1.0 * 64.0 / ((double) ray->wall_height);
	ray->texpos = (((double) ray->draw[0]) - WINDOW_H / 2
			+ ray->wall_height / 2) * ray->step;
}
