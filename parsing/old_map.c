/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   old_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 18:47:53 by akefeder          #+#    #+#             */
/*   Updated: 2023/03/22 20:57:49 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_3d.h"

void	prepa_map(t_file *file)
{
	file->map->map = NULL;
	file->map->orient_find = 0;
	file->map->orient = 'R';
	file->map->len = 0;
	file->map->maplen = 0;
}

void	add_map_help(t_file *file, char *line, char **save)
{
	int	i;

	i = 0;
	while (file->map->map[i] != NULL)
	{
		save[i] = file->map->map[i];
		i++;
	}
	save[i] = line;
	save[i + 1] = NULL;
}

int	add_map(t_file *file, int i)
{
	char	**save;
	int		len;

	len = ft_maplen(file->map->map);
	save = malloc((len + 2) * sizeof(char *));
	if (save == NULL)
		return (ERROR);
	if (len == 0)
	{
		save[0] = file->tmp[i];
		save[1] = NULL;
	}
	else
		add_map_help(file, file->tmp[i], save);
	if (file->map->map)
		free(file->map->map);
	file->map->map = save;
	return (OK);
}

int	rempli_map(t_file *file, int i)
{
	file->map = malloc(1 * sizeof(t_map));
	if (file->map == NULL)
		return (ERROR);
	prepa_map(file);
	while (file->tmp[i] != NULL)
	{
		if (filter_char(file->tmp[i], "01 NSWE") == ERROR || add_map(file, i) == ERROR)
			return (ERROR);
		i++;
	}
	print_tab(file->map->map, "rempli map");
	return (OK);
}
