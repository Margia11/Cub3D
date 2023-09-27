/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andreamargiacchi <andreamargiacchi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 13:09:45 by andreamargi       #+#    #+#             */
/*   Updated: 2023/09/27 13:28:24 by andreamargi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

int	checkbordes_mid_north(t_cube *cube)
{
	int	x;
	int	y;

	x = 0;
	while(cube->map[x])
	{
		y = 0;
		while(cube->map[x][y])
		{
			if(cube->map[x][y] == 'N' && cube->map[x][y + 1] == ' ')
				return(-1);
			if(cube->map[x][y] == 'N' && cube->map[x][y - 1] == ' ')
				return(-1);
			if(cube->map[x][y] == 'N' && cube->map[x + 1][y] == ' ')
				return(-1);
			if(cube->map[x][y] == 'N' && cube->map[x - 1][y] == ' ')
				return(-1);
			y++;
		}
		x++;
	}
	return(0);
}

int	checkbordes_mid_south(t_cube *cube)
{
	int	x;
	int	y;

	x = 0;
	while(cube->map[x])
	{
		y = 0;
		while(cube->map[x][y])
		{
			if(cube->map[x][y] == 'S' && cube->map[x][y + 1] == ' ')
				return(-1);
			if(cube->map[x][y] == 'S' && cube->map[x][y - 1] == ' ')
				return(-1);
			if(cube->map[x][y] == 'S' && cube->map[x + 1][y] == ' ')
				return(-1);
			if(cube->map[x][y] == 'S' && cube->map[x - 1][y] == ' ')
				return(-1);
			y++;
		}
		x++;
	}
	return(0);
}

int	checkbordes_mid_east(t_cube *cube)
{
	int	x;
	int	y;

	x = 0;
	while(cube->map[x])
	{
		y = 0;
		while(cube->map[x][y])
		{
			if(cube->map[x][y] == 'E' && cube->map[x][y + 1] == ' ')
				return(-1);
			if(cube->map[x][y] == 'E' && cube->map[x][y - 1] == ' ')
				return(-1);
			if(cube->map[x][y] == 'E' && cube->map[x + 1][y] == ' ')
				return(-1);
			if(cube->map[x][y] == 'E' && cube->map[x - 1][y] == ' ')
				return(-1);
			y++;
		}
		x++;
	}
	return(0);
}

int	checkbordes_mid_west(t_cube *cube)
{
	int	x;
	int	y;

	x = 0;
	while(cube->map[x])
	{
		y = 0;
		while(cube->map[x][y])
		{
			if(cube->map[x][y] == 'W' && cube->map[x][y + 1] == ' ')
				return(-1);
			if(cube->map[x][y] == 'W' && cube->map[x][y - 1] == ' ')
				return(-1);
			if(cube->map[x][y] == 'W' && cube->map[x + 1][y] == ' ')
				return(-1);
			if(cube->map[x][y] == 'W' && cube->map[x - 1][y] == ' ')
				return(-1);
			y++;
		}
		x++;
	}
	return(0);
}

int map_ctrl(t_cube *cube)
{
	if (checkelements(cube) == -1 || checkposition(cube) == -1)
		return (-1);
	if (check_textures(cube) == -1 || checknplayer(cube->map) == -1)
		return (-1);
	if (checkbordes_first(cube->map) == -1 || checkbordes_last(cube->map) == -1)
		return (-1);
	if (checkbordes_left(cube->map) == -1 || checkbordes_right(cube->map) == -1)
		return (-1);
	if (checkbordes_mid_zero(cube) == -1 || checkbordes_mid_north(cube) == -1)
	 	return (-1);
	if (checkbordes_mid_south(cube) == -1 || checkbordes_mid_east(cube) == -1)
		return (-1);
	if (checkbordes_mid_west(cube) == -1)
		return (-1);
	return (0);
}
