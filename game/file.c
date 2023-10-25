/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 17:34:09 by akefeder          #+#    #+#             */
/*   Updated: 2023/10/25 16:40:19 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_3d.h"

t_player	*charg_player(char orient, int i, int j)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	player->orient = orient;
	player->posx = j + 0.5;
	player->posy = i + 0.5;
	return (player);
}

void	init_player(t_file *file)
{
	int	i;
	int	j;
	int	find;

	i = 0;
	find = 0;
	while (find == 0 && i < file->map->maplen)
	{
		j = 0;
		while (find == 0 && j < file->map->len)
		{
			if (file->map->map[i][j] != '1' && file->map->map[i][j] != '0')
			{
				file->player = charg_player(file->map->map[i][j], i, j);
				init_component(file);
				file->map->map[i][j] = '0';
				find = 1;
			}
			j++;
		}
		i++;
	}
}

int	charg_file(t_file *file)
{
	file->mlx = mlx_init();
	if (!file->mlx)
		return (ERROR);
	file->win = mlx_new_window(file->mlx, SIZEPIC_WIDTH,
			SIZEPIC_HEIGHT, "cub_3d");
	if (!file->win)
		return (ERROR);
	init_player(file);
	if (load_img(file) == ERROR)
		return (ERROR);
	if (raycasting(file) == ERROR)
		return (ERROR);
	return (OK);
}

void	affiche_map(t_file *file)
{
	mlx_put_image_to_window(file->mlx, file->win, file->img_map.img, 0, 0);
}
