/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 22:53:41 by akefeder          #+#    #+#             */
/*   Updated: 2023/10/24 21:54:41 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_3d.h"

char	get_map(t_file *file, int x, int y)
{
	if (x < 0 || y < 0 || x >= SIZEPIC_WIDTH || y >= SIZEPIC_HEIGHT)
		return ('1');
	return (file->map->map[y][x]);
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
		if (get_map(file, file->ray->mapx, file->ray->mapy) == '1')
			file->ray->hit = 1;
	}
}

void	draw_texture(t_file *file, double x, int i)
{	
	init_texture(file);
	file->tex.texx = (int)(file->tex.wallx
			* (double)(file->tex.tex_used.width));
	if (file->ray->side == 0 && file->ray->raydirx > 0)
		file->tex.texx = file->tex.tex_used.width - file->tex.texx - 1;
	if (file->ray->side == 1 && file->ray->raydiry < 0)
		file->tex.texx = file->tex.tex_used.width - file->tex.texx - 1;
	file->tex.step = 1.0f * file->tex.tex_used.height / file->ray->heightline;
	file->tex.texpos = (file->ray->drawstart - SIZEPIC_HEIGHT / 2
			+ file->ray->heightline / 2) * file->tex.step;
	while (i < file->ray->drawend)
	{
		file->tex.texy = (int)(file->tex.texpos) % (file->tex.tex_used.height);
		file->tex.texpos = file->tex.texpos + file->tex.step;
		my_mlx_pixel_put(&(file->img_map), x, i,
			my_mlx_pixel_take(&(file->tex.tex_used), file->tex.texx,
				file->tex.texy));
		i++;
	}
}

void	draw_verticale_line(t_file *file, double x)
{
	int	i;

	i = 0;
	while (i < file->ray->drawstart)
	{
		my_mlx_pixel_put((&file->img_map), (int)x, i, file->ceil);
		i++;
	}
	if (i <= file->ray->drawend)
		draw_texture(file, x, i);
	i = file->ray->drawend;
	while (i < SIZEPIC_HEIGHT)
	{
		my_mlx_pixel_put((&file->img_map), (int)x, i, file->floor);
		i++;
	}
}

int	raycasting(t_file *file)
{
	double	x;

	x = 0;
	while (x < SIZEPIC_WIDTH)
	{
		file->ray = init_ray(file);
		if (file->ray == NULL)
			return (ERROR);
		file->ray->camerax = x / (double)SIZEPIC_WIDTH * 2.0 - 1.0;
		file->ray->raydirx = file->player->dirx + file->player->planx
			* file->ray->camerax;
		file->ray->raydiry = file->player->diry + file->player->plany
			* file->ray->camerax;
		calc_delta(file);
		calc_step_side(file);
		find_hit(file);
		calc_drawtool(file);
		draw_verticale_line(file, x);
		free(file->ray);
		file->ray = NULL;
		x++;
	}
	mlx_put_image_to_window(file->mlx, file->win, file->img_map.img, 0, 0);
	return (OK);
}
