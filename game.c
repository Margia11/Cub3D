/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpecci <gpecci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 12:37:33 by gpecci            #+#    #+#             */
/*   Updated: 2023/10/04 12:38:59 by gpecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

int	game_loop(t_cube *cube)
{
	t_ray		ray;
	static int	lock = 0;

	if (lock == 170)
	{
		ft_memset(&ray, 0, sizeof(t_ray));
		// engine(cube, cube->img, &ray);
		// mlx_put_image_to_window(cube->mlx, cube->mlx_win,
		// 	cube->img->img, 0, 0);
		//update_animation(cube);
		lock = 0;
	}
	else
		lock++;
	return (0);
}
