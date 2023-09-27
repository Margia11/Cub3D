/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andreamargiacchi <andreamargiacchi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:19:33 by andreamargi       #+#    #+#             */
/*   Updated: 2023/09/27 13:33:48 by andreamargi      ###   ########.fr       */
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
}

int main(int argc, char **argv)
{
	t_cube	cube;

	if (argc == 2)
	{
		read_map(argv[1], &cube);
		init_textures(&cube);
		fill_textures(&cube);
		fill_map(&cube);
		if (argv_check(argv[1]) == 1 && map_ctrl(&cube) == 0)
		{
			printf("OK\n");
		//		gameplay effettivo
		// 		mlx_loop(cube.mlx);
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
