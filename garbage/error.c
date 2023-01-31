/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 12:57:09 by akefeder          #+#    #+#             */
/*   Updated: 2023/01/27 18:58:37 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_3d.h"

void	gest_error_map(t_map *map)
{
	int	i;

	i = 0;
	if (map->map != NULL)
	{
		while (map->map[i] != NULL)
		{
			free(map->map[i]);
			i++;
		}
		free(map->map);
	}
}

int	gest_error(t_map *map, int code, t_file *file)
{
	if (code == 1)
		ft_putstr_fd("Error : false parameters\n", 2);
	else if (code == 2)
	{
		gest_error_map(map);
		ft_putstr_fd("Error : map don't follow the rules\n", 2);
	}
	else
	{
		destroy_img(file);
		if (file->win)
			mlx_destroy_window(file->mlx, file->win);
		file->win = NULL;
		if (file->mlx)
			mlx_destroy_display(file->mlx);
		if (file->mlx)
			free(file->mlx);
		free_map(file);
		ft_putstr_fd("Error : Cannot print map\n", 2);
	}
	exit (1);
}
