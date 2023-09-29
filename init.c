/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andreamargiacchi <andreamargiacchi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 12:10:07 by andreamargi       #+#    #+#             */
/*   Updated: 2023/09/29 11:50:46 by andreamargi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

void	init_textures(t_cube *cube)
{
	cube->NO = NULL;
	cube->SO = NULL;
	cube->WE = NULL;
	cube->EA = NULL;
}

void	init_map(char *str, t_cube *cube)
{
	read_map(str, cube);
	init_textures(cube);
	fill_textures(cube);
	fill_map(cube);
}

void	init_game(t_cube *cube)
{
	cube->mlx = mlx_init();
	cube->win = mlx_new_window(cube->mlx, 1000, 500, "cub3d");
}
