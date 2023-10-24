/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 16:47:46 by akefeder          #+#    #+#             */
/*   Updated: 2023/10/24 22:10:00 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_3d.h"

void	free_tmp(char **tmp)
{
	int	i;

	i = 0;
	while (tmp && tmp[i] != NULL)
	{
		free(tmp[i]);
		i++;
	}
	if (tmp)
		free(tmp);
	tmp = NULL;
}

void	free_gnl(char *tmp)
{
	if (tmp != NULL)
		free(tmp);
}
