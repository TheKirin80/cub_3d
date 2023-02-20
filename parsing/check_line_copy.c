/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line_copy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 19:26:46 by akefeder          #+#    #+#             */
/*   Updated: 2023/02/20 03:18:10 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_3d.h"

char	*ft_i_cpt_strcopy(char *line, int deb, int cpt)
{
	int		j;
	char	*cpy;	
	
	j = 0;
	cpy = malloc((cpt + 2) * sizeof(char));
	if (cpy == NULL)
		return (NULL);
	while (j < cpt)
	{
		cpy[j] = line[deb + j];
		j++;
	}
	cpy[j] = '\0';
	return (cpy);
}

int ft_strlen_num(char *str, int i)
{
	int	ret;
	
	ret = 0;
	while (str[i] != '\0' && is_num(str[i]) == OK)
	{
		i++;
		ret++;
	}
	return (ret);	
}
//utiliser le retour de strlen num pour pouvoir savoir la taille de chaine avant
//la conversion en int puis l'add a ret

int	check_etat(char *line, int deb, int cpt)
{
	int	i;
	int cpt_virg;

	if (cpt > 11)
		return (ERROR);
	i = 0;
	cpt_virg = 0;
	while (i < cpt)
	{
		if (line[deb + i] == ',')
			cpt_virg++;
		else if (is_num(line[deb + i]) == ERROR)
			return (ERROR);
		i++;
	}
	if (cpt_virg != 2)
		return (ERROR);
	return (OK);
}

int		ft_i_cpt_intcopy(char *line, int deb, int cpt)
{
	int	j;
	int	ret;
	char color[3];
	int stock;
	
	ret = 0;
	j = 0;
	if (check_etat(line, deb, cpt) == ERROR)
		return (ERROR);
	while (j < 3)
	{
		color[0] = line[deb + ((j * 3) + j) + 0];
		color[1] = line[deb + ((j * 3) + j) + 1];
		color[2] = line[deb + ((j * 3) + j) + 2];
		stock = ft_atoi_color(color);
		if (stock == ERROR)
			return (ERROR);
		ret = ret + stock;
		if (j < 2)
			ret = ret << 8;
		j++;
	}
	return (ret);
}