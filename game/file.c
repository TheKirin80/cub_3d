/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 17:34:09 by akefeder          #+#    #+#             */
/*   Updated: 2023/10/23 00:26:25 by akefeder         ###   ########.fr       */
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

	if (x >= 0 && x < SIZEPIC_WIDTH && y >= 0 && y < SIZEPIC_HEIGHT)
	{
		dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
		*(unsigned int*)dst = color;
	}
	
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
	file->img_minimap.img = mlx_new_image(file->mlx, SIZEPIC_WIDTH,
			SIZEPIC_HEIGHT);
	file->img_minimap.addr = mlx_get_data_addr(file->img_minimap.img,&(file->img_minimap.bpp),
			&(file->img_minimap.line_length), &(file->img_minimap.endian));
	//my_mlx_pixel_put(&(file->img_minimap), 10, 10, 0x00FF0000);//affichage d'un pixel	
	return (OK);
}
t_player	*charg_player(char orient, int i, int j)
{
	t_player *player;

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
	while(find == 0 && i < file->map->maplen)
	{
		j = 0;
		while(find == 0 && j < file->map->len)
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
	print_tab(file->map->map, "Dans le charg file");
	raycasting(file);
	return (OK);
}

void	affiche_map(t_file *file)
{
	//draw_map(file);
	//draw_square(file, file->player->posx, file->player->posy, 10, 0x00FF0000);
	mlx_put_image_to_window(file->mlx, file->win, file->img_minimap.img, 0, 0);
}