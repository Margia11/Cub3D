/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andreamargiacchi <andreamargiacchi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 12:03:55 by andreamargi       #+#    #+#             */
/*   Updated: 2023/10/16 12:06:36 by andreamargi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

unsigned long int	get_color(t_cube *cube, t_ray *ray, int texy)
{
	unsigned long int	color;

	color = 0;
	if (cube->map[(ray->pos[0])][(ray->pos[1])] == 'c')
		color = get_pixel(&cube->tex->door.xpm, ray->texx, texy);
	else if (ray->side == 0)
	{
		if (cube->player->pos[0] - ray->pos[0] > 0)
			color = get_pixel(&cube->tex->we.xpm, ray->texx, texy);
		else
			color = get_pixel(&cube->tex->ea.xpm, ray->texx, texy);
	}
	else
	{
		if (cube->player->pos[1] - ray->pos[1] > 0)
			color = get_pixel(&cube->tex->no.xpm, ray->texx, texy);
		else
			color = get_pixel(&cube->tex->so.xpm, ray->texx, texy);
	}
	return (color);
}

void	draw_ray_text(t_cube *cube, int x, t_ray *ray, t_img *img)
{
	int					v;
	unsigned long int	color;
	int					texy;

	draw_ceiling(cube, x, ray, img);
	v = ray->draw[0];
	color = 0;
	while (v < ray->draw[1])
	{
		texy = (int) ray->texpos & (64 - 1);
		ray->texpos += ray->step;
		color = get_color(cube, ray, texy);
		my_mlx_pixel_put(img, x, v, color);
		v++;
	}
	draw_flooring(cube, x, ray, img);
}

static void	body(t_cube *cube, t_ray *ray)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (ray->side_dist[0] < ray->side_dist[1])
		{
			ray->side_dist[0] += ray->delta_dist[0];
			ray->pos[0] += ray->incr[0];
			ray->side = 0;
		}
		else
		{
			ray->side_dist[1] += ray->delta_dist[1];
			ray->pos[1] += ray->incr[1];
			ray->side = 1;
		}
		if (cube->map[(ray->pos[0])][(ray->pos[1])] == '1' ||
			cube->map[(ray->pos[0])][(ray->pos[1])] == 'c')
			hit = 1;
	}
}

void	dda(t_cube *cube, t_ray *ray)
{
	if (cube->map[(ray->pos[0])][(ray->pos[1])] == '1')
	{
		if (ray->side_dist[0] < ray->side_dist[1])
			ray->side = 0;
		else
			ray->side = 1;
		return ;
	}
	else
		body(cube, ray);
}
