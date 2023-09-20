/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andreamargiacchi <andreamargiacchi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:32:57 by andreamargi       #+#    #+#             */
/*   Updated: 2023/09/20 11:54:11 by andreamargi      ###   ########.fr       */
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
int	check_textures(t_cube *textures)
{
	if(!textures->no || !textures->so || !textures->we || !textures->ea
		|| !textures->F || !textures->C)
		printf("Error Missing texture\n");
}

int check_argc(int argc)
{
	if(argc != 2)
		printf("Error Wrong number of arguments\n");
	return (0);
}
