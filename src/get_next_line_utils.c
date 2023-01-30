/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 18:04:06 by akefeder          #+#    #+#             */
/*   Updated: 2023/01/30 15:15:46 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_3d.h"

int	ft_backslash_n(char *str)
{
	int	i;

	i = -1;
	while (str[++i] != '\0')
		if (str[i] == '\n')
			return (FIND);
	return (NOTFIND);
}

int	ft_strclen(char *str, char c)
{
	int	i;

	i = 0;
	while (str && str[i] != '\0')
	{
		if (str[i] != c)
			i++;
		else
			return (i);
	}
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	int		len;
	int		i;
	int		j;

	i = 0;
	j = 0;
	len = ft_strclen(s1, 0) + ft_strclen(s2, 0) + 1;
	res = (char *)malloc(len * sizeof(char));
	if (!res)
		return (NULL);
	while (s1[i] != '\0')
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	res[i] = '\0';
	return (res);
}

int	check_carac(char buf[BUFFER_SIZE + 1] , char *src_verif)
{
	int	i;
	int find;

	i = 0;
	while (buf[i] != '\0')
	{
		j = 0;
		find = 0;
		while (find == 0 && src_verif[j] != '\0')
		{
			if (buf[i] == src_verif[j])
				find = 1;
			j++;
		}
		if (find == 0)
			return (ERROR);
		i++;
	}
	return (OK);
}