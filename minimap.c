/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andreamargiacchi <andreamargiacchi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:24:46 by andreamargi       #+#    #+#             */
/*   Updated: 2023/10/10 14:48:08 by andreamargi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

static void	draw_square(t_img *img, int len, int offset_x, int offset_y)
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

static void	draw_green_square(t_img *img, int len, int offset_x, int offset_y)
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

static void	draw_black_square(t_img *img, int len, int offset_x, int offset_y)
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

static void	draw_square_border(t_img *img, int len, int offset_x, int offset_y)
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
				my_mlx_pixel_put(img, x + offset_x, y + offset_y, 0x0FFFFFF);
			y++;
		}
		x++;
	}
}

static void	draw_minimap(t_cube *cube, int start_x, int x)
{
	int	start_y;
	int	y;
	int	pix[2];

	start_y = (int) floor(cube->player->pos[0]);
	y = start_y + PLAYER_R;
	pix[0] = 50 + ((x - start_x) * 10);
	while (y >= start_y - 4)
	{
		pix[1] = 50 - ((start_y - y) * 10);
		if (x < 0 || y < 0 || y >= cube->map_h
			|| x >= cube->map_w)
			draw_black_square(cube->img, 10, pix[0] + 10, pix[1]);
		else if (cube->map[y][x] == '1')
			draw_square_border(cube->img, 10, pix[0] + 10, pix[1]);
		else if (cube->map[y][x] == '2')
			draw_green_square(cube->img, 10, pix[0] + 10, pix[1]);
		else if (cube->map[y][x] != '1')
			draw_square(cube->img, 10, pix[0] + 10, pix[1]);
		y--;
	}
}

static void	draw_player(t_img *img, int len, int offset_x, int offset_y)
{
	int	x;
	int	y;

	x = 0;
	while (x < len)
	{
		y = 0;
		while (y < len)
		{
			my_mlx_pixel_put(img, x + offset_x, y + offset_y, 0x00c22620);
			y++;
		}
		x++;
	}
}

void	render_minimap(t_cube *cube)
{
	int	start_x;
	int	x;

	start_x = (int) floor(cube->player->pos[1]);
	x = start_x + PLAYER_R;
	while (x >= start_x - 4)
	{
		draw_minimap(cube, start_x, x);
		x--;
	}
	draw_player(cube->img, 10, 60, 50);
}
