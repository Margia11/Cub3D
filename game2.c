/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andreamargiacchi <andreamargiacchi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:31:02 by andreamargi       #+#    #+#             */
/*   Updated: 2023/10/16 12:17:33 by andreamargi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

int	raycast(t_cube *cube, t_img *img, t_ray *ray)
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
	draw_fires(cube, zbuffer);
	return (0);
}

void	engine(t_cube *cube, t_img *img, t_ray *ray)
{
	raycast(cube, img, ray);
	render_minimap(cube);
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
		update_animation(cube);
		lock = 0;
	}
	else
		lock++;
	return (0);
}
