/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 17:34:09 by akefeder          #+#    #+#             */
/*   Updated: 2023/03/24 08:38:49 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_3d.h"

int	load_img(t_file *file)
{
    
	file->img_north->img = mlx_xpm_file_to_image(file->mlx, file->north
        , &file->img_north->img_width, &file->img_north->img_height);
	file->img_south->img = mlx_xpm_file_to_image(file->mlx, file->south
        , &file->img_south->img->img_width, &file->img_south->img_height);
	file->img_west->img = mlx_xpm_file_to_image(file->mlx, file->west
        , &file->img_west->img->img_width, &file->img_west->img_height);
    file->img_east->img = mlx_xpm_file_to_image(file->mlx, file->east
        , &file->img_east->img->img_width, &file->img_east->img_height);
	if (!file->img_north || !file->img_south || !file->img_west || !file->east)
		return (ERROR);
	return (OK);
}

int	charg_file(t_file *file)
{
	file->mlx = mlx_init();
	if (!file->mlx)
		return (ERROR);
	// file->win = mlx_new_window(file->mlx, file->map->len * SIZEPIC,
	// 		file->map->maplen * SIZEPIC, "cub_3d");
	// if (!file->win)
	// 	return (ERROR);
	if (load_img(file) == ERROR)
		return (ERROR);
	return (OK);
}

