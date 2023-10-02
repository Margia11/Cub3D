/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpecci <gpecci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 12:10:07 by andreamargi       #+#    #+#             */
/*   Updated: 2023/10/02 15:54:40 by gpecci           ###   ########.fr       */
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
	cube->no.path = NULL;
	cube->so.path = NULL;
	cube->we.path = NULL;
	cube->ea.path = NULL;
	cube->f_temp = NULL;
	cube->c_temp = NULL;
}

void	init_map(char *str, t_cube *cube)
{
	read_map(str, cube);
	init_textures(cube);
	fill_textures(cube);
	fill_map(cube);
	set_player(cube);
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

void	ctrl_ctemp(t_cube *cube)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (cube->c_temp[j])
	{
		while (cube->c_temp[i] != ',' && cube->c_temp[i])
			i++;
		while (j < i)
		{
			if (cube->c_temp[j] < '0' || cube->c_temp[j] > '9')
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

void	ctrl_comma(char *str, t_cube *cube)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (str[i])
	{
		if (str[i] == ',')
			n++;
		i++;
	}
	if (n != 2)
	{
		printf("RGB not valid\n");
		exit_game(cube);
	}
}

void	init_rgb(t_cube *cube)
{
	ctrl_comma(cube->c_temp, cube);
	ctrl_comma(cube->f_temp, cube);
	ctrl_ctemp(cube);
	ctrl_ftemp(cube);
	cube->F[0] = ft_atoi(ft_substr(cube->f_temp, 0, my_strchr(cube->f_temp, ',')));
	cube->f_temp = ft_substr(cube->f_temp, my_strchr(cube->f_temp, ',') + 1, ft_strlen(cube->f_temp));
	cube->F[1] = ft_atoi(ft_substr(cube->f_temp, 0, my_strchr(cube->f_temp, ',')));
	cube->f_temp = ft_substr(cube->f_temp, my_strchr(cube->f_temp, ',') + 1, ft_strlen(cube->f_temp));
	cube->F[2] = ft_atoi(ft_substr(cube->f_temp, 0, ft_strlen(cube->f_temp)));
	free(cube->f_temp);
	cube->C[0] = ft_atoi(ft_substr(cube->c_temp, 0, my_strchr(cube->c_temp, ',')));
	cube->c_temp = ft_substr(cube->c_temp, my_strchr(cube->c_temp, ',') + 1, ft_strlen(cube->c_temp));
	cube->C[1] = ft_atoi(ft_substr(cube->c_temp, 0, my_strchr(cube->c_temp, ',')));
	cube->c_temp = ft_substr(cube->c_temp, my_strchr(cube->c_temp, ',') + 1, ft_strlen(cube->c_temp));
	cube->C[2] = ft_atoi(ft_substr(cube->c_temp, 0, ft_strlen(cube->c_temp)));
	free(cube->c_temp);
}

void	init_game(t_cube *cube)
{
	init_rgb(cube);
	if (cube->F[0] < 0 || cube->F[0] > 255 || cube->F[1] < 0
		|| cube->F[1] > 255 || cube->F[2] < 0 || cube->F[2] > 255)
	{
		printf("RGB not valid\n");
		exit_game(cube);
	}
	if (cube->C[0] < 0 || cube->C[0] > 255 || cube->C[1] < 0
		|| cube->C[1] > 255 || cube->C[2] < 0 || cube->C[2] > 255)
	{
		printf("RGB not valid\n");
		exit_game(cube);
	}
	cube->mlx = mlx_init();
	cube->win = mlx_new_window(cube->mlx, WINDOW_W, WINDOW_H, "cub3d");
	cube->map_h = ft_matlen(cube->map);
	cube->map_w = ft_strlen(cube->map[0]);
}
