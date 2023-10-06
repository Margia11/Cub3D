/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpecci <gpecci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 12:10:07 by andreamargi       #+#    #+#             */
/*   Updated: 2023/10/06 18:06:32 by gpecci           ###   ########.fr       */
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
	cube->nopath = NULL;
	cube->sopath = NULL;
	cube->wepath = NULL;
	cube->eapath = NULL;
	cube->f_temp = NULL;
	cube->c_temp = NULL;
}

void	init_map(char *str, t_cube *cube, t_player *player)
{
	read_map(str, cube);
	init_textures(cube);
	fill_textures(cube);
	fill_map(cube);
	set_player(player);
	cube->player = player;
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

int	load_text_walls(t_cube *cube, t_tex *tex, char *path)
{
	tex->xpm.img = mlx_xpm_file_to_image(cube->mlx, path,
			&tex->w, &tex->h);
	if (!tex->xpm.img)
		return (1);
	tex->xpm.addr = mlx_get_data_addr(tex->xpm.img,
			&tex->xpm.bits_per_pixel, &tex->xpm.line_length,
			&tex->xpm.endian);
	if (!tex->xpm.addr)
		return (1);
	return (0);
}

void	walls(t_cube *cube)
{
	if (cube->nopath != NULL)
		load_text_walls(cube, &(cube->tex->no), cube->nopath);
	if (cube->sopath != NULL)
		load_text_walls(cube, &(cube->tex->so), cube->sopath);
	if (cube->eapath != NULL)
		load_text_walls(cube, &(cube->tex->ea), cube->eapath);
	if (cube->wepath != NULL)
		load_text_walls(cube, &(cube->tex->we), cube->wepath);
}

char	**full_map(char **map, t_cube *cube)
{
	char	**res;
	int		i;
	int		j;

	i = 0;

	res = malloc(sizeof(char *) * (cube->map_h + 1));
	while (map[i])
	{
		j = 0;
		res[i] = malloc (sizeof(char) * cube->max);
		while (map[i][j])
		{
			if (map[i][j] != ' ')
				res[i][j] = map[i][j];
			else
				res[i][j] = '1';
			j++;
		}
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


static int ft_maxlen(char **map)
{
	int	i;
	int	j;
	int	n;
	int res;

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

static char	**copy_map(char **map, int n)
{
	char	**res;
	int		i;

	i = 0;
	res = malloc(sizeof(char*) * n);
	while (map[i])
	{
		res[i] = ft_strdup(map[i]);
		i++;
	}
	res[i] = NULL;
	return (res);
}

void	init_game(t_cube *cube, t_img *img)
{
	char	**tmp;

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
	cube->max = ft_maxlen(cube->map) + 1;
	cube->map_w = ft_strlen(cube->map[0]);
	tmp = copy_map(cube->map, cube->map_h);
	free_map(cube->map);
	cube->map = full_map(tmp, cube);
	free_map(tmp);
	walls(cube);
	img->img = mlx_new_image(cube->mlx, WINDOW_W, WINDOW_H);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	cube->img = img;
}
