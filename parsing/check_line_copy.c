/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line_copy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 19:26:46 by akefeder          #+#    #+#             */
/*   Updated: 2023/10/24 18:33:36 by akefeder         ###   ########.fr       */
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



int		ft_rempli_ret(int *ret, int *list_cpt, char *color)
{
	int	stock;

	//stock = 0;
	color[list_cpt[1]] = '\0';
	stock = ft_atoi_color(color);
	//printf("color : |%s|\tstock : %i\tret : %i\n", color, stock, *ret);
	if (stock == ERROR)
		return (ERROR);
	*ret = *ret + stock;
	if (list_cpt[2] < 2)
		*ret = *ret << 8;
	list_cpt[1] = 0;
	list_cpt[2] = list_cpt[2] + 1;
	return (OK);
}
//	list_cpt : 0 -> i ; 1 -> j ; 2 -> virgule
//	list_rest : 0 ->stock ; 1 -> res
int		ft_i_cpt_intcopy(char *line, int deb, int cpt)
{
	int	list_cpt[3];
	int	ret;
	char color[13];
	
	ret = 0;
	rempli_zero(list_cpt, 3);
	if (check_etat(line, deb, cpt) == ERROR)
		return (ERROR);
	while (list_cpt[0] < cpt)
	{
		if (line[deb + list_cpt[0]] == ',')
		{
			if (ft_rempli_ret(&ret, list_cpt, color) == ERROR)
				return (ERROR);
		}
		else
		{
			color[list_cpt[1]] = line[deb + list_cpt[0]];
			list_cpt[1] = list_cpt[1] + 1;
		}
		list_cpt[0] = list_cpt[0] + 1;
	}
	if (ft_rempli_ret(&ret, list_cpt, color) == ERROR)
				return (ERROR);
	return (ret);
}