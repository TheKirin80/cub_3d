/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 18:59:42 by akefeder          #+#    #+#             */
/*   Updated: 2023/02/20 01:21:18 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_3d.h"

void	add_tmp_help(char **tmp, char *line, char **save)
{
	int	i;

	i = 0;
	while (tmp[i] != NULL)
	{
		save[i] = tmp[i];
		i++;
	}
	save[i] = line;
	save[i + 1] = NULL;
}

int	add_tmp(char **tmp, char *line)
{
	char	**save;
	int		len;

	len = ft_maplen(tmp);
	save = malloc((len + 2) * sizeof(char *));
	if (save == NULL)
	{
		free(line);
		return (ERROR);
	}
	if (len == 0)
	{
		save[0] = line;
		save[1] = NULL;
	}
	else
		add_tmp_help(tmp, line, save);
	free(tmp);
	tmp = save;
	return (OK);
}

int	rempli_tmp_help(int *fd, char *av)
{
	*fd = open(av, O_RDONLY);
	if (*fd == -1)
		return (ERROR);
	return (OK);
}

int	rempli_tmp(char *av, t_file *file)
{
	int		fd;
	char	*line;
	int		ret;

	if (rempli_tmp_help(&fd, av) == ERROR)
		return (ERROR);
	line = NULL;
	ret = get_next_line(fd, &line, 0);
	while (ret > 0)
	{
		if (add_tmp(file->tmp, line) == ERROR)
			return (close(fd), ERROR);
		line = NULL;
		ret = get_next_line(fd, &line, 0);
	}
	get_next_line(fd, &line, 1);
	close(fd);
	if (ret == -1)
		return (ERROR);
	else
		if (add_tmp(file->tmp, line) == ERROR)
			return (ERROR);
	line = NULL;
	return (OK);
}
