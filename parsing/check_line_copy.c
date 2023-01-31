/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line_copy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 19:26:46 by akefeder          #+#    #+#             */
/*   Updated: 2023/01/31 20:04:10 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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

int	is_num(char c)
{
	if (c > 47 && c < 58)
		return (OK);
	return (ERROR);
}

int ft_strlen_num(char *str, int i)
{
	int	ret;
	
	while (str[i] != '\0' && is_num(str[i]) == OK)
	{
		i++;
		ret++;
	}
	return (ret);	
}
//utiliser le retour de strlen num pour pouvoir savoir la taille de chaine avant
//la conversion en int puis l'add a ret
int		*ft_i_cpt_intcopy(char *line, int deb, int cpt)
{
	int	j;
	int	ret;
	
	ret = 0;
	j = 0;
	
	
}