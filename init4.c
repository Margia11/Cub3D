/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andreamargiacchi <andreamargiacchi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:40:15 by andreamargi       #+#    #+#             */
/*   Updated: 2023/10/16 13:01:35 by andreamargi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

void	set_rgb(t_cube *cube)
{
	init_rgb(cube);
	if (cube->F[0] < 0 || cube->F[0] > 255 || cube->F[1] < 0
		|| cube->F[1] > 255 || cube->F[2] < 0 || cube->F[2] > 255)
	{
		printf("RGB not valid\n");
		exit_game(cube);
	}
	if (cube->C[0] < 0 || cube->C[0] > 255 || cube->C[1] < 0
		|| cube->C[1] > 255 || cube->C[2] < 0 || cube->C[2] > 255)
	{
		printf("RGB not valid\n");
		exit_game(cube);
	}
}

void	init_game(t_cube *cube, t_img *img, t_player *player, t_textures *tex)
{
	char	**tmp;

	set_rgb(cube);
	set_player(cube, player);
	cube->mlx = mlx_init();
	cube->win = mlx_new_window(cube->mlx, WINDOW_W, WINDOW_H, "cub3d");
	cube->map_h = ft_matlen(cube->map);
	cube->max = ft_maxlen(cube->map);
	cube->map_w = ft_strlen(cube->map[0]);
	tmp = copy_map(cube->map, cube->map_h);
	free_map(cube->map);
	cube->map = full_map(tmp, cube);
	free_map(tmp);
	walls(cube, tex);
	door(cube);
	fire(cube);
	img->img = mlx_new_image(cube->mlx, WINDOW_W, WINDOW_H);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	cube->img = img;
	get_all_objects(cube);
	cube->sorted = sort_objects(cube);
}

void	init_rgb_utils(t_cube *cube)
{
	ctrl_comma(cube->c_temp, cube);
	ctrl_comma(cube->f_temp, cube);
	ctrl_ctemp(cube);
	ctrl_ftemp(cube);
}
