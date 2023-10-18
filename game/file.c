/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 17:34:09 by akefeder          #+#    #+#             */
/*   Updated: 2023/10/18 20:37:16 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_3d.h"

// int	load_img(t_file *file)
// {
    
// 	file->img_north->img = mlx_xpm_file_to_image(file->mlx, file->north
//         , &file->img_north->img_width, &file->img_north->img_height);
// 	file->img_south->img = mlx_xpm_file_to_image(file->mlx, file->south
//         , &file->img_south->img->img_width, &file->img_south->img_height);
// 	file->img_west->img = mlx_xpm_file_to_image(file->mlx, file->west
//         , &file->img_west->img->img_width, &file->img_west->img_height);
//     file->img_east->img = mlx_xpm_file_to_image(file->mlx, file->east
//         , &file->img_east->img->img_width, &file->img_east->img_height);
// 	if (!file->img_north->img || !file->img_south->img
// 		|| !file->img_west->img || !file->img_east->img)
// 		return (ERROR);
// 	return (OK);
// }

// int load_img(t_file *file)
// {
//     int		iw;
// 	int		ih;

// 	iw = SIZEPIC_WIDTH;
// 	ih = SIZEPIC_HEIGHT;
// 	file->img_north.img = mlx_xpm_file_to_image(file->mlx, "./img/black.xpm", &iw, &ih);
// 	file->img_south.img = mlx_xpm_file_to_image(file->mlx, "./img/white.xpm", &iw, &ih);
//     if (!file->img_north.img || !file->img_south.img)
// 		return (ERROR);
// 	return (OK);
// }

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

void	draw_square(t_file *file, int posx, int posy, int len, int color)
{
	int	i;
	int	j;
	
	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len)
		{
			my_mlx_pixel_put(&(file->img_minimap), posx + j, posy + i, color);
			j++;
		}
		i++;
	}
}
void draw_map(t_file *file)
{
	int	i;
	int	j;

	i = 0;
	while (i < file->map->maplen)
	{
		j = 0;
		while(j < file->map->len)
		{
			if (file->map->map[i][j] == '1')
				draw_square(file, j * SIZEPIC_HEIGHT, i * SIZEPIC_WIDTH, SIZEPIC_HEIGHT, 0x00000000);
			else
				draw_square(file, j * SIZEPIC_HEIGHT, i * SIZEPIC_WIDTH, SIZEPIC_HEIGHT, 0x00FFFFFF);
			j++;
		}
		i++;
	}
}
int	load_img(t_file *file)
{
	file->img_minimap.img = mlx_new_image(file->mlx, file->map->len * SIZEPIC_WIDTH,
			file->map->maplen * SIZEPIC_HEIGHT);
	file->img_minimap.addr = mlx_get_data_addr(file->img_minimap.img,&(file->img_minimap.bpp),
			&(file->img_minimap.line_length), &(file->img_minimap.endian));
	//my_mlx_pixel_put(&(file->img_minimap), 10, 10, 0x00FF0000);//affichage d'un pixel
	draw_map(file);
	//draw_square(file, file->player.posx, file->player.posy, 10, 0x00FF0000);
	return (OK);
}
int	charg_player(t_file *file, char orient, int i, int j)
{
	file->player.orient = orient;
	file->player.posx = j * SIZEPIC_HEIGHT;
	file->player.posy = i * SIZEPIC_WIDTH;
	return (1);
}
void	init_player(t_file *file)
{
	int	i;
	int	j;
	int	find;

	i = 0;
	find = 0;
	while(find == 0 && i < file->map->maplen)
	{
		j = 0;
		while(find == 0 && j < file->map->len)
		{
			if (file->map->map[i][j] != '1' && file->map->map[i][j] != '0')
			{
				find = charg_player(file, file->map->map[i][j], i, j);
				file->map->map[i][j] = '0';
			}
		}
		j++;
	}
}

int	charg_file(t_file *file)
{
	file->mlx = mlx_init();
	if (!file->mlx)
		return (ERROR);
	file->win = mlx_new_window(file->mlx, file->map->len * SIZEPIC_WIDTH,
			file->map->maplen * SIZEPIC_HEIGHT, "cub_3d");
	if (!file->win)
		return (ERROR);
	//init_player(file);
	if (load_img(file) == ERROR)
		return (ERROR);
	return (OK);
}

// void	affiche_img(int i, int j, char obj, t_file *file)
// {
// 	int		iw;
// 	int		ih;

// 	iw = SIZEPIC_WIDTH;
// 	ih = SIZEPIC_HEIGHT;
// 	if (obj == '1')
// 		mlx_put_image_to_window(file->mlx, file->win, file->img_north.img,
// 			j * ih, i * iw);
// 	if (obj == '0')
// 		mlx_put_image_to_window(file->mlx, file->win, file->img_south.img,
// 			j * ih, i * iw);
// }

// void	affiche_map(t_file *file)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (file->map->map[i] != NULL)
// 	{
// 		j = 0;
// 		while (file->map->map[i][j] != '\0')
// 		{
// 			affiche_img(i, j, file->map->map[i][j], file);
// 			j++;
// 		}
// 		i++;
// 	}
// }
void	affiche_map(t_file *file)
{
	mlx_put_image_to_window(file->mlx, file->win, file->img_minimap.img, 0, 0);
}