/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpecci <gpecci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:39:20 by andreamargi       #+#    #+#             */
/*   Updated: 2023/10/16 15:25:30 by gpecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

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
	cube->f[0] = ft_atoi(tmp0);
	tmp1 = ft_substr(cube->f_temp, my_strchr(cube->f_temp, ',') + 1,
			ft_strlen(cube->f_temp));
	cube->f[1] = ft_atoi(tmp1);
	tmp2 = ft_substr(tmp1, my_strchr(tmp1, ',') + 1, ft_strlen(tmp1));
	cube->f[2] = ft_atoi(tmp2);
	free_util(tmp0, tmp1, tmp2);
	tmp0 = ft_substr(cube->c_temp, 0, my_strchr(cube->c_temp, ','));
	cube->c[0] = ft_atoi(tmp0);
	tmp1 = ft_substr(cube->c_temp, my_strchr(cube->c_temp, ',') + 1,
			ft_strlen(cube->c_temp));
	cube->c[1] = ft_atoi(tmp1);
	tmp2 = ft_substr(tmp1, my_strchr(tmp1, ',') + 1, ft_strlen(tmp1));
	cube->c[2] = ft_atoi(tmp2);
	free_util(tmp0, tmp1, tmp2);
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
