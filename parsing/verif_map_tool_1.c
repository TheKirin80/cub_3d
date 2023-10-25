/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map_tool_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 04:04:38 by akefeder          #+#    #+#             */
/*   Updated: 2023/10/25 15:26:15 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_3d.h"

int	sizing_map(t_file *file)
{
	int	i;
	int	res;

	i = 0;
	while (file->map->map[i] != NULL)
	{
		res = ft_strlen(file->map->map[i]);
		if (res == 0)
			return (ERROR);
		if (res > file->map->len)
			file->map->len = res;
		i++;
	}
	file->map->maplen = i;
	return (OK);
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
}
int	ft_strcmp(char c, char *cmp)
{
	int	i;

	i = 0;
	while (cmp[i] != '\0')
	{
		if (cmp[i] == c)
			return (OK);
		i++;
	}
	return (ERROR);
}

int	verif_carac_valid(t_file *file)
{
	int		i;
	int		j;

	i = 0;
	while (file->map->map[i] != NULL)
	{
		j = 0;
		while (file->map->map[i][j] != '\0')
		{
			if ((ft_strcmp(file->map->map[i][j], "01NSWE ") == ERROR))
				return (ERROR);
			j++;
		}
		i++;
	}
	return (OK);
}