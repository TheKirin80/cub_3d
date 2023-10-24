/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 18:47:25 by akefeder          #+#    #+#             */
/*   Updated: 2023/10/24 19:23:28 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_3d.h"

int	parsing(char *path_to_file, t_file *file)
{
	if (rempli_tmp(path_to_file, file) == ERROR)
		return (free_tmp(file->tmp), ERROR);
	if (check_background(file) == ERROR)
		return (free_file(file), ERROR);
	print_file(file, "parsing");
	return (OK);
}
