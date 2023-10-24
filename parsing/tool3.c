/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 00:18:08 by akefeder          #+#    #+#             */
/*   Updated: 2023/10/24 19:12:59 by akefeder         ###   ########.fr       */
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

char	is_present_char(char src, char *src_verif)
{
	int	i;

	i = 0;
	while (src_verif[i] != '\0')
	{
		if (src_verif[i] == src)
			return (src_verif[i]);
		i++;
	}
	return ('F');
}
