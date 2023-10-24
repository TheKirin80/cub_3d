/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_param_verif_background.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 20:25:30 by akefeder          #+#    #+#             */
/*   Updated: 2023/10/24 21:12:08 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_3d.h"

int	is_full(t_file *file)
{
	if (file->north == NULL)
	{
		return (NOTFULL);
	}
	else if (file->south == NULL)
	{
		return (NOTFULL);
	}
	else if (file->east == NULL)
	{
		return (NOTFULL);
	}
	else if (file->west == NULL)
	{
		return (NOTFULL);
	}
	else if (file->find_f == 0)
	{
		return (NOTFULL);
	}
	else if (file->find_c == 0)
	{
		return (NOTFULL);
	}
	return (FULL);
}

int	already_up_2(char c, t_file *file)
{
	if (c == 'E')
	{
		if (file->east != NULL)
			return (FULL);
	}
	else if (c == 'F')
	{
		if (file->find_f == 1)
			return (FULL);
	}
	else if (c == 'C')
	{
		if (file->find_c == 1)
			return (FULL);
	}
	return (NOTFULL);
}

int	already_up(char c, t_file *file)
{
	if (c == 'N')
	{
		if (file->north != NULL)
			return (FULL);
	}
	else if (c == 'S')
	{
		if (file->south != NULL)
			return (FULL);
	}
	else if (c == 'W')
	{
		if (file->west != NULL)
			return (FULL);
	}
	else if (already_up_2(c, file) == FULL)
		return (FULL);
	return (NOTFULL);
}
