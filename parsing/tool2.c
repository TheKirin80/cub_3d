/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 02:16:16 by akefeder          #+#    #+#             */
/*   Updated: 2023/03/22 20:57:36 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_3d.h"

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

int	filter_char(char *src, char *filter)
{
	int	i;
	int j;
	int find;

	i = 0;
	find = 0;
	while (src[i] != '\0')
	{
		j = 0;
		while (filter[j] != '\0' && find == 0)
		{
			if (src[i] == filter[j])
				find = 1;
			j++;
		}
		if (find == 0)
			return (ERROR);
		i++;
	}
	return (OK);
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
	while (color[i] != '\0')
	{
		ret = (ret * 10) + (color[i] - 48);
		if (ret > 255)
			return (ERROR);
		i++;
 	}
	return (ret);
}