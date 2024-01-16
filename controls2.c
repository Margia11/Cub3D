/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpecci <gpecci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:32:57 by andreamargi       #+#    #+#             */
/*   Updated: 2023/10/16 14:41:25 by gpecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

int	checkelements(t_cube *cube)
{
	int	x;
	int	y;

	x = -1;
	while (cube->map[++x] != NULL)
	{
		y = -1;
		while (cube->map[x][++y] != '\0')
		{
			if (cube->map[x][y] != '1' && cube->map[x][y] != '0'
				&& cube->map[x][y] != ' ' && cube->map[x][y] != 'c'
				&& cube->map[x][y] != 'N' && cube->map[x][y] != 'S'
				&& cube->map[x][y] != 'E' && cube->map[x][y] != 'W'
				&& cube->map[x][y] != 'o' && cube->map[x][y] != 'F')
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
	if (cube->nopath == NULL || cube->sopath == NULL || cube->wepath == NULL
		|| cube->eapath == NULL || cube->f_temp == NULL || cube->c_temp == NULL)
		return (-1);
	if ((check_xpm(cube->nopath) == 0) || (check_xpm(cube->sopath) == 0)
		|| (check_xpm(cube->eapath) == 0) || (check_xpm(cube->wepath) == 0))
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
