/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amargiac <amargiac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:55:55 by amargiac          #+#    #+#             */
/*   Updated: 2023/09/12 18:48:14 by amargiac         ###   ########.fr       */
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
		&& argv[i - 4] '.')
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
	while(map[k] != '\0')
		i++;
	y = -1;
	while(map[x][++y] != '\0')
	{
		if(map[x][y] != '1' || map[x][y] != != ' ')
			return(-1);
	}
	while(map[k][++y] != '\0')
	{
		if(map[k][y] != '1' || map[k][y] != != ' ')
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
		strrev = rev_string(map[x])
		if(ft_strchr(map[x], '0') < ft_strchr(map[x], '1'))
			return(-1);
		if(ft_strchr(rev, '0') < ft_strchr(rev, '1'))
			return(-1);
		free(rev);
	}
	return(0);
}

int	checkbordes(t_cube *cube)
{
	
}


void mapchecks(t_cube *cube)
{
	int	x;

	x = 0;
	x += checkbordes_left_right(cube->map);
	x += checkbordes_top_down(cube->map);
	x += checkbordes_mid(cube);
}


