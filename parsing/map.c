/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 18:47:53 by akefeder          #+#    #+#             */
/*   Updated: 2023/01/27 18:58:37 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_3d.h"

void	prepa_map(t_map *map)
{
	map->map = NULL;
	map->orient_find = 0;
	map->orient = 'R';
	map->len = 0;
	map->maplen = 0;
}

void	add_map_help(t_map *map, char *line, char **save)
{
	int	i;

	i = 0;
	while (map->map[i] != NULL)
	{
		save[i] = map->map[i];
		i++;
	}
	save[i] = line;
	save[i + 1] = NULL;
}

int	add_map(t_map *map, char *line)
{
	char	**save;
	int		len;

	len = ft_maplen(map->map);
	save = malloc((len + 2) * sizeof(char *));
	if (save == NULL)
	{
		free(line);
		return (ERROR);
	}
	if (len == 0)
	{
		save[0] = line;
		save[1] = NULL;
	}
	else
		add_map_help(map, line, save);
	free(map->map);
	map->map = save;
	return (OK);
}

int	rempli_map_help(int *fd, char *av)
{
	*fd = open(av, O_RDONLY);
	if (*fd == -1)
		return (ERROR);
	return (OK);
}

int	rempli_map(char *av, t_map *map)
{
	int		fd;
	char	*line;
	int		ret;

	if (rempli_map_help(&fd, av) == ERROR)
		return (ERROR);
	line = NULL;
	ret = get_next_line(fd, &line, 0);
	while (ret > 0)
	{
		if (add_map(map, line) == ERROR)
			return (close(fd), ERROR);
		line = NULL;
		ret = get_next_line(fd, &line, 0);
	}
	get_next_line(fd, &line, 1);
	close(fd);
	if (ret == -1)
		return (ERROR);
	else
		if (add_map(map, line) == ERROR)
			return (ERROR);
	line = NULL;
	return (OK);
}
