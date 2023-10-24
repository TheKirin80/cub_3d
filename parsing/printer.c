/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 00:22:54 by akefeder          #+#    #+#             */
/*   Updated: 2023/10/24 21:14:49 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_3d.h"

void	print_part_tab(char *tab, int deb)
{
	int i;
	
	i = 0;
	printf("tab partiel a partir de %i : ", deb);
	while (tab[deb + i] != '\0')
	{
		printf("%c", tab[deb + i]);
		i++;
	}
	printf("\n");
}

void	print_tab(char **tab, char *msg)
{
	int i;

	i = 0;
	printf("\n-------------%s--------------\n", msg);
	while (tab[i] != NULL)
	{
		printf("%s\n", tab[i]);
		i++;
	}
	printf("-------------fin %s--------------\n",msg);
}

void	print_file(t_file *file, char *descriptor)
{
	printf("-------%s--------------------\n", descriptor);
	print_tab(file->map->map, "map");
	printf("north : %s\n", file->north);
	printf("south : %s\n", file->south);
	printf("east : %s\n", file->east);
	printf("west : %s\n", file->west);
	printf("F : %i\n", file->floor);
	printf("C : %i\n", file->ceil);
	printf("full : %i\n", file->full);
	printf("--------%s------------------\n",descriptor);
	
}

void	print_ray(t_file *file, char *descriptor)
{
	printf("--------%s------------------\n",descriptor);
	printf("posx : %f\n", file->player->posx);
	printf("posy : %f\n", file->player->posy);
	printf("mapx : %i\n", file->ray->mapx);
	printf("mapy : %i\n", file->ray->mapy);
	printf("camerax : %f\n", file->ray->camerax);
	printf("raydirx : %f\n", file->ray->raydirx);
	printf("raydiry : %f\n", file->ray->raydiry);
	printf("deltastepx : %f\n", file->ray->deltastepx);
	printf("deltastepy : %f\n", file->ray->deltastepy);
	printf("stepx : %f\n", file->ray->stepx);
	printf("stepy : %f\n", file->ray->stepy);
	printf("sidestepx : %f\n", file->ray->sidestepx);
	printf("sidestepy : %f\n", file->ray->sidestepy);
	printf("hit : %i\n", file->ray->hit);
	printf("side : %i\n", file->ray->side);
	printf("perpwalldist : %f\n", file->ray->perpwalldist);
	printf("heightline : %i\n", file->ray->heightline);
	printf("drawstart : %i\n", file->ray->drawstart);
	printf("drawend : %i\n", file->ray->drawend);
	printf("--------%s------------------\n",descriptor);
}