/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andreamargiacchi <andreamargiacchi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 12:10:07 by andreamargi       #+#    #+#             */
/*   Updated: 2023/10/16 12:57:17 by andreamargi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

int	my_strchr(char *s, int n)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == n)
			return (i);
		i++;
	}
	return (i);
}

void	init_textures(t_cube *cube)
{
	cube->map = NULL;
	cube->nopath = NULL;
	cube->sopath = NULL;
	cube->wepath = NULL;
	cube->eapath = NULL;
	cube->f_temp = NULL;
	cube->c_temp = NULL;
}

void	init_map(char *str, t_cube *cube)
{
	read_map(str, cube);
	init_textures(cube);
	fill_textures(cube);
	fill_map(cube);
}

int	ft_matlen(char **mat)
{
	int	i;

	i = 0;
	while (mat[i])
		i++;
	return (i);
}

void	ctrl_ftemp(t_cube *cube)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (cube->f_temp[j])
	{
		while (cube->f_temp[i] != ',' && cube->f_temp[i])
			i++;
		while (j < i)
		{
			if (cube->f_temp[j] < '0' || cube->f_temp[j] > '9')
			{
				printf("RGB not valid\n");
				exit_game(cube);
			}
			j++;
		}
		j++;
		i = j;
	}
}
