/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpecci <gpecci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:24:57 by gpecci            #+#    #+#             */
/*   Updated: 2023/10/16 14:55:57 by gpecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

unsigned long	create_rgb(int r, int g, int b)
{
	return (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
}

void	draw_ceiling(t_cube *cube, int x, t_ray *ray, t_img *img)
{
	int	v;

	v = 0;
	while (v < ray->draw[0])
	{
		my_mlx_pixel_put(img, x, v,
			create_rgb(cube->c[0], cube->c[1], cube->c[2]));
		v++;
	}
}

void	draw_flooring(t_cube *cube, int x, t_ray *ray, t_img *img)
{
	int	v;

	v = ray->draw[1];
	while (v < WINDOW_H)
	{
		my_mlx_pixel_put(img, x, v,
			create_rgb(cube->f[0], cube->f[1], cube->f[2]));
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
