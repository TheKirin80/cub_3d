/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 12:57:09 by akefeder          #+#    #+#             */
/*   Updated: 2023/02/20 00:10:58 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_3d.h"

int	gest_error(int code, t_file *file)
{
	if (code == 1)
		ft_putstr_fd("Error : false parameters\n", 2);
	else if (code == 2)
	{
		free_file(file);
		ft_putstr_fd("Error : map don't follow the rules\n", 2);
	}
	else
	{
		free_file(file);
		ft_putstr_fd("Error : Cannot print map\n", 2);
	}
	exit (1);
}
