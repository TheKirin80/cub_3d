/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:28:58 by akefeder          #+#    #+#             */
/*   Updated: 2023/10/25 15:51:38 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_3d.h"

int	test_ext(char *av, char *ext, int i)
{
	int	j;

	j = 0;
	while (ext[j] != '\0')
	{
		if (ext[j] != av[i])
			return (ERROR);
		j++;
		i++;
	}
	return (OK);
}

int	test_fich(char *av)
{
	int	len;

	len = ft_strlen(av);
	if (len <= 4)
		return (ERROR);
	if (test_ext(av, ".cub", len - 4) == ERROR)
		return (ERROR);
	return (OK);
}

int	main(int ac, char **av)
{
	t_file	file;

	file = (t_file){0};
	if (ac != 2 || test_fich(av[1]) == ERROR)
		return (gest_error(1, &file));
	if (parsing(av[1], &file))
		return (gest_error(2, &file));
	if (charg_file(&file) == ERROR)
		return (gest_error(3, &file));
	mlx_hook(file.win, KeyPress, KeyPressMask, gest_moove, &file);
	mlx_hook(file.win, ClientMessage, LeaveWindowMask, gest_close, &file);
	mlx_loop(file.mlx);
	return (0);
}
