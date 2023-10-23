/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:03:17 by akefeder          #+#    #+#             */
/*   Updated: 2023/10/23 15:28:02 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_3d.h"

void	vec_rotate(double *x, double *y, double rad)
{
	double const	xc = *x;
	double const	yc = *y;

	*x = xc * cos(rad) - yc * sin(rad);
	*y = xc * sin(rad) + yc * cos(rad);
}

void	rotate_right(t_file *file)
{
	vec_rotate(&file->player->dirx, &file->player->diry, file->player->rotspeed);
	vec_rotate(&file->player->planx, &file->player->plany, file->player->rotspeed);
	raycasting(file);
}

void	rotate_left(t_file *file)
{
	vec_rotate(&file->player->dirx, &file->player->diry, -(file->player->rotspeed));
	vec_rotate(&file->player->planx, &file->player->plany, -(file->player->rotspeed));
	raycasting(file);
}
