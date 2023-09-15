/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andreamargiacchi <andreamargiacchi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:19:33 by andreamargi       #+#    #+#             */
/*   Updated: 2023/09/15 14:15:20 by andreamargi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

int main(int argc, char **argv)
{
	t_cube	cube;

	init_cube(&cube);
	init_player(&cube);
	if(check_argc(argc) == -1)
		return (-1);
	if(map_format(argv[1]) == -1)
		return (-1);
	read_input(&cube);
	//game_init(&cube);
	if(checkelements(&cube) == -1)
		return (-1);
	return (0);
}
