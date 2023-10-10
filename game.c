/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andreamargiacchi <andreamargiacchi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 12:37:33 by gpecci            #+#    #+#             */
/*   Updated: 2023/10/10 12:45:51 by andreamargi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

double	absf(double i)
{
	if (i < 0)
		return (i * -1.0);
	else
		return (i);
}

static void	init_ray(t_cube *cube, t_ray *ray)
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
		ray->delta_dist[0] = absf(1.0 / ray->dir[0]);
	if (ray->dir[1] == 0)
		ray->delta_dist[1] = 1e30;
	else
		ray->delta_dist[1] = absf(1.0 / ray->dir[1]);
}

static void	calc_incr(t_cube *cube, t_ray *ray)
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

static void	init_draw(t_cube *cube, t_ray *ray)
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

static void	init_wall_vars(t_cube *cube, t_ray *ray)
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

int	engine(t_cube *cube, t_img *img, t_ray *ray)
{
	int		i;
	double	zbuffer[WINDOW_W];

	i = 0;
	while (i < WINDOW_W)
	{
		ray->ray_id = i;
		init_ray(cube, ray);
		calc_incr(cube, ray);
		dda(cube, ray);
		init_draw(cube, ray);
		init_wall_vars(cube, ray);
		draw_ray_text(cube, i, ray, img);
		zbuffer[i] = ray->wall_dist;
		i++;
	}
	// draw_sprites(cube, zbuffer);
	// draw_crosshair(img);
	return (0);
}

int	game_loop(t_cube *cube)
{
	t_ray		ray;
	static int	lock = 0;

	if (lock == 170)
	{
		ft_memset(&ray, 0, sizeof(t_ray));
		engine(cube, cube->img, &ray);
		mlx_put_image_to_window(cube->mlx, cube->win,
			cube->img->img, 0, 0);
		lock = 0;
	}
	else
		lock++;
	return (0);
}
