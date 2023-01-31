/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 17:34:09 by akefeder          #+#    #+#             */
/*   Updated: 2023/01/27 18:58:37 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_3d.h"

int	load_img(t_file *file)
{
	int		iw;
	int		ih;

	iw = SIZEPIC;
	ih = SIZEPIC;
	file->bord = mlx_xpm_file_to_image(file->mlx, "./img/bord.xpm", &iw, &ih);
	file->fond = mlx_xpm_file_to_image(file->mlx, "./img/fond.xpm", &iw, &ih);
	file->col = mlx_xpm_file_to_image(file->mlx, "./img/col.xpm", &iw, &ih);
	file->exit = mlx_xpm_file_to_image(file->mlx, "./img/exit.xpm", &iw, &ih);
	file->play = mlx_xpm_file_to_image(file->mlx, "./img/play.xpm", &iw, &ih);
	if (!file->bord || !file->fond || !file->col || !file->exit || !file->play)
		return (ERROR);
	return (OK);
}

int	charg_file(t_file *file)
{
	file->mlx = mlx_init();
	if (!file->mlx)
		return (ERROR);
	file->win = mlx_new_window(file->mlx, file->map->len * SIZEPIC,
			file->map->maplen * SIZEPIC, "cub_3d");
	if (!file->win)
		return (ERROR);
	file->nbr_coup = 0;
	if (load_img(file) == ERROR)
		return (ERROR);
	return (OK);
}

