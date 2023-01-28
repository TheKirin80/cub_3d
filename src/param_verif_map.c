/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_verif_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 14:25:08 by akefeder          #+#    #+#             */
/*   Updated: 2023/01/27 18:58:37 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_3d.h"

int	verif_carac(t_map *map, char c)
{
	if (c == '1' || c == '0')
		return (OK);
	if (c == 'P')
	{
		map->p = map->p + 1;
		return (OK);
	}
	if (c == 'E')
	{
		map->e = map->e + 1;
		return (OK);
	}
	if (c == 'C')
	{
		map->c = map->c + 1;
		return (OK);
	}
	return (ERROR);
}

int	verif_composant(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i] != NULL)
	{
		j = 0;
		while (map->map[i][j] != '\0')
		{
			if (verif_carac(map, map->map[i][j]) == ERROR)
				return (ERROR);
			j++;
		}
		i++;
	}
	if (map->p != 1 || map->c == 0 || map->e == 0)
		return (ERROR);
	return (OK);
}
