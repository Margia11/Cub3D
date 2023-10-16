/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpecci <gpecci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 13:35:29 by andreamargi       #+#    #+#             */
/*   Updated: 2023/10/16 15:21:58 by gpecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

void	read_map(char *str, t_cube *cube)
{
	int		fd;
	char	*buff;

	fd = open(str, O_RDONLY);
	if (fd == -1)
		return ;
	buff = malloc(sizeof(char) * INT_MAX);
	read(fd, buff, INT_MAX);
	cube->tmp_map = ft_split(buff, '\n');
	free(buff);
	close(fd);
	return ;
}

void	parse_texture(char *line, t_cube *cube)
{
	if (ft_strncmp(line, "NO", 2) == 0)
		cube->nopath = ft_strtrim(line + 3, "\n");
	else if (ft_strncmp(line, "SO", 2) == 0)
		cube->sopath = ft_strtrim(line + 3, "\n");
	else if (ft_strncmp(line, "WE", 2) == 0)
		cube->wepath = ft_strtrim(line + 3, "\n");
	else if (ft_strncmp(line, "EA", 2) == 0)
		cube->eapath = ft_strtrim(line + 3, "\n");
	else if (ft_strncmp(line, "F", 1) == 0)
		cube->f_temp = ft_strtrim(line + 2, "\n");
	else if (ft_strncmp(line, "C", 1) == 0)
		cube->c_temp = ft_strtrim(line + 2, "\n");
}

int	line_texture(char *line)
{
	if (ft_strncmp(line, "NO", 2) == 0)
		return (0);
	else if (ft_strncmp(line, "SO", 2) == 0)
		return (0);
	else if (ft_strncmp(line, "WE", 2) == 0)
		return (0);
	else if (ft_strncmp(line, "EA", 2) == 0)
		return (0);
	else if (ft_strncmp(line, "F", 1) == 0)
		return (0);
	else if (ft_strncmp(line, "C", 1) == 0)
		return (0);
	return (1);
}

void	fill_map(t_cube *cube)
{
	int	i;
	int	j;

	i = 0;
	while (cube->tmp_map[i])
		i++;
	cube->map = malloc (sizeof(char *) * i);
	i = 0;
	j = 0;
	while (cube->tmp_map[i])
	{
		if (line_texture(cube->tmp_map[i]) == 1)
		{
			cube->map[j] = ft_strdup(cube->tmp_map[i]);
			j++;
		}
		i++;
	}
	cube->map[j] = NULL;
	free_map(cube->tmp_map);
}

void	fill_textures(t_cube *cube)
{
	int	i;

	i = 0;
	while (cube->tmp_map[i])
	{
		parse_texture(cube->tmp_map[i], cube);
		i++;
	}
}
