/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andreamargiacchi <andreamargiacchi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:24:46 by andreamargi       #+#    #+#             */
/*   Updated: 2023/10/16 11:55:59 by andreamargi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

void	draw_square(t_img *img, int len, int offset_x, int offset_y)
{
	int	x;
	int	y;

	x = 0;
	while (x < len)
	{
		y = 0;
		while (y < len)
		{
			my_mlx_pixel_put(img, x + offset_x, y + offset_y, 0x0DDE3E4);
			y++;
		}
		x++;
	}
}

void	draw_yellow_square(t_img *img, int len, int offset_x, int offset_y)
{
	int	x;
	int	y;

	x = 0;
	while (x < len)
	{
		y = 0;
		while (y < len)
		{
			if (x == 0 || y == 0 || x == len - 1 || y == len - 1)
				my_mlx_pixel_put(img, x + offset_x, y + offset_y, 0x0000000);
			else
				my_mlx_pixel_put(img, x + offset_x, y + offset_y, 0x0FFDB28);
			y++;
		}
		x++;
	}
}

void	draw_green_square(t_img *img, int len, int offset_x, int offset_y)
{
	int	x;
	int	y;

	x = 0;
	while (x < len)
	{
		y = 0;
		while (y < len)
		{
			if (x == 0 || y == 0 || x == len - 1 || y == len - 1)
				my_mlx_pixel_put(img, x + offset_x, y + offset_y, 0x0000000);
			else
				my_mlx_pixel_put(img, x + offset_x, y + offset_y, 0x01ce33d);
			y++;
		}
		x++;
	}
}

void	draw_black_square(t_img *img, int len, int offset_x, int offset_y)
{
	int	x;
	int	y;

	x = 0;
	while (x < len)
	{
		y = 0;
		while (y < len)
		{
			my_mlx_pixel_put(img, x + offset_x, y + offset_y, 0x00000000);
			y++;
		}
		x++;
	}
}

void	draw_blue_square(t_img *img, int len, int offset_x, int offset_y)
{
	int	x;
	int	y;

	x = 0;
	while (x < len)
	{
		y = 0;
		while (y < len)
		{
			my_mlx_pixel_put(img, x + offset_x, y + offset_y, 0x00000FF);
			y++;
		}
		x++;
	}
}
