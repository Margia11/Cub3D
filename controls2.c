/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpecci <gpecci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:32:57 by andreamargi       #+#    #+#             */
/*   Updated: 2023/09/25 12:47:37 by gpecci           ###   ########.fr       */
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
	if(!textures->NO || !textures->SO || !textures->WE || !textures->EA
		|| !textures->F || !textures->C)
		printf("Error Missing texture\n");
	return (0);
}


