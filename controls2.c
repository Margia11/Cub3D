/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andreamargiacchi <andreamargiacchi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:32:57 by andreamargi       #+#    #+#             */
/*   Updated: 2023/09/27 13:29:54 by andreamargi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

int	checkelements(t_cube *cube)
{
	int	x;
	int	y;

	x = -1;
	while(cube->map[++x] != NULL)
	{
		y = -1;
		while(cube->map[x][++y] != '\0')
		{
			if(cube->map[x][y] != '1' && cube->map[x][y] != '0'
				&& cube->map[x][y] != ' ' && cube->map[x][y] != '2'
				&& cube->map[x][y] != 'N' && cube->map[x][y] != 'S'
				&& cube->map[x][y] != 'E' && cube->map[x][y] != 'W')
				return (-1);
		}
	}
	return (0);
}

int	checkposition(t_cube *cube)
{
	int	i;
	int	j;

	i = 0;
	while (cube->map[i])
	{
		j = 0;
		while (cube->map[i][j])
		{
			if (cube->map[i][j] == 'N' || cube->map[i][j] == 'S'
				|| cube->map[i][j] == 'E' || cube->map[i][j] == 'W')
			{
				cube->player.pos_x = i;
				cube->player.pos_y = j;
				return (0);
			}
			j++;
		}
		i++;
	}
	return (-1);
}

int	check_textures(t_cube *cube)
{
	if(cube->NO == NULL || cube->SO == NULL || cube->WE == NULL
		|| cube->EA == NULL || cube->F == NULL || cube->C == NULL)
		return (-1);
	return (0);
}

int	checknplayer(char **map)
{
	int	i;
	int	j;
	int	n;

	i = 0;
	n = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'E' || map[i][j] == 'W')
				n++;
			j++;
		}
		if (n > 1)
			return (-1);
		i++;
	}
	return (0);
}

int	argv_check(char *argv)
{
	int	i;

	if (!argv)
		return (0);
	i = 0;
	while (argv[i])
		i++;
	i -= 1;
	if (argv[i] == 'b' && argv[i - 1] == 'u'
		&& argv[i - 2] == 'c' && argv[i - 3] == '.')
		return (1);
	return (0);
}
