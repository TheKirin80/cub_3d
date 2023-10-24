/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gest_close.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 03:59:01 by akefeder          #+#    #+#             */
/*   Updated: 2023/10/24 22:08:45 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_3d.h"

void	destroy_img(t_file *file)
{
	if (file->img_n.img)
		mlx_destroy_image(file->mlx, file->img_n.img);
	if (file->img_s.img)
		mlx_destroy_image(file->mlx, file->img_s.img);
	if (file->img_e.img)
		mlx_destroy_image(file->mlx, file->img_e.img);
	if (file->img_w.img)
		mlx_destroy_image(file->mlx, file->img_w.img);
	if (file->img_map.img)
		mlx_destroy_image(file->mlx, file->img_map.img);
}

void	free_direction(t_file *file)
{
	if (file->north != NULL)
		free(file->north);
	if (file->south != NULL)
		free(file->south);
	if (file->west != NULL)
		free(file->west);
	if (file->east != NULL)
		free(file->east);
}

void	free_map(t_file *file)
{
	int	i;

	i = 0;
	if (file->map->map != NULL)
	{
		while (file->map->map[i] != NULL)
		{
			free(file->map->map[i]);
			i++;
		}
		free(file->map->map);
	}
	if (file->map != NULL)
		free(file->map);
}

void	free_file(t_file *file)
{
	free_direction(file);
	free_tmp(file->tmp);
	destroy_img(file);
	if (file->win)
		mlx_destroy_window(file->mlx, file->win);
	file->win = NULL;
	if (file->mlx)
		mlx_destroy_display(file->mlx);
	if (file->mlx)
		free(file->mlx);
	if (file->map != NULL)
		free_map(file);
	if (file->player != NULL)
		free(file->player);
	if (file->ray != NULL)
		free(file->ray);
}

int	gest_close(t_file *file)
{
	free_file(file);
	exit(0);
}
