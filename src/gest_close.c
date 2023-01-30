/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gest_close.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 03:59:01 by akefeder          #+#    #+#             */
/*   Updated: 2023/01/30 15:50:17 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_3d.h"

void	destroy_img(t_file *file)
{
	if (file->bord)
		mlx_destroy_image(file->mlx, file->bord);
	if (file->fond)
		mlx_destroy_image(file->mlx, file->fond);
	if (file->play)
		mlx_destroy_image(file->mlx, file->play);
	if (file->exit)
		mlx_destroy_image(file->mlx, file->exit);
	if (file->col)
		mlx_destroy_image(file->mlx, file->col);
}

void	free_direction(t_file *file)
{
	if (file->NO != NULL)
		free(file->NO);
	if (file->SO != NULL)
		free(file->SO);
	if (file->WE != NULL)
		free(file->WE);
	if (file->EA != NULL)
		free(file->EA);
}

void	free_map(t_file *file)
{
	int	i;

	i = 0;
	while (file->map->map[i] != NULL)
	{
		free(file->map->map[i]);
		i++;
	}
	free(file->map->map);
}

void	free_file(t_file *file)
{
	free_direction(file);
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
}

int	gest_close(t_file *file)
{
	affichage(file, 0);
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
