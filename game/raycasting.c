/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 22:53:41 by akefeder          #+#    #+#             */
/*   Updated: 2023/10/22 00:36:19 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3d.h"

void	init_dir_plan(t_file *file)
{
	if (file->player->orient == 'N')
	{
		file->player->dirx = -1;
		file->player->plany = 0.66;
	}
	else if (file->player->orient == 'S')
	{
		file->player->dirx = 1;
		file->player->plany = -0.66;
	}
	else if (file->player->orient == 'W')
	{
		file->player->diry = -1;
		file->player->planx = -0.66;
	}
	else if (file->player->orient == 'E')
	{
		file->player->diry = 1;
		file->player->planx = 0.66;
	}
}



t_ray	*init_ray()
{
	t_ray	*ray;

	ray = malloc (1 * sizeof(t_ray));
	if (!ray)
		return(NULL);
	ray->camerax = 0;
	ray->raydirx = 0;
	ray->deltastepx = 0;
	ray->deltastepy = 0;
	ray->stepx = 0;
	ray->stepy = 0;
	ray->sidestepx = 0;
	ray->sidestepy = 0;
	return (ray);
}

void	init_component(t_file *file)
{
	file->player->dirx = 0;
	file->player->diry = 0;
	file->player->planx = 0;
	file->player->plany = 0;
	file->ray = init_ray();
	if (file->ray == NULL)
		return (ERROR);
	init_dir_plan(file);
}
void	calc_delta(t_file *file)
{
	if (file->ray->raydirx == 0)
	{
		file->ray->deltastepx = 1;
		file->ray->deltastepy = 0;
	}
	else if(file->ray->raydiry == 0)
	{
		file->ray->deltastepx = 0;
		file->ray->deltastepy = 1;
	}
	else
	{
		file->ray->deltastepx = sqrt(1 + (file->ray->raydiry * file->ray->raydiry) / (file->ray->raydirx * file->ray->raydirx));
		file->ray->deltastepy = sqrt(1 + (file->ray->raydirx * file->ray->raydirx) / (file->ray->raydiry * file->ray->raydiry));
	}
}

void	calc_step_side(t_file *file)
{
	if (file->ray->raydirx < 0)
	{
		file->ray->stepx = -1;
		file->ray->sidedistx = (file->player->posx - file->player->mapx) * file->ray->deltastepx;
	}
	else
	{
		file->ray->stepx = 1;
		file->ray->sidedistx = (file->player->mapx + 1.0 - file->player->posx) * file->ray->deltastepx;
	}
	if (file->ray->raydiry < 0)
	{
		file->ray->stepy = -1;
		file->ray->sidedisty = (file->player->posy - file->player->mapy) * file->ray->deltastepy;
	}
	else
	{
		file->ray->stepy = 1;
		file->ray->sidedisty = (file->player->mapy + 1.0 - file->player->posy) * file->ray->deltastepy;
	}
}
void raycasting(t_file *file)
{
	double x;

	x = 0;
	init_component(t_file); // potentiellement a deplacer dans l'appelant pour pouvoir reexecuter la commande de raycasting en independant
	while (x < file->map->len * SIZEPIC_WIDTH) // modifiable par la width tout court si ecran avec resolution fixe
	{
		file->ray->camerax = 2 * x / (file->map->len * SIZEPIC_WIDTH) - 1;
		file->ray->raydirx = file->player->dirx + file->player->planx * file->ray->camerax;
		file->ray->raydiry = file->player->diry + file->player->plany * file->ray->camerax;
    	mapX = (int)file->player->posx;
    	mapY = (int)file->player->posy;
		calc_delta(file);
		calc_step_side(file);
		
	}
}