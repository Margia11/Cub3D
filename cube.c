/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpecci <gpecci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:19:33 by andreamargi       #+#    #+#             */
/*   Updated: 2023/10/13 17:32:26 by gpecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

void	free_map(char **mat)
{
	int	i;

	i = 0;
	while(mat[i])
	{
		free(mat[i]);
		i++;
	}
	free(mat);
}

void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
}

int	exit_game(t_cube *cube)
{
	if (cube->nopath != NULL)
		free(cube->nopath);
	if (cube->sopath != NULL)
		free(cube->sopath);
	if (cube->wepath != NULL)
		free(cube->wepath);
	if (cube->eapath != NULL)
		free(cube->eapath);
	if (cube->f_temp != NULL)
		free(cube->f_temp);
	if (cube->c_temp != NULL)
		free(cube->c_temp);
	if (cube->map)
		free_map(cube->map);
	exit(0);
	return (0);
}

int	keypress(int keycode, t_cube *cube)
{
	if (keycode == KEY_ESC || keycode == KEY_Q)
		exit_game(cube);
	else if (keycode == KEY_W)
		move_up_down(cube, 1.0);
	else if (keycode == KEY_S)
		move_up_down(cube, -1.0);
	else if (keycode == KEY_LEFT)
		move_cam(cube, -1.0, ROTSPEED);
	else if (keycode == KEY_RIGHT)
		move_cam(cube, 1.0, ROTSPEED);
	else if (keycode == KEY_A)
		move_left_right(cube, -1.0);
	else if (keycode == KEY_D)
		move_left_right(cube, 1.0);
	else if (keycode == 49)
		open_door(cube);
	return (0);
}

int main(int argc, char **argv)
{
	t_cube		cube;
	t_img		img;
	t_player	player;
	t_textures	tex;

	if (argc == 2)
	{
		init_map(argv[1], &cube);
		if (argv_check(argv[1]) == 1 && map_ctrl(&cube) == 0)
		{
			init_game(&cube, &img, &player, &tex);
			mlx_hook(cube.win, 17, 0, exit_game, &cube);
			mlx_hook(cube.win, 2, 1L << 0, keypress, &cube);
			mlx_hook(cube.win, 6, 0, mouse_filter, &cube);
			mlx_loop_hook(cube.mlx, game_loop, &cube);
			mlx_loop(cube.mlx);
		}
		else
		{
			if (cube.map)
				free_map(cube.map);
			printf("Error: Invalid Map\n");
			exit(1);
		}
	}
	else
	{
		printf("Error: Bad Arguments\n");
		exit(1);
	}
	return (0);
}
