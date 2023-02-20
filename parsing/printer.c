/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 00:22:54 by akefeder          #+#    #+#             */
/*   Updated: 2023/02/20 01:19:32 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_3d.h"

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
	printf("\n\n\n---------------------------");
	printf("north : %s\n", file->north);
	printf("south : %s\n", file->south);
	printf("east : %s\n", file->east);
	printf("west : %s\n", file->west);
	printf("F : %i\n", file->F);
	printf("C : %i\n", file->C);
	printf("full : %i\n", file->full);
	
}