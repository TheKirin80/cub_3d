/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 22:53:41 by akefeder          #+#    #+#             */
/*   Updated: 2023/10/22 21:55:42 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_3d.h"

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
	file->ray->heightline = (int)((SIZEPIC_HEIGHT) / file->ray->perpwalldist)
	file->ray->drawstart = (-1 * file->ray->heightline) / 2 + (SIZEPIC_HEIGHT) / 2;
	//print_ray(file, "cherche ERREUR");
	if (file->ray->drawstart < 0)
		file->ray->drawstart = 0;
	file->ray->drawend =  (file->ray->heightline) / 2 + (SIZEPIC_HEIGHT) / 2;
	if (file->ray->drawend >= (SIZEPIC_HEIGHT))
		file->ray->drawend = (SIZEPIC_HEIGHT) - 1;
}

void	draw_verticale_line(t_file *file, double x)
{
	int	i;

	i = 0;
	while (i < file->ray->drawstart)
	{
		//printf("heightline : %i, perpwalldist = %f, drawstart : %i, drawend : %i, i = %i, x = %f\n", file->ray->heightline, file->ray->perpwalldist, file->ray->drawstart, file->ray->drawend, i, x);
		my_mlx_pixel_put((&file->img_minimap), (int)x, i, file->F);
		i++;
	}
	i = file->ray->drawstart;
	while (i < file->ray->drawend)
	{
		//printf("heightline : %i, perpwalldist = %f, drawstart : %i, drawend : %i, i = %i, x = %f\n", file->ray->heightline, file->ray->perpwalldist, file->ray->drawstart, file->ray->drawend, i, x);
		my_mlx_pixel_put((&file->img_minimap), (int)x, i, 0x00FF0000);
		i++;
	}
	i = file->ray->drawend;
	while (i < SIZEPIC_HEIGHT - 1)
	{
		//printf("heightline : %i, perpwalldist = %f, drawstart : %i, drawend : %i, i = %i, x = %f\n", file->ray->heightline, file->ray->perpwalldist, file->ray->drawstart, file->ray->drawend, i, x);
		my_mlx_pixel_put((&file->img_minimap), (int)x, i, file->C);
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
	draw_clean_line(file);
 // potentiellement a deplacer dans l'appelant pour pouvoir reexecuter la commande de raycasting en independant
	while (x < SIZEPIC_WIDTH) // modifiable par la width tout court si ecran avec resolution fixe
	{
		file->ray = init_ray(file);
		// if (file->ray == NULL)
		// 	return (ERROR);
		//file->ray->camerax = 2 * x / (double)(SIZEPIC_WIDTH) - 1;
		file->ray->camerax = x / (double)SIZEPIC_WIDTH * 2.0 - 1.0;
		//printf("canerax = %f\n", file->ray->camerax);
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