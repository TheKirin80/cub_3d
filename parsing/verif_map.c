/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 23:42:52 by akefeder          #+#    #+#             */
/*   Updated: 2023/10/25 15:52:54 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_3d.h"

int	verif_single_pos(t_file *file)
{
	int		i;
	int		j;
	char	ret;

	i = 0;
	while (file->map->map[i] != NULL)
	{
		j = 0;
		while (file->map->map[i][j] != '\0')
		{
			ret = is_present_char(file->map->map[i][j], "NSWE");
			if (ret != 'F' && file->map->orient_find == 1)
				return (ERROR);
			if (ret != 'F')
			{
				file->map->orient = ret;
				file->map->orient_find = 1;
			}
			j++;
		}
		i++;
	}
	if (file->map->orient_find == 0)
		return (ERROR);
	return (OK);
}

int	modif_for_traitment(t_file *file, int i)
{
	int		j;
	char	*copy;

	copy = malloc((file->map->len + 1) * sizeof(char));
	if (copy == NULL)
		return (ERROR);
	j = 0;
	while (file->map->map[i][j] != '\0')
	{
		if (file->map->map[i][j] != ' ')
			copy[j] = file->map->map[i][j];
		else
			copy[j] = '2';
		j++;
	}
	while (j < file->map->len)
	{
		copy[j] = '2';
		j++;
	}
	copy[j] = '\0';
	free(file->map->map[i]);
	file->map->map[i] = copy;
	return (OK);
}

int	verif_encaps_zero(t_file *file, int x, int y)
{
	if (x == 0 || x == file->map->maplen - 1)
		return (ERROR);
	if (y == 0 || y == file->map->len - 1)
		return (ERROR);
	if (file->map->map[x][y - 1] == '2' || file->map->map[x][y + 1] == '2'
		|| file->map->map[x - 1][y] == '2' || file->map->map[x + 1][y] == '2')
		return (ERROR);
	return (OK);
}

int	verif_all_close(t_file *file)
{
	int	i;
	int	j;

	i = 0;
	while (file->map->map[i] != NULL)
	{
		j = 0;
		while (file->map->map[i][j] != '\0')
		{
			if ((file->map->map[i][j] == '0'
				|| file->map->map[i][j] == file->map->orient)
					&& verif_encaps_zero(file, i, j) == ERROR)
				return (ERROR);
			j++;
		}
		i++;
	}
	return (OK);
}



int	verif_map(t_file *file)
{
	int	i;

	if (verif_single_pos(file) == ERROR)
		return (ERROR);
	if (sizing_map(file) == ERROR)
		return (ERROR);
	if (verif_carac_valid(file) == ERROR)
		return (ERROR);
	i = 0;
	while (file->map->map[i] != NULL)
	{
		if (modif_for_traitment(file, i) == ERROR)
			return (ERROR);
		i++;
	}
	if (verif_all_close(file) == ERROR)
		return (ERROR);
	change_two_occurence(file);
	return (OK);
}
