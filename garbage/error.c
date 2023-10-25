/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 12:57:09 by akefeder          #+#    #+#             */
/*   Updated: 2023/10/25 16:35:40 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_3d.h"

int	gest_error(int code, t_file *file)
{
	if (code == 1)
		ft_putstr_fd("Error\nFalse parameters\n", 2);
	else if (code == 2)
	{
		ft_putstr_fd("Error\nMap don't follow the rules\n", 2);
	}
	else
	{
		free_file(file);
		ft_putstr_fd("Error\nCannot print map\n", 2);
	}
	exit (1);
}
