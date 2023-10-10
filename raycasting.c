/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andreamargiacchi <andreamargiacchi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:24:57 by gpecci            #+#    #+#             */
/*   Updated: 2023/10/10 12:48:15 by andreamargi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

unsigned long	create_rgb(int r, int g, int b)
{
	return (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
}

static void	draw_ceiling(t_cube *cube, int x, t_ray *ray, t_img *img)
{
	int	v;

	v = 0;
	while (v < ray->draw[0])
	{
		my_mlx_pixel_put(img, x, v,
			create_rgb(cube->C[0], cube->C[1], cube->C[2]));
		v++;
	}
}

static void	draw_flooring(t_cube *cube, int x, t_ray *ray, t_img *img)
{
	int	v;

	v = ray->draw[1];
	while (v < WINDOW_H)
	{
		my_mlx_pixel_put(img, x, v,
			create_rgb(cube->F[0], cube->F[1], cube->F[2]));
		v++;
	}
}

void	my_mlx_pixel_put(t_img *data, int x, int y, unsigned int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

unsigned long	get_pixel(t_img *img, int x, int y)
{
	char	*dest;

	if (x < 0 || x >= 64 || y < 0 || y >= 64)
		return (1);
	dest = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	return (*(unsigned long *)dest);
}

static unsigned long int	get_color(t_cube *cube, t_ray *ray, int texy)
{
	unsigned long int	color;

	color = 0;
	if (cube->map[(ray->pos[0])][(ray->pos[1])] == '2')
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
			cube->map[(ray->pos[0])][(ray->pos[1])] == '2')
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
