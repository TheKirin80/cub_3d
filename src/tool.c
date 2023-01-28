/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 17:54:58 by akefeder          #+#    #+#             */
/*   Updated: 2023/01/27 18:58:37 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_3d.h"

void	ft_putstr_fd(char *s, int fd)
{
	int		len;

	if (s != NULL && fd >= 0)
	{
		len = ft_strlen(s);
		write(fd, s, len);
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *s)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_maplen(char **s)
{
	int		i;

	i = 0;
	if (s == NULL)
		return (i);
	while (s[i] != NULL)
		i++;
	return (i);
}

void	ft_putnbr(int i)
{
	if (i == -2147483648)
		ft_putstr_fd("-2147483648", 1);
	else
	{
		if (i < 0)
		{
			i = i * -1;
			ft_putchar('-');
		}
		if (i >= 10)
		{
			ft_putnbr(i / 10);
			ft_putchar((i % 10) + 48);
		}
		else
			ft_putchar((i % 10) + 48);
	}
}
