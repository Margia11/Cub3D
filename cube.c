/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpecci <gpecci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:19:33 by andreamargi       #+#    #+#             */
/*   Updated: 2023/09/25 13:02:13 by gpecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

void	free_map(char **mat)
{
	int	i;

	i = 0;
	while(mat[i])
	{
		free(mat[i]);
		i++;
	}
	free(mat);
}

void	print_map(t_cube *cube)
{
	int	i;

	i = 0;
	while(cube->map[i])
	{
		printf("%s\n", cube->map[i]);
		i++;
	}
}

int	argv_check(char *argv)
{
	int	i;

	if (!argv)
		return (0);
	i = 0;
	while (argv[i])
		i++;
	i -= 1;
	if (argv[i] == 'b' && argv[i - 1] == 'u'
		&& argv[i - 2] == 'c' && argv[i - 3] == '.')
		return (1);
	return (0);
}

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

int parse_texture(char *line, t_cube *cube)
{
	if(ft_strncmp(line, "NO", 2) == 0)
	{
		cube->NO = ft_strtrim(line + 3, " \n");
		return (0);
	}
	else if(ft_strncmp(line, "SO", 2) == 0)
	{
		cube->SO = ft_strtrim(line + 3, " \n");
		return (0);
	}
	else if(ft_strncmp(line, "WE", 2) == 0)
	{
		cube->WE = ft_strtrim(line + 3, " \n");
		return (0);
	}
	else if(ft_strncmp(line, "EA", 2) == 0)
	{
		cube->EA = ft_strtrim(line + 3, " \n");
		return (0);
	}
	else if(ft_strncmp(line, "F", 1) == 0)
	{
		cube->F = ft_strtrim(line + 2, " \n");
		return (0);
	}
	else if(ft_strncmp(line, "C", 1) == 0)
	{
		cube->C = ft_strtrim(line + 2, " \n");
		return (0);
	}
	else
		return (-1);
}

void	fill_map(t_cube *cube)
{
	int	i;
	int	j;

	i = 0;
	while(cube->tmp_map[i])
		i++;
	cube->map = malloc (sizeof(char *) * i);
	i = 0;
	j = 0;
	while(cube->tmp_map[i])
	{
		if (parse_texture(cube->tmp_map[i], cube) == -1)
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

int main(int argc, char **argv)
{
	t_cube	cube;

	if (argc == 2)
	{
		read_map(argv[1], &cube);
		fill_textures(&cube);
		fill_map(&cube);
		// if (argv_check(argv[1]) == 1 && checks_map_textures(&cube) == 1)
		// {
		//		gameplay effettivo
		// 		mlx_loop(cube.mlx);
		// }
		// else
		// {
		// 	if (cube.map)
		// 		free_map(&cube);
		// 	printf("Error: Invalid Map\n");
		// 	exit(1);
		// }
	}
	else
	{
		printf("Error: Bad Arguments\n");
		exit(1);
	}
	return (0);
}
