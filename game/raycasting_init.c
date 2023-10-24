/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 23:26:13 by akefeder          #+#    #+#             */
/*   Updated: 2023/10/24 22:03:48 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_3d.h"

t_ray	*init_ray(t_file *file)
{
	t_ray	*ray;

	ray = malloc (1 * sizeof(t_ray));
	if (!ray)
		return (NULL);
	ray->mapx = 0;
	ray->mapx = (int)(file->player->posx);
	ray->mapy = 0;
	ray->mapy = (int)(file->player->posy);
	ray->camerax = 0;
	ray->raydirx = 0;
	ray->deltastepx = 0;
	ray->deltastepy = 0;
	ray->stepx = 0;
	ray->stepy = 0;
	ray->sidestepx = 0;
	ray->sidestepy = 0;
	ray->hit = 0;
	ray->side = 0;
	ray->perpwalldist = 0;
	ray->heightline = 0;
	ray->drawstart = 0;
	ray->drawend = 0;
	return (ray);
}

void	init_dir_plan(t_file *file)
{
	if (file->player->orient == 'N')
	{
		file->player->diry = -1;
		file->player->planx = 0.66;
	}
	else if (file->player->orient == 'S')
	{
		file->player->diry = 1;
		file->player->planx = -0.66;
	}
	else if (file->player->orient == 'E')
	{
		file->player->dirx = 1;
		file->player->plany = 0.66;
	}
	else if (file->player->orient == 'W')
	{
		file->player->dirx = -1;
		file->player->plany = -0.66;
	}
}

void	init_component(t_file *file)
{
	file->player->dirx = 0;
	file->player->diry = 0;
	file->player->planx = 0;
	file->player->plany = 0;
	file->player->mvspd = 0.1;
	file->player->rotspeed = 0.033 * 1.8;
	init_dir_plan(file);
}

t_img	select_tex(t_file *file)
{
	if (file->tex.texdir == 'W')
		return (file->img_w);
	else if (file->tex.texdir == 'E')
		return (file->img_e);
	else if (file->tex.texdir == 'N')
		return (file->img_n);
	else
		return (file->img_s);
}

void	init_texture(t_file *file)
{
	if (file->ray->side == 0 && file->ray->raydirx < 0)
		file->tex.texdir = 'W';
	if (file->ray->side == 0 && file->ray->raydirx >= 0)
		file->tex.texdir = 'E';
	if (file->ray->side == 1 && file->ray->raydiry < 0)
		file->tex.texdir = 'N';
	if (file->ray->side == 1 && file->ray->raydiry >= 0)
		file->tex.texdir = 'S';
	file->tex.tex_used = select_tex(file);
	if (file->ray->side == 0)
		file->tex.wallx = file->player->posy + file->ray->perpwalldist
			* file->ray->raydiry;
	else
		file->tex.wallx = file->player->posx + file->ray->perpwalldist
			* file->ray->raydirx;
	file->tex.wallx = file->tex.wallx - floor((file->tex.wallx));
}
