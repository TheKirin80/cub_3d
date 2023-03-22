/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gest_close.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 03:59:01 by akefeder          #+#    #+#             */
/*   Updated: 2023/03/22 21:06:28 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_3d.h"

// void	destroy_img(t_file *file)
// {
// 	if (file->bord)
// 		mlx_destroy_image(file->mlx, file->bord);
// 	if (file->fond)
// 		mlx_destroy_image(file->mlx, file->fond);
// 	if (file->play)
// 		mlx_destroy_image(file->mlx, file->play);
// 	if (file->exit)
// 		mlx_destroy_image(file->mlx, file->exit);
// 	if (file->col)
// 		mlx_destroy_image(file->mlx, file->col);
// }

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
	//destroy_img(file);
	if (file->win)
		mlx_destroy_window(file->mlx, file->win);
	file->win = NULL;
	if (file->mlx)
		mlx_destroy_display(file->mlx);
	if (file->mlx)
		free(file->mlx);
 	if (file->map != NULL)
 		free_map(file);
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
