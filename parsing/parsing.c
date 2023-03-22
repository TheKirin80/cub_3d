/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 18:47:25 by akefeder          #+#    #+#             */
/*   Updated: 2023/03/22 21:01:44 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_3d.h"

int	parsing(char *path_to_file, t_file *file)
{
	if (rempli_tmp(path_to_file, file) == ERROR) //tmp.c
		return (free_tmp(file->tmp) ,ERROR);
	//print_tab(file->tmp);
	if (check_background(file) == ERROR) //param_verif_background.c
		return (free_file(file), ERROR);
	print_file(file, "free parsing");
	free_file(file);
	return (OK);
}