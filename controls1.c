/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andreamargiacchi <andreamargiacchi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:55:55 by amargiac          #+#    #+#             */
/*   Updated: 2023/09/13 16:18:54 by andreamargi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

int map_format(char *argv)
{
	int	i;

	i = 0;
	if(!argv)
		return (0);
	while(argv[i] != '\0')
		i++;
	if(argv[i - 3] != 'c' && argv[i - 2] != 'u' && argv[i - 1] != 'b'
		&& argv[i - 4] != '.')
		return (-1);
	return (0);
}

int checkbordes_top_down(char **map)
{
	int	x;
	int	y;
	int	k;

	x = 0;
	k = 0;
	while(map[k] != NULL)
		k++;
	y = -1;
	while(map[x][++y] != '\0')
	{
		if(map[x][y] != '1' || map[x][y] != ' ')
			return(-1);
	}
	while(map[k][++y] != '\0')
	{
		if(map[k][y] != '1' || map[k][y] != ' ')
			return(-1);
	}
	return(0);
}

int checkbordes_left_right(char **map)
{
	int		x;
	char	*strrev;

	x = -1;
	while(map[++x] != NULL)
	{
		strrev = rev_string(map[x]);
		if(ft_strchr(map[x], '0') < ft_strchr(map[x], '1'))
			return(-1);
		if(ft_strchr(strrev, '0') < ft_strchr(strrev, '1'))
			return(-1);
		free(strrev);
	}
	return(0);
}
//controllo che intorno allo 0 non ci siano spazi
int	checkbordes_mid(t_cube *cube)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while(cube->map[x] != NULL)
	{
		while(cube->map[x][y] != '\0')
		{
			if(cube->map[x][y] == '0' && cube->map[x][y + 1] == ' ')
				return(-1);
			if(cube->map[x][y] == '0' && cube->map[x][y - 1] == ' ')
				return(-1);
			if(cube->map[x][y] == '0' && cube->map[x + 1][y] == ' ')
				return(-1);
			if(cube->map[x][y] == '0' && cube->map[x - 1][y] == ' ')
				return(-1);
			y++;
		}
		x++;
	}
	return(0);
}

void mapchecks(t_cube *cube)
{
	if(checkbordes_top_down(cube->map) == -1)
	{
		printf("Error Map not closed on top or bottom\n");
		exit(0);
	}
	if(checkbordes_left_right(cube->map) == -1)
	{
		printf("Error Map not closed on left or right\n");
		exit(0);
	}
	if(checkbordes_mid(cube) == -1)
	{
		printf("Error Map not closed in the middle\n");
		exit(0);
	}
}
