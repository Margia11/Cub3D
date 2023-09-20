/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andreamargiacchi <andreamargiacchi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 13:35:29 by andreamargi       #+#    #+#             */
/*   Updated: 2023/09/20 17:32:51 by andreamargi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

void read_input(t_cube *textures, char **line, int fd)
{
	*line = get_next_line(fd);
	while(*line)
	{
		if(!ft_strncmp(*line, "\n", 1))
		{
			gnl(*line, fd);
			continue;
		}
		if(!parse_texture(*line, textures))
			return ;
		if(textures->no && textures->so && textures->we && textures->ea
			&& textures->F && textures->C)
			break;
		free(*line);
		*line = get_next_line(fd);
	}
	check_textures(textures);
	if(!parse_map(textures, line, fd))
	 	return ;
	return ;
}

int parse_texture(char *line, t_cube *textures)
{
	if(!ft_strncmp(line, "NO", 2))
		textures->no = ft_strtrim(line + 3, " \n");
	else if(!ft_strncmp(line, "SO", 2))
		textures->so = ft_strtrim(line + 3, " \n");
	else if(!ft_strncmp(line, "WE", 2))
		textures->we = ft_strtrim(line + 3, " \n");
	else if(!ft_strncmp(line, "EA", 2))
		textures->ea = ft_strtrim(line + 3, " \n");
	else if(!ft_strncmp(line, "F", 1))
		textures->F = *ft_strtrim(line + 2, " \n");
	else if(!ft_strncmp(line, "C", 1))
		textures->C = *ft_strtrim(line + 2, " \n");
	else
		printf("Error Wrong texture\n");
	return (0);
}

int	parse_map(t_cube *textures, char **line, int fd)
{
	int		i;
	char	**buff;
	//int		map_size;

	buff = malloc(sizeof(char *) * (99 + 1));
	i = 0;
	gnl(*line, fd);
	// while(*line)
	// 	*line++;
	while(*line)
		buff[i++] = ft_strdup(*line++);
	textures->map = ft_split(*buff, '\n');
	free(buff);
	return (0);
}
