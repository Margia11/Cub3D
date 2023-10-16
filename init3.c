/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpecci <gpecci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:39:57 by andreamargi       #+#    #+#             */
/*   Updated: 2023/10/16 14:46:12 by gpecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

char	**full_map(char **map, t_cube *cube)
{
	char	**res;
	int		i;
	int		j;

	i = 0;
	res = malloc(sizeof(char *) * (cube->map_h + 1));
	while (map[i])
	{
		j = -1;
		res[i] = malloc (sizeof(char) * (cube->max + 1));
		while (map[i][++j])
			full_map_utils(map, res, i, j);
		while (j < cube->max)
		{
			res[i][j] = '1';
			j++;
		}
		res[i][j] = '\0';
		i++;
	}
	res[i] = NULL;
	return (res);
}

int	ft_maxlen(char **map)
{
	int	i;
	int	j;
	int	n;
	int	res;

	i = 0;
	res = ft_strlen(map[0]);
	while (map[i])
	{
		n = 0;
		j = 0;
		while (map[i][j])
		{
			j++;
			n++;
		}
		if (n > res)
			res = n;
		i++;
	}
	return (res);
}

char	**copy_map(char **map, int n)
{
	char	**res;
	int		i;

	i = 0;
	res = malloc(sizeof(char *) * (n + 1));
	while (map[i])
	{
		res[i] = ft_strdup(map[i]);
		i++;
	}
	res[i] = NULL;
	return (res);
}

void	door(t_cube *cube)
{
	load_text_walls(cube, &(cube->tex->door), "./pics/door.xpm");
}

void	fire(t_cube *cube)
{
	load_text_walls(cube, &(cube->tex->fire1), "./pics/fire1.xpm");
	load_text_walls(cube, &(cube->tex->fire2), "./pics/fire2.xpm");
	load_text_walls(cube, &(cube->tex->fire3), "./pics/fire3.xpm");
	load_text_walls(cube, &(cube->tex->fire4), "./pics/fire4.xpm");
}
