/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 22:53:41 by akefeder          #+#    #+#             */
/*   Updated: 2023/10/22 13:55:17 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_3d.h"

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



t_ray	*init_ray(t_file *file)
{
	t_ray	*ray;

	ray = malloc (1 * sizeof(t_ray));
	if (!ray)
		return(NULL);
	ray->mapx = (int)(file->player->posx);
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

void	init_component(t_file *file)
{
	file->player->dirx = 0;
	file->player->diry = 0;
	file->player->planx = 0;
	file->player->plany = 0;
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
		file->ray->sidestepx = (file->player->posx - file->ray->mapx) * file->ray->deltastepx;
	}
	else
	{
		file->ray->stepx = 1;
		file->ray->sidestepx = (file->ray->mapx + 1.0 - file->player->posx) * file->ray->deltastepx;
	}
	if (file->ray->raydiry < 0)
	{
		file->ray->stepy = -1;
		file->ray->sidestepy = (file->player->posy - file->ray->mapy) * file->ray->deltastepy;
	}
	else
	{
		file->ray->stepy = 1;
		file->ray->sidestepy = (file->ray->mapy + 1.0 - file->player->posy) * file->ray->deltastepy;
	}
}

void	find_hit(t_file *file)
{
	while (file->ray->hit == 0)
	{
		if (file->ray->sidestepx < file->ray->sidestepy)
		{
			file->ray->sidestepx += file->ray->deltastepx;
			file->ray->mapx += file->ray->stepx;
			file->ray->side = 0;
		}
		else
		{
			file->ray->sidestepy += file->ray->deltastepy;
			file->ray->mapy += file->ray->stepy;
			file->ray->side = 1;
		}
		if (file->map->map[file->ray->mapx][file->ray->mapy] == '1')
			file->ray->hit = 1;
		
	}
}

void	calc_drawtool(t_file *file)
{
	if (file->ray->side == 0)
		file->ray->perpwalldist = (file->ray->mapx - file->player->posx + (1 - file->ray->stepx) / 2) / file->ray->raydirx;
	else
		file->ray->perpwalldist = (file->ray->mapy - file->player->posy + (1 - file->ray->stepy) / 2) / file->ray->raydiry;
	file->ray->heightline = (int)((file->map->maplen * SIZEPIC_HEIGHT) / file->ray->perpwalldist);
	file->ray->drawstart = (-1 * file->ray->heightline) / 2 + (file->map->maplen * SIZEPIC_HEIGHT) / 2;
	if (file->ray->drawstart < 0)
		file->ray->drawstart = 0;
	file->ray->drawend =  (file->ray->heightline) / 2 + (file->map->maplen * SIZEPIC_HEIGHT) / 2;
	if (file->ray->drawend >= (file->map->maplen * SIZEPIC_HEIGHT))
		file->ray->drawend = (file->map->maplen * SIZEPIC_HEIGHT) - 1;
}

void	draw_verticale_line(t_file *file, double x)
{
	int	i;

	i = file->ray->drawstart;
	while (i < file->ray->drawend)
	{
		my_mlx_pixel_put((&file->img_minimap), (int)x, i, 0x00FF0000);
		i++;
	}
}

void raycasting(t_file *file)
{
	double x;

	x = 0;
	init_component(file); // potentiellement a deplacer dans l'appelant pour pouvoir reexecuter la commande de raycasting en independant
	while (x < file->map->len * SIZEPIC_WIDTH) // modifiable par la width tout court si ecran avec resolution fixe
	{
		file->ray = init_ray(file);
		// if (file->ray == NULL)
		// 	return (ERROR);
		file->ray->camerax = 2 * x / (file->map->len * SIZEPIC_WIDTH) - 1;
		file->ray->raydirx = file->player->dirx + file->player->planx * file->ray->camerax;
		file->ray->raydiry = file->player->diry + file->player->plany * file->ray->camerax;
		calc_delta(file);
		calc_step_side(file);
		find_hit(file);
		calc_drawtool(file);
		draw_verticale_line(file, x);
		free(file->ray);
		x++;
	}
	mlx_put_image_to_window(file->mlx, file->win, file->img_minimap.img, 0, 0);
}