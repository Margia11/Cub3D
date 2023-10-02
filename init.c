/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpecci <gpecci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 12:10:07 by andreamargi       #+#    #+#             */
/*   Updated: 2023/09/29 15:25:28 by gpecci           ###   ########.fr       */
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
	cube->NO = NULL;
	cube->SO = NULL;
	cube->WE = NULL;
	cube->EA = NULL;
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

void	init_game(t_cube *cube)
{
	cube->map_h = ft_matlen(cube->map);
	cube->map_w = ft_strlen(cube->map[0]);
	cube->F[0] = ft_atoi(ft_substr(cube->f_temp, 0, my_strchr(cube->f_temp, ',')));
	cube->f_temp = ft_substr(cube->f_temp, my_strchr(cube->f_temp, ',') + 1, ft_strlen(cube->f_temp));
	cube->F[1] = ft_atoi(ft_substr(cube->f_temp, 0, my_strchr(cube->f_temp, ',')));
	cube->f_temp = ft_substr(cube->f_temp, my_strchr(cube->f_temp, ',') + 1, ft_strlen(cube->f_temp));
	cube->F[2] = ft_atoi(ft_substr(cube->f_temp, 0, ft_strlen(cube->f_temp)));
	cube->mlx = mlx_init();
	cube->win = mlx_new_window(cube->mlx, 800, 800, "cub3d");
}
