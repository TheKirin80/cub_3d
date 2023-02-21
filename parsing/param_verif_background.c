/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_verif_background.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 23:01:40 by akefeder          #+#    #+#             */
/*   Updated: 2023/02/21 00:59:22 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_3d.h"

int line_full_space(char *line)
{
	int i;
	
	i = 0;
	while (line[i] == ' ')
	{
		i++;
	}
	if (line[i] == '\0')
		return (OK);
	return (ERROR);
}

int	fill_param(char *param, t_file *file, char c)
{
	if (c == 'N')
	{
		if (north(param, file) == ERROR)
			return (ERROR);
	}
	else if (c == 'S')
	{
		if (south(param, file) == ERROR)
			return (ERROR);
	}
	else if (c == 'W')
	{
		if (west(param, file) == ERROR)
			return (ERROR);
	}
	else if (c == 'E')
	{
		if (east(param, file) == ERROR)
			return (ERROR);
	}
	else if (c == 'F')
	{
		if (color(param, file) == ERROR)
			return (ERROR);
	}
	else if (c == 'C')
	{
		if (color(param, file) == ERROR)
			return (ERROR);
	}
	return (OK);
}

int find_param(char *param, t_file *file)
{
	int	find;
	char *carac;

	carac = "NSWEFC";
	if (line_full_space(param) == OK)
		return (OK);
	find = is_present(param[0], carac);
	if (find == ERROR)
		return (ERROR);
	if (already_up(carac[find], file) == FULL)
		return (ERROR);
	if (fill_param(param, file, carac[find]) == ERROR)
		return (ERROR);
	return (OK);
}



int	check_background(t_file *file)
{
	int	i;

	i = 0;
	while (file->tmp[i] != NULL && file->full == 0)
	{
		if (find_param(file->tmp[i],file) == ERROR)
			return (ERROR);
		i++;
		file->full = is_full(file);
	}
	return (OK);
}

