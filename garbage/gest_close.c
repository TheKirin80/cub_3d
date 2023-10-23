/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gest_close.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 03:59:01 by akefeder          #+#    #+#             */
/*   Updated: 2023/10/23 18:45:09 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_3d.h"

void	destroy_img(t_file *file)
{
	if (file->img_north.img)
		mlx_destroy_image(file->mlx, file->img_north.img);
	if (file->img_south.img)
		mlx_destroy_image(file->mlx, file->img_south.img);
	if (file->img_east.img)
		mlx_destroy_image(file->mlx, file->img_east.img);
	if (file->img_west.img)
		mlx_destroy_image(file->mlx, file->img_west.img);
	if (file->img_minimap.img)
		mlx_destroy_image(file->mlx, file->img_minimap.img);
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
			//printf("file map : %s\t\t\ti : %i\n", file->map->map[i], i);
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
	//affichage(file, 0);
	free_file(file);
	//destroy_img(file);
	// if (file->win)
	// 	mlx_destroy_window(file->mlx, file->win);
	// file->win = NULL;
	// if (file->mlx)
	// 	mlx_destroy_display(file->mlx);
	// if (file->mlx)
	// 	free(file->mlx);
	// free_map(file);
	exit(0);
}
