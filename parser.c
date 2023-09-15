/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andreamargiacchi <andreamargiacchi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 13:35:29 by andreamargi       #+#    #+#             */
/*   Updated: 2023/09/15 14:23:05 by andreamargi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

//
void read_input(t_cube *cube)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open("map.cub", O_RDONLY);
	while(get_next_line(fd))
	{
		cube->map[i] = ft_strdup(line);
		free(line);
		i++;
	}
	cube->map[i] = NULL;
	close(fd);
}

void init_player(t_cube *cube)
{
	int	x;
	int	y;

	x = -1;
	while(cube->map[++x] != NULL)
	{
		y = -1;
		while(cube->map[x][++y] != '\0')
		{
			if(cube->map[x][y] == 'N' || cube->map[x][y] == 'S'
				|| cube->map[x][y] == 'E' || cube->map[x][y] == 'W')
			{
				cube->player.x = x;
				cube->player.y = y;
				cube->player.dir = cube->map[x][y];
				cube->map[x][y] = '0';
			}
		}
	}
}

void init_cube(t_cube *cube)
{
	cube->map = malloc(sizeof(char *) * 100);
	cube->player.x = 0;
	cube->player.y = 0;
	cube->player.dir = '0';
}

// void game_init(t_cube *cube)
// {
// 	cube->mlx = mlx_init();
// 	cube->win = mlx_new_window(cube->mlx, 640, 480, "Cub3d");
// }


