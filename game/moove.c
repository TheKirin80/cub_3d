/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 22:23:25 by akefeder          #+#    #+#             */
/*   Updated: 2023/10/18 22:33:28 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_3d.h"

void up_moove(t_file *file)
{
	t_pos pos_tmp;

	pos_tmp.x = file->player->posx;
	pos_tmp.y = file->player->posy;
	if (file->map->map[((pos_tmp.y - 5) / SIZEPIC_WIDTH)][pos_tmp.x / SIZEPIC_HEIGHT] == '0')
		file->player->posy = file->player->posy - 5;
}

void down_moove(t_file *file)
{
	t_pos pos_tmp;

	pos_tmp.x = file->player->posx;
	pos_tmp.y = file->player->posy;
	
	// printf("valeur : %i\n", ((pos_tmp.y - 5) / SIZEPIC_WIDTH));
	if (file->map->map[((pos_tmp.y + 5) / SIZEPIC_WIDTH)][pos_tmp.x / SIZEPIC_HEIGHT] == '0')
		file->player->posy = file->player->posy + 5;
}

void left_moove(t_file *file)
{
	t_pos pos_tmp;

	pos_tmp.x = file->player->posx;
	pos_tmp.y = file->player->posy;
	if (file->map->map[pos_tmp.y / SIZEPIC_WIDTH][((pos_tmp.x - 5) / SIZEPIC_HEIGHT)] == '0')
		file->player->posx = file->player->posx - 5; 
}

void right_moove(t_file *file)
{
	t_pos pos_tmp;

	pos_tmp.x = file->player->posx;
	pos_tmp.y = file->player->posy;
	if (file->map->map[pos_tmp.y / SIZEPIC_WIDTH][((pos_tmp.x + 5) / SIZEPIC_HEIGHT)] == '0')
		file->player->posx = file->player->posx + 5; 
}

int	gest_moove(int keycode, t_file *file)
{
    //printf("je suis ici\n");
	file->keycode = keycode;
	if (keycode == KEY_A)
		left_moove(file);
	if (keycode == KEY_D)
		right_moove(file);
	if (keycode == KEY_W)
		up_moove(file);
	if (keycode == KEY_S)
		down_moove(file);
	if (keycode == KEY_ECHAP)
		//gest_close(file);
        printf("coole\n");
	if (keycode == ROTATE_LEFT)
        printf("coolfg\n");
	if (keycode == ROTATE_RIGHT)
        printf("coolfd\n");
	else
		affiche_map(file);
	return (0);
}