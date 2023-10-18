/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 00:22:54 by akefeder          #+#    #+#             */
/*   Updated: 2023/03/25 00:03:49 by akefeder         ###   ########.fr       */
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
	printf("F : %i\n", file->F);
	printf("C : %i\n", file->C);
	printf("full : %i\n", file->full);
	printf("--------%s------------------\n",descriptor);
	
}