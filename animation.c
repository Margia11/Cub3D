/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andreamargiacchi <andreamargiacchi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:52:30 by gpecci            #+#    #+#             */
/*   Updated: 2023/10/16 12:17:33 by andreamargi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

static void	next_fire(t_cube *cube, t_object *obj)
{
	if (cube->ani == 0)
		obj->tex = &(cube->tex->fire1);
	else if (cube->ani == 1)
		obj->tex = &(cube->tex->fire2);
	else if (cube->ani == 2)
		obj->tex = &(cube->tex->fire3);
	else if (cube->ani == 3)
		obj->tex = &(cube->tex->fire4);
}

void	update_animation(t_cube *cube)
{
	static int	i = ANISPEED;
	t_object	*obj;

	if (i == ANISPEED)
	{
		i = 0;
		obj = cube->objs;
		while (obj)
		{
			next_fire(cube, obj);
			obj = obj->next;
		}
		if (cube->ani == 3)
			cube->ani = 0;
		else
			cube->ani += 1;
	}
	else
		i++;
}

static void	draw_spritino(t_cube *cube, t_drawsprite *spr, t_object *obj,
				double *zbuff)
{
	int				v;
	int				stripe;
	int				d;
	int				tex[2];
	unsigned int	color;

	stripe = spr->drawx[0];
	while (stripe < spr->drawx[1])
	{
		tex[0] = (256 * (stripe - (-spr->spr_w / 2 + spr->spr_screen_x))
				* obj->tex->w / spr->spr_w) / 256;
		if (spr->transf[1] > 0 && spr->transf[1] < zbuff[stripe])
		{
			v = spr->drawy[0] - 1;
			while (++v < spr->drawy[1])
			{
				d = (v) * 256 - WINDOW_H * 128 + spr->spr_h * 128;
				tex[1] = ((d * obj->tex->h) / spr->spr_h) / 256;
				color = get_pixel(&obj->tex->xpm, tex[0], tex[1]);
				if (color & 0x0FFFFFFF)
					my_mlx_pixel_put(cube->img, stripe, v, color);
			}
		}
		stripe++;
	}
}

static void	draw_spritone(t_drawsprite *spr)
{
	spr->spr_h = fabs(WINDOW_H / spr->transf[1]);
	spr->drawy[0] = -spr->spr_h / 2 + WINDOW_H / 2;
	if (spr->drawy[0] < 0)
		spr->drawy[0] = 0;
	spr->drawy[1] = spr->spr_h / 2 + WINDOW_H / 2;
	if (spr->drawy[1] >= WINDOW_H)
		spr->drawy[1] = WINDOW_H - 1;
	spr->spr_w = fabs((WINDOW_H / spr->transf[1]));
	spr->drawx[0] = -spr->spr_w / 2 + spr->spr_screen_x;
	if (spr->drawx[0] < 0)
		spr->drawx[0] = 0;
	spr->drawx[1] = spr->spr_w / 2 + spr->spr_screen_x;
	if (spr->drawx[1] >= WINDOW_W)
		spr->drawx[1] = WINDOW_W - 1;
}

void	draw_fires(t_cube *cube, double *zbuff)
{
	t_object		*obj;
	t_drawsprite	spr;

	obj = cube->sorted;
	while (obj)
	{
		if (obj->dist > .1)
		{
			spr.pos[0] = (obj->x + 0.5) - cube->player->pos[0];
			spr.pos[1] = (obj->y + 0.5) - cube->player->pos[1];
			spr.inv_det = 1.0 / (cube->player->plane[0]
					* cube->player->dir[1]
					- cube->player->dir[0] * cube->player->plane[1]);
			spr.transf[0] = spr.inv_det * (cube->player->dir[1] * spr.pos[0]
					- cube->player->dir[0] * spr.pos[1]);
			spr.transf[1] = spr.inv_det * (-cube->player->plane[1]
					* spr.pos[0]
					+ cube->player->plane[0] * spr.pos[1]);
			spr.spr_screen_x = (((double)(WINDOW_W) / 2.) * (1.
						+ spr.transf[0] / spr.transf[1]));
			draw_spritone(&spr);
			draw_spritino(cube, &spr, obj, zbuff);
		}
		obj = obj->sort;
	}
}
