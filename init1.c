/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpecci <gpecci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 12:10:07 by andreamargi       #+#    #+#             */
/*   Updated: 2023/10/16 15:24:23 by gpecci           ###   ########.fr       */
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

void	ctrl_temp(char *str, t_cube *cube)
{
	int	j;

	j = 0;
	while (str[j])
	{
		if (!(str[j] > '0' || str[j] < '9') && str[j] != ',')
		{
			printf("RGB not valid\n");
			exit_game(cube);
		}
		j++;
	}
}
