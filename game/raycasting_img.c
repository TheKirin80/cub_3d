/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_img.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 21:40:50 by akefeder          #+#    #+#             */
/*   Updated: 2023/10/24 21:57:32 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_3d.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < SIZEPIC_WIDTH && y >= 0 && y < SIZEPIC_HEIGHT)
	{
		dst = data->addr + (y * data->ll + x * (data->bpp / 8));
		*(unsigned int *)dst = color;
	}
}

int	my_mlx_pixel_take(t_img *data, int x, int y)
{
	char	*dst;
	int		color;

	color = 0;
	if (x >= 0 && x < data->width && y >= 0 && y < data->height)
	{
		dst = data->addr + (y * data->ll + x * (data->bpp / 8));
		color = *(unsigned int *)dst;
	}
	return (color);
}

void	load_addr(t_file *file)
{
	file->img_n.addr = mlx_get_data_addr(file->img_n.img,
			&(file->img_n.bpp), &(file->img_n.ll), &(file->img_n.endian));
	file->img_s.addr = mlx_get_data_addr(file->img_s.img,
			&(file->img_s.bpp), &(file->img_s.ll), &(file->img_s.endian));
	file->img_e.addr = mlx_get_data_addr(file->img_e.img,
			&(file->img_e.bpp), &(file->img_e.ll), &(file->img_e.endian));
	file->img_w.addr = mlx_get_data_addr(file->img_w.img,
			&(file->img_w.bpp), &(file->img_w.ll), &(file->img_w.endian));
	file->img_map.addr = mlx_get_data_addr(file->img_map.img,
			&(file->img_map.bpp), &(file->img_map.ll), &(file->img_map.endian));
}

int	load_img(t_file *file)
{
	file->img_n.img = mlx_xpm_file_to_image(file->mlx, file->north,
			&(file->img_n.width), &(file->img_n.height));
	file->img_s.img = mlx_xpm_file_to_image(file->mlx, file->south,
			&(file->img_s.width), &(file->img_s.height));
	file->img_e.img = mlx_xpm_file_to_image(file->mlx, file->east,
			&(file->img_e.width), &(file->img_e.height));
	file->img_w.img = mlx_xpm_file_to_image(file->mlx, file->west,
			&(file->img_w.width), &(file->img_w.height));
	file->img_map.img = mlx_new_image(file->mlx, SIZEPIC_WIDTH,
			SIZEPIC_HEIGHT);
	if (!file->img_n.img || !file->img_s.img || !file->img_e.img
		|| !file->img_w.img || !file->img_map.img)
		return (ERROR);
	load_addr(file);
	return (OK);
}
