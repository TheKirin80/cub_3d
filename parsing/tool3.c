/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 00:18:08 by akefeder          #+#    #+#             */
/*   Updated: 2023/02/21 00:20:12 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_3d.h"

void	rempli_zero(int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		tab[i] = 0;
		i++;
	}
}