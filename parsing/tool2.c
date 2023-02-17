/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 02:16:16 by akefeder          #+#    #+#             */
/*   Updated: 2023/02/17 19:57:01 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_3d.h"

void	affichage(t_file *file, int i)
{
	if (i == 1)
	{
		ft_putstr_fd("Votre nombre de mouvement est de : ", 1);
		ft_putnbr(file->nbr_coup);
		ft_putstr_fd("\n", 1);
	}
	else
	{
		ft_putstr_fd("Votre nombre de final de mouvement est de : ", 1);
		ft_putnbr(file->nbr_coup);
		ft_putstr_fd("\n", 1);
	}
}

int	verif_map(t_map *map)
{
	map->len = ft_strlen(map->map[0]);
	map->maplen = ft_maplen(map->map);
	if (verif_square(map) == ERROR)
		return (ERROR);
	if (verif_haut_bas(map) == ERROR)
		return (ERROR);
	if (verif_gauche_droite(map) == ERROR)
		return (ERROR);
	if (verif_composant(map) == ERROR)
		return (ERROR);
	return (OK);
}

int	is_present(char src, char *src_verif)
{
	int	i;

	i = 0;
	while (src_verif[i] != '\0')
	{
		if (src_verif[i] == src)
			return (i);
		i++;
	}
	return (ERROR);
}

int	is_num(char src)
{
	if (src > 47 && src < 58)
		return (OK);
	return (ERROR);
}

int ft_atoi_color(char *color)
{
	int	i;
	int	ret;
	
	i = 0;
	ret = 0;
	while (i < 3)
	{
		ret = (ret * 10) + (color[i] - 48);
		if (ret > 255)
			return (ERROR);
		i++;
 	}
	return (OK);
}