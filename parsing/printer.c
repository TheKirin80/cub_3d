/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 00:22:54 by akefeder          #+#    #+#             */
/*   Updated: 2023/02/20 18:05:20 by akefeder         ###   ########.fr       */
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

void	print_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i] != NULL)
	{
		printf("%s\n", tab[i]);
		i++;
	}
}

void	print_file(t_file *file)
{
	printf("------------tmp------------\n\n\n");
	print_tab(file->tmp);
	printf("\n\n\n---------------------------\n");
	printf("north : %s\n", file->north);
	printf("south : %s\n", file->south);
	printf("east : %s\n", file->east);
	printf("west : %s\n", file->west);
	printf("F : %i\n", file->F);
	printf("C : %i\n", file->C);
	printf("full : %i\n", file->full);
	
}