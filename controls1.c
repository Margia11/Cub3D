/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpecci <gpecci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:55:55 by amargiac          #+#    #+#             */
/*   Updated: 2023/10/16 14:48:02 by gpecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

int	checkbordes_first(char **map)
{
	int	k;

	k = 0;
	while (map[0][k])
	{
		if (map[0][k] != '1' && map[0][k] != ' ')
			return (-1);
		k++;
	}
	return (0);
}

int	checkbordes_last(char **map)
{
	int	x;
	int	k;

	x = 0;
	k = 0;
	while (map[x])
		x++;
	x--;
	while (map[x][k])
	{
		if (map[x][k] != '1' && map[x][k] != ' ')
			return (-1);
		k++;
	}
	return (0);
}

int	checkbordes_left(char **map)
{
	int	x;
	int	y;

	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y] == ' ')
			y++;
		if (map[x][y] != '1')
			return (-1);
		x++;
	}
	return (0);
}

int	checkbordes_right(char **map)
{
	int	x;
	int	y;

	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
			y++;
		y--;
		if (map[x][y] != '1')
			return (-1);
		x++;
	}
	return (0);
}

int	checkbordes_mid_zero(t_cube *cube)
{
	int	x;
	int	y;

	x = 0;
	while (cube->map[x])
	{
		y = 0;
		while (cube->map[x][y])
		{
			if (cube->map[x][y] == '0' && cube->map[x][y + 1] == ' ')
				return (-1);
			if (cube->map[x][y] == '0' && cube->map[x][y - 1] == ' ')
				return (-1);
			if (cube->map[x][y] == '0' && cube->map[x + 1][y] == ' ')
				return (-1);
			if (cube->map[x][y] == '0' && cube->map[x - 1][y] == ' ')
				return (-1);
			y++;
		}
		x++;
	}
	return (0);
}
