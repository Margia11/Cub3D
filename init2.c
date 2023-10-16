/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andreamargiacchi <andreamargiacchi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:39:20 by andreamargi       #+#    #+#             */
/*   Updated: 2023/10/16 13:01:26 by andreamargi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

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
	char	*tmp0;
	char	*tmp1;
	char	*tmp2;

	init_rgb_utils(cube);
	tmp0 = ft_substr(cube->f_temp, 0, my_strchr(cube->f_temp, ','));
	cube->F[0] = ft_atoi(tmp0);
	tmp1 = ft_substr(cube->f_temp, my_strchr(cube->f_temp, ',') + 1, ft_strlen(cube->f_temp));
	cube->F[1] = ft_atoi(tmp1);
	tmp2 = ft_substr(tmp1, my_strchr(tmp1, ',') + 1, ft_strlen(tmp1));
	cube->F[2] = ft_atoi(tmp2);
	free(cube->f_temp);
	free(tmp0);
	free(tmp1);
	free(tmp2);
	tmp0 = ft_substr(cube->c_temp, 0, my_strchr(cube->c_temp, ','));
	cube->C[0] = ft_atoi(tmp0);
	tmp1 = ft_substr(cube->c_temp, my_strchr(cube->c_temp, ',') + 1, ft_strlen(cube->c_temp));
	cube->C[1] = ft_atoi(tmp1);
	tmp2 = ft_substr(tmp1, my_strchr(tmp1, ',') + 1, ft_strlen(tmp1));
	cube->C[2] = ft_atoi(tmp2);
	free(cube->c_temp);
	free(tmp0);
	free(tmp1);
	free(tmp2);
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

void	walls(t_cube *cube, t_textures *tex)
{
	cube->tex = tex;
	if (cube->nopath != NULL)
		load_text_walls(cube, &(cube->tex->no), cube->nopath);
	if (cube->sopath != NULL)
		load_text_walls(cube, &(cube->tex->so), cube->sopath);
	if (cube->eapath != NULL)
		load_text_walls(cube, &(cube->tex->ea), cube->eapath);
	if (cube->wepath != NULL)
		load_text_walls(cube, &(cube->tex->we), cube->wepath);
}
