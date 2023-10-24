/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 22:53:41 by akefeder          #+#    #+#             */
/*   Updated: 2023/10/24 01:51:57 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_3d.h"

t_ray	*init_ray(t_file *file)
{
	t_ray	*ray;

	ray = malloc (1 * sizeof(t_ray));
	if (!ray)
		return(NULL);
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


void	calc_delta(t_file *file)
{
	if (file->ray->raydirx == 0)
		file->ray->deltastepx = 1e30;
	else
		file->ray->deltastepx = fabs(1 / file->ray->raydirx);
	if(file->ray->raydiry == 0)
		file->ray->deltastepy = 1e30;
	else
		file->ray->deltastepy = fabs(1 / file->ray->raydiry);
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

char 	get_map(t_file *file, int x, int y)
{
	if (x < 0 || y < 0 || x >= SIZEPIC_WIDTH || y >= SIZEPIC_HEIGHT)
		return ('1');
	return (file->map->map[y][x]);
}

void	find_hit(t_file *file)
{
	//printf("sidestepx = %f, sidestepy = %f, deltastepx = %f, deltastepy = %f, mapx = %i, mapy = %i\n", file->ray->sidestepx, file->ray->sidestepy, file->ray->deltastepx, file->ray->deltastepy, file->ray->mapx, file->ray->mapy);
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
		if (get_map(file, file->ray->mapx, file->ray->mapy) == '1')
			file->ray->hit = 1;
	}
	//printf("mapx = %i, mapy = %i\n", file->ray->mapx, file->ray->mapy);
}

void	calc_drawtool(t_file *file)
{
	if (file->ray->side == 0)
		//file->ray->perpwalldist = (file->ray->mapx - file->player->posx + (1 - file->ray->stepx) / 2) / file->ray->raydirx;
		file->ray->perpwalldist = file->ray->sidestepx - file->ray->deltastepx;
	else
		//file->ray->perpwalldist = (file->ray->mapy - file->player->posy + (1 - file->ray->stepy) / 2) / file->ray->raydiry;
		file->ray->perpwalldist = file->ray->sidestepy - file->ray->deltastepy;
	if (file->ray->perpwalldist > 0.001f)
		file->ray->heightline = (int)((SIZEPIC_HEIGHT) / file->ray->perpwalldist);
	else
		file->ray->heightline = (int)((SIZEPIC_HEIGHT) / 0.01f);
	file->ray->drawstart = SIZEPIC_HEIGHT / 2 - file->ray->heightline / 2;
	file->ray->drawend =  file->ray->drawstart + file->ray->heightline;
	if (file->ray->drawstart < 0)
		file->ray->drawstart = 0;
	if (file->ray->drawend >= SIZEPIC_HEIGHT)
		file->ray->drawend = SIZEPIC_HEIGHT;
}

void	draw_texture(t_file *file, double x, int i)
{	
	init_texture(file);
	file->tex.texx = (int)(file->tex.wallx * (double)(file->tex.tex_used.width));
	if (file->ray->side == 0 && file->ray->raydirx > 0)
		file->tex.texx = file->tex.tex_used.width - file->tex.texx - 1;
	if (file->ray->side == 1 && file->ray->raydiry < 0)
		file->tex.texx = file->tex.tex_used.width - file->tex.texx - 1;
	file->tex.step = 1.0f * file->tex.tex_used.height / file->ray->heightline;
	file->tex.texpos = (file->ray->drawstart - SIZEPIC_HEIGHT / 2 + file->ray->heightline / 2) * file->tex.step;
	while (i < file->ray->drawend)
	{
		file->tex.texy = (int)(file->tex.texpos) & (file->tex.tex_used.height - 1);
		file->tex.texpos = file->tex.texpos + file->tex.step;
		my_mlx_pixel_put(&(file->img_minimap), x, i, my_mlx_pixel_take(&(file->tex.tex_used), file->tex.texx, file->tex.texy));
		i++;
	}
}

void	draw_verticale_line(t_file *file, double x)
{
	int	i;

	i = 0;
	// if (file->ray->drawstart < 0 || file->ray->drawend < 0)
	// 	return;
	while (i < file->ray->drawstart)
	{
		//printf("heightline : %i, perpwalldist = %f, drawstart : %i, drawend : %i, i = %i, x = %f\n", file->ray->heightline, file->ray->perpwalldist, file->ray->drawstart, file->ray->drawend, i, x);
		my_mlx_pixel_put((&file->img_minimap), (int)x, i, file->C);
		i++;
	}
	// while (i < file->ray->drawend)
	// {
	// 	my_mlx_pixel_put((&file->img_minimap), (int)x, i, 0x00FF0000);
	// 	i++;
	// }
	if (i <= file->ray->drawend)
		draw_texture(file, x, i);
	i = file->ray->drawend;
	while (i < SIZEPIC_HEIGHT)
	{
		//printf("heightline : %i, perpwalldist = %f, drawstart : %i, drawend : %i, i = %i, x = %f\n", file->ray->heightline, file->ray->perpwalldist, file->ray->drawstart, file->ray->drawend, i, x);
		my_mlx_pixel_put((&file->img_minimap), (int)x, i, file->F);
		i++;
	}
}

void	draw_clean_line(t_file *file)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < SIZEPIC_HEIGHT)
	{
		j = 0;
		while (j < SIZEPIC_WIDTH)
		{
			my_mlx_pixel_put((&file->img_minimap), j, i, 0x00000000);
			j++;
		}
		//printf("heightline : %i, perpwalldist = %f, drawstart : %i, drawend : %i, i = %i, x = %f\n", file->ray->heightline, file->ray->perpwalldist, file->ray->drawstart, file->ray->drawend, i, x);
		i++;
	}
}

void raycasting(t_file *file)
{
	double x;
	
	x = 0;
	while (x < SIZEPIC_WIDTH)
	{
		file->ray = init_ray(file);
		// if (file->ray == NULL)
		// 	return (ERROR);
		//file->ray->camerax = 2 * x / (double)(SIZEPIC_WIDTH) - 1;
		file->ray->camerax = x / (double)SIZEPIC_WIDTH * 2.0 - 1.0;
		file->ray->raydirx = file->player->dirx + file->player->planx * file->ray->camerax;
		file->ray->raydiry = file->player->diry + file->player->plany * file->ray->camerax;
		calc_delta(file);
		calc_step_side(file);
		find_hit(file);
		calc_drawtool(file);
		draw_verticale_line(file, x);
		free(file->ray);
		file->ray = NULL;
		x++;
	}
	mlx_put_image_to_window(file->mlx, file->win, file->img_minimap.img, 0, 0);
}