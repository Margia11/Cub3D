/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amargiac <amargiac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:37:01 by amargiac          #+#    #+#             */
/*   Updated: 2023/09/12 18:44:36 by amargiac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
#define CUBE3D_H

#include "get_next_line/get_next_line.h"
#include "libft/libft.h"
#include <unistd.h>
#include <math.h>
#include <stdlib.h>
#include "mlx_linux/mlx.h"
#include <stdio.h>

typedef struct s_cube
{
	char **map;
}	t_cube;

typedef struct s_player
{

}	t_player;

//utils
int	ft_strcmp(char *s1, char *s2);
char	*rev_string(char *s);

//controls1
int map_format(char *argv);
int checkbordes_top_down(char **map);
int checkbordes_left_right(char **map);


#endif
