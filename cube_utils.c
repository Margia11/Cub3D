/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpecci <gpecci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:43:55 by gpecci            #+#    #+#             */
/*   Updated: 2023/10/16 14:44:15 by gpecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

void	hook(t_cube *cube)
{
	mlx_hook(cube->win, 17, 0, exit_game, cube);
	mlx_hook(cube->win, 2, 1L << 0, keypress, cube);
	mlx_hook(cube->win, 6, 0, mouse_filter, cube);
	mlx_loop_hook(cube->mlx, game_loop, cube);
	mlx_loop(cube->mlx);
}
