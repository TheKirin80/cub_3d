/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 18:04:35 by akefeder          #+#    #+#             */
/*   Updated: 2023/10/24 18:06:32 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_3d.h"

int	prepa_tmp(char **tmp, int *flag)
{
	*flag = 0;
	if (!*tmp)
	{
		*tmp = (char *)malloc(sizeof(char));
		if (!*tmp)
			return (ERROR);
		(*tmp)[0] = '\0';
	}
	return (OK);
}

int	insert_static(char **tmp, int fd)
{
	char		buf[BUFFER_SIZE + 1];
	char		*copy;
	ssize_t		nb_car_lu;

	nb_car_lu = read(fd, buf, BUFFER_SIZE);
	while (nb_car_lu > 0)
	{
		buf[nb_car_lu] = '\0';
		if (check_carac(buf) == ERROR)
		{
			if (*tmp)
				free(*tmp);
			return(*tmp = NULL, ERROR);
		}
		copy = *tmp;
		*tmp = ft_strjoin(copy, buf);
		free(copy);
		copy = NULL;
		if (*tmp == NULL)
			return(ERROR);
		if (ft_backslash_n(*tmp) == FIND)
			break ;
		nb_car_lu = read(fd, buf, BUFFER_SIZE);
	}
	return (nb_car_lu);
}

int	insert_line(char **tmp, char **line)
{
	char	*copy;
	int		i;
	int		j;

	i = ft_strclen(*tmp, '\n');
	copy = (char *)malloc((i + 1) * sizeof(char));
	if (!copy)
		return (ERROR);
	j = 0;
	while (j < i)
	{
		copy[j] = (*tmp)[j];
		j++;
	}
	copy[j] = '\0';
	*line = copy;
	if ((*tmp)[i] == '\n')
		i++;
	return (i);
}

int	epuration_tmp(char **tmp, int i)
{
	char	*copy;
	int		j;

	j = 0;
	copy = (char *)malloc((ft_strclen(*tmp, '\0') + 1)
			* sizeof(char));
	if (!copy)
		return (ERROR);
	while ((*tmp)[i] != '\0')
	{
		copy[j] = (*tmp)[i];
		i++;
		j++;
	}
	copy[j] = '\0';
	free(*tmp);
	*tmp = NULL;
	*tmp = copy;
	return (OK);
}

int	get_next_line(int fd, char **line, int reset)
{
	static char		*tmp;
	int				i;
	int				flag;

	if (reset)
		return (free_gnl(tmp), END);
	if (line == 0 || BUFFER_SIZE == 0)
		return (ERROR);
	if (prepa_tmp(&tmp, &flag) == ERROR)
		return (ERROR);
	if (insert_static(&tmp, fd) == ERROR)
		return (ERROR);
	if (ft_backslash_n(tmp) == NOTFIND)
		flag = 1;
	i = insert_line(&tmp, line);
	if (i == ERROR)
		return (ERROR);
	if (epuration_tmp(&tmp, i) == ERROR)
		return (ERROR);
	if (flag == 1)
		return (free(tmp), tmp = NULL, END);
	else
		return (CONTINUE);
}
