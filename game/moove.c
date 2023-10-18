/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 22:23:25 by akefeder          #+#    #+#             */
/*   Updated: 2023/10/18 19:40:49 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_3d.h"

int	gest_moove(int keycode, t_file *file)
{
    //printf("je suis ici\n");
	file->keycode = keycode;
	if (keycode == KEY_A)
        printf("coola\n");
	if (keycode == KEY_D)
		//right_moove(file);
        printf("coold\n");
	if (keycode == KEY_W)
		//up_moove(file);
        printf("coolw\n");
	if (keycode == KEY_S)
		//down_moove(file);
        printf("cools\n");
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