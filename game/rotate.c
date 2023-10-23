/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:03:17 by akefeder          #+#    #+#             */
/*   Updated: 2023/10/23 13:49:55 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_3d.h"

// void	vec_rotate(float *x, float *y, float rad)
// {
// 	float const	xc = *x;
// 	float const	yc = *y;

// 	*x = xc * cos(rad) - yc * sin(rad);
// 	*y = xc * sin(rad) + yc * cos(rad);
// }

// void	rotate_vec(t_file *file, double rotspeed)
// {
// 	double const	odirx = t_file->player->dirx;
// 	double const	oplanx = t_file->player->planx;

// 	*x = xc * cos() - yc * sin(rad);
// 	*y = xc * sin(rad) + yc * cos(rad);
// }

void	rotate_right(t_file *file)
{
	double const	odirx = file->player->dirx;
	double const	oplanx = file->player->planx;

	file->player->dirx = odirx * cos(file->player->rotspeed) - file->player->diry * sin(file->player->rotspeed);
	file->player->diry = odirx * sin(file->player->rotspeed) + file->player->diry * cos(file->player->rotspeed);
	file->player->planx = oplanx * cos(file->player->rotspeed) - file->player->plany * sin(file->player->rotspeed);
	file->player->plany = oplanx* sin(file->player->rotspeed) + file->player->plany * cos(file->player->rotspeed);
	raycasting(file);
}

void	rotate_left(t_file *file)
{
	double const	odirx = file->player->dirx;
	double const	oplanx = file->player->planx;

	file->player->dirx = odirx * cos(-(file->player->rotspeed)) - file->player->diry * sin(-(file->player->rotspeed));
	file->player->diry = odirx * sin(-(file->player->rotspeed)) + file->player->diry * cos(-(file->player->rotspeed));
	file->player->planx = oplanx * cos(-(file->player->rotspeed)) - file->player->plany * sin(-(file->player->rotspeed));
	file->player->plany = oplanx* sin(-(file->player->rotspeed)) + file->player->plany * cos(-(file->player->rotspeed));
	raycasting(file);
}
