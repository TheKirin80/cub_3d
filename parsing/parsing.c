/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 18:47:25 by akefeder          #+#    #+#             */
/*   Updated: 2023/02/20 01:12:00 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_3d.h"

int	parsing(char *path_to_file, t_file *file)
{
	char	**tmp;

	tmp = NULL;
	if (rempli_tmp(path_to_file, tmp) == ERROR) //tmp.c
		return (ERROR);
	if (check_background(tmp, file) == ERROR) //param_verif_background.c
		return (ERROR);
	print_file(file);
	free_file(file);
	return (OK);
}