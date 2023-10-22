/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 23:26:13 by akefeder          #+#    #+#             */
/*   Updated: 2023/10/22 21:50:21 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cub_3d.h"

void	init_dir_plan(t_file *file)
{
	if (file->player->orient == 'N')
	{
		file->player->diry = -1;
		file->player->planx = 0.66;
	}
	else if (file->player->orient == 'S')
	{
		file->player->diry = 1;
		file->player->planx = -0.66;
	}
	else if (file->player->orient == 'E')
	{
		file->player->dirx = 1;
		file->player->plany = 0.66;
	}
	else if (file->player->orient == 'W')
	{
		file->player->dirx = -1;
		file->player->plany = -0.66;
	}
}

void	init_component(t_file *file)
{
	file->player->dirx = 0;
	file->player->diry = 0;
	file->player->planx = 0;
	file->player->plany = 0;
	file->player->moovespeed = 0.1;
	file->player->rotspeed = 0.033 * 1.8;
	init_dir_plan(file);
}
