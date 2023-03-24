/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map_tool_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 04:04:38 by akefeder          #+#    #+#             */
/*   Updated: 2023/03/24 05:40:57 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_3d.h"

void	sizing_map(t_file *file)
{
	int	i;
	int res;

	i = 0;
	while (file->map->map[i] != NULL)
	{
		res = ft_strlen(file->map->map[i]);
		if (res > file->map->len)
			file->map->len = res;
		i++;
	}
	file->map->maplen = i;
}

void	change_two_occurence(t_file *file)
{
	int	i;
	int	j;

	i = 0;
	while (file->map->map[i] != NULL)
	{
		j = 0;
		while (file->map->map[i][j] != '\0')
		{
			if (file->map->map[i][j] == '2')
				file->map->map[i][j] = '1';
			j++;
		}
		i++;
	}
	//print_tab(file->map->map, "map after verif");
}