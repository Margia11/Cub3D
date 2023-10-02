/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpecci <gpecci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:19:33 by andreamargi       #+#    #+#             */
/*   Updated: 2023/10/01 16:18:48 by gpecci           ###   ########.fr       */
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

void	print_map(t_cube *cube)
{
	int	i;

	i = 0;
	while(cube->map[i])
	{
		printf("%s\n", cube->map[i]);
		i++;
	}
	printf("%s\n", cube->NO);
	printf("%s\n", cube->SO);
	printf("%s\n", cube->EA);
	printf("%s\n", cube->WE);
}

int	exit_game(t_cube *cube)
{
	free_map(cube->map);
	exit(0);
	return (0);
}

static int	keypress(int keycode, t_cube *cube)
{
	if (keycode == KEY_ESC || keycode == KEY_Q)
		exit_game(cube);
	return (0);
}

static void	gameplay(t_cube *cube)
{
	//da aggiungere altri hook
	mlx_hook(cube->win, 2, 1L << 0, keypress, cube);
	mlx_hook(cube->win, 17, 1L << 17, exit_game, cube);
}

int main(int argc, char **argv)
{
	t_cube	cube;

	if (argc == 2)
	{
		init_map(argv[1], &cube);
		if (argv_check(argv[1]) == 1 && map_ctrl(&cube) == 0)
		{
			init_game(&cube);
			printf("%D\n", cube.F[2]);
			gameplay(&cube);
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
