/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:30:16 by akefeder          #+#    #+#             */
/*   Updated: 2023/02/17 20:43:56 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_3d.h"

int	north(char *line, t_file *file)
{
	int	i;
	int	deb;
	int	cpt;
	
	
	if (line[1] != 'O')
		return (ERROR);
	i = 2;
	while (line[i] == ' ')
		i++;
	j = 0;
	deb = i;
	while (line[i] != '\0' && line[i] != ' ')
	{
		i++;
		cpt++;
	}
	while(line[i] != '\0' && line[i] == ' ')
		i++;
	if (line[i] != '\0')
		return (ERROR);
	file->north = ft_strijcopy(line, deb, cpt);
	if (file->north == NULL)
		return (ERROR);
	return (OK);
}

int	south(char *line, t_file *file)
{
	int	i;
	int	deb;
	int	cpt;
	
	
	if (line[1] != 'O')
		return (ERROR);
	i = 2;
	while (line[i] == ' ')
		i++;
	j = 0;
	deb = i;
	while (line[i] != '\0' && line[i] != ' ')
	{
		i++;
		cpt++;
	}
	while(line[i] != '\0' && line[i] == ' ')
		i++;
	if (line[i] != '\0')
		return (ERROR);
	file->south = ft_strijcopy(line, deb, cpt);
	if (file->south == NULL)
		return (ERROR);
	return (OK);
}

int	west(char *line, t_file *file)
{
	int	i;
	int deb;
	int	cpt;
	
	
	if (line[1] != 'E')
		return (ERROR);
	i = 2;
	while (line[i] == ' ')
		i++;
	j = 0;
	deb = i;
	while (line[i] != '\0' && line[i] != ' ')
	{
		i++;
		cpt++;
	}
	while(line[i] != '\0' && line[i] == ' ')
		i++;
	if (line[i] != '\0')
		return (ERROR);
	file->west = ft_strijcopy(line, deb, cpt);
	if (file->west == NULL)
		return (ERROR);
	return (OK);
}

int	east(char *line, t_file *file)
{
	int	i;
	int deb;
	int	cpt;
	
	
	if (line[1] != 'A')
		return (ERROR);
	i = 2;
	while (line[i] == ' ')
		i++;
	j = 0;
	deb = i;
	while (line[i] != '\0' && line[i] != ' ')
	{
		i++;
		cpt++;
	}
	while(line[i] != '\0' && line[i] == ' ')
		i++;
	if (line[i] != '\0')
		return (ERROR);  
	file->east = ft_i_cpt_strcopy(line, deb, cpt);
	if (file->east == NULL)
		return (ERROR);
	return (OK);
}

int	color(char *line, t_file *file)
{
	int	i;
	int deb;
	int	cpt;

	i = 1;
	while (line[i] == ' ')
		i++;
	deb = i;
	while (line[i] != '\0' && line[i] != ' ')
	{
		i++;
		cpt++;
	}
	while(line[i] != '\0' && line[i] == ' ')
		i++;
	if (line[i] != '\0')
		return (ERROR);
	if (line[0] == 'F')
		file->F = ft_i_cpt_intcopy(line, deb, cpt);
	else
		file->C = ft_i_cpt_intcopy(line, deb, cpt);
	if (line[0] == 'F')
		return (file->find_F = 1, file->F);
	else
		return (file->find_C = 1, file->C);
}