/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_verif_background.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 23:01:40 by akefeder          #+#    #+#             */
/*   Updated: 2023/01/31 00:36:08 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_3d.h"

int line_full_space(char *line)
{
	int i;
	
	i = 0;
	while (param[i] == ' ')
	{
		i++;
	}
	if (param[i] == '\0')
		return (OK);
	return (ERROR);
}

int find_param(char *param, t_file *file)
{
	int	find

	if (line_full_space(param) == OK)
		return (OK);
	find = is_present(param[0], "NSWEFC");
	if (find == ERROR)
		return (ERROR);
	
	}
}

int	check_background(char **tmp, t_file *file, t_map *map)
{
	int	i;

	i = 0;
	while (tmp[i] != NULL)
	{
		if (find_param(tmp[i],file) == ERROR)
			return (free_tmp(tmp), free_file(file), ERROR);
		i++;
		
	}
}