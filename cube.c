/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andreamargiacchi <andreamargiacchi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:19:33 by andreamargi       #+#    #+#             */
/*   Updated: 2023/09/20 11:55:47 by andreamargi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

int end_game(t_cube *cube)
{
	free_mat(cube->map);
	exit(0);
}

int main(int argc, char **argv)
{
	t_cube	cube;

	if(check_argc(argc) == -1)
		return (-1);
	init_cube(&cube);
	init_player(&cube);
	if(map_format(argv[1]) == -1)
		return (-1);
	read_input(&cube, argv[1], 0);
	//game_init(&cube);
	if(checkelements(&cube) == -1)
		return (-1);
	end_game(&cube);
	return (0);
}
