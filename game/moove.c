/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 22:23:25 by akefeder          #+#    #+#             */
/*   Updated: 2023/10/24 12:23:49 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_3d.h"

void up_moove(t_file *file)
{
	if (file->map->map[(int)(file->player->posy)][(int)(file->player->posx + file->player->dirx * file->player->moovespeed * 2.0)] != '1')
		file->player->posx = file->player->posx + file->player->dirx * file->player->moovespeed;
	if (file->map->map[(int)(file->player->posy + file->player->diry * file->player->moovespeed * 2.0)][(int)(file->player->posx)] != '1')
		file->player->posy = file->player->posy + file->player->diry * file->player->moovespeed;
	//printf("posx = %f, posy = %f\n", file->player->posx, file->player->posy);
	raycasting(file);
}

void down_moove(t_file *file)
{
	if (file->map->map[(int)(file->player->posy)][(int)(file->player->posx - file->player->dirx * file->player->moovespeed * 2.0)] != '1')
		file->player->posx = file->player->posx - file->player->dirx * file->player->moovespeed;
	if (file->map->map[(int)(file->player->posy - file->player->diry * file->player->moovespeed * 2.0)][(int)(file->player->posx)] != '1')
		file->player->posy = file->player->posy - file->player->diry * file->player->moovespeed;
	//printf("posx = %f, posy = %f\n", file->player->posx, file->player->posy);
	raycasting(file);
}

void right_moove(t_file *file)
{
	if (file->map->map[(int)(file->player->posy)][(int)(file->player->posx - file->player->diry * file->player->moovespeed * 2.0)] != '1')
		file->player->posx = file->player->posx - file->player->diry * file->player->moovespeed;
	if (file->map->map[(int)(file->player->posy + file->player->dirx * file->player->moovespeed * 2.0)][(int)(file->player->posx)] != '1')
		file->player->posy = file->player->posy + file->player->dirx * file->player->moovespeed;
	//printf("posx = %f, posy = %f\n", file->player->posx, file->player->posy);
	raycasting(file);
}

void left_moove(t_file *file)
{
	if (file->map->map[(int)(file->player->posy)][(int)(file->player->posx + file->player->diry * file->player->moovespeed * 2.0 )] != '1')
		file->player->posx = file->player->posx + file->player->diry * file->player->moovespeed;
	if (file->map->map[(int)(file->player->posy - file->player->dirx * file->player->moovespeed * 2.0)][(int)(file->player->posx)] != '1')
		file->player->posy = file->player->posy - file->player->dirx * file->player->moovespeed;
	//printf("posx = %f, posy = %f\n", file->player->posx, file->player->posy);
	raycasting(file);
}

int	gest_moove(int keycode, t_file *file)
{
    //printf("je suis ici\n");
	file->keycode = keycode;
	//printf("keycode : %i\n",keycode);
	if (keycode == KEY_A)
		left_moove(file);
	if (keycode == KEY_D)
		right_moove(file);
	if (keycode == KEY_W)
		up_moove(file);
	if (keycode == KEY_S)
		down_moove(file);
	if (keycode == KEY_ECHAP)
		gest_close(file);
    //     printf("coole\n");
	if (keycode == ROTATE_LEFT)
		rotate_left(file);
	if (keycode == ROTATE_RIGHT)
        rotate_right(file);
	else
		affiche_map(file);
	return (0);
}