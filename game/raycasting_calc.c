/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_calc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 21:25:54 by akefeder          #+#    #+#             */
/*   Updated: 2023/10/24 21:39:37 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_3d.h"

void	calc_delta(t_file *file)
{
	if (file->ray->raydirx == 0)
		file->ray->deltastepx = 1e30;
	else
		file->ray->deltastepx = fabs(1 / file->ray->raydirx);
	if (file->ray->raydiry == 0)
		file->ray->deltastepy = 1e30;
	else
		file->ray->deltastepy = fabs(1 / file->ray->raydiry);
}

void	calc_step_side(t_file *file)
{
	if (file->ray->raydirx < 0)
	{
		file->ray->stepx = -1;
		file->ray->sidestepx = (file->player->posx - file->ray->mapx)
			* file->ray->deltastepx;
	}
	else
	{
		file->ray->stepx = 1;
		file->ray->sidestepx = (file->ray->mapx + 1.0 - file->player->posx)
			* file->ray->deltastepx;
	}
	if (file->ray->raydiry < 0)
	{
		file->ray->stepy = -1;
		file->ray->sidestepy = (file->player->posy - file->ray->mapy)
			* file->ray->deltastepy;
	}
	else
	{
		file->ray->stepy = 1;
		file->ray->sidestepy = (file->ray->mapy + 1.0 - file->player->posy)
			* file->ray->deltastepy;
	}
}

void	calc_drawtool(t_file *file)
{
	if (file->ray->side == 0)
		file->ray->perpwalldist = file->ray->sidestepx - file->ray->deltastepx;
	else
		file->ray->perpwalldist = file->ray->sidestepy - file->ray->deltastepy;
	if (file->ray->perpwalldist > 0.001f)
		file->ray->heightline = (int)((SIZEPIC_HEIGHT)
				/ file->ray->perpwalldist);
	else
		file->ray->heightline = (int)((SIZEPIC_HEIGHT) / 0.01f);
	file->ray->drawstart = SIZEPIC_HEIGHT / 2 - file->ray->heightline / 2;
	file->ray->drawend = file->ray->drawstart + file->ray->heightline;
	if (file->ray->drawstart < 0)
		file->ray->drawstart = 0;
	if (file->ray->drawend >= SIZEPIC_HEIGHT)
		file->ray->drawend = SIZEPIC_HEIGHT;
}
