/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:28:43 by akefeder          #+#    #+#             */
/*   Updated: 2023/01/27 21:56:29 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_3D_H
# define CUB_3D_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <mlx.h>
# include <X11/X.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

# define ERROR -1
# define OK 0
# define END 0
# define NOTFIND 0
# define FIND 1
# define CONTINUE 1
# define SIZEPIC 36
# define KEY_W 119
# define KEY_S 115
# define KEY_A 97
# define KEY_D 100
# define KEY_ECHAP 65307
# define CARACT_OK "01NOSEAW "

typedef struct s_map	t_map;
typedef struct s_file	t_file;
typedef struct s_lect	t_lect;

struct s_map
{
	char	**map;
	int		orient_find;
	char	orient;
	int		len;
	int		maplen;
};

struct s_file
{
	void	*mlx;
	void	*win;
	t_map	*map;
	int		px;
	int		py;
	int		nbr_coup;
	int		keycode;
	void	*F;
	void	*C;
	void	*NO;
	void	*SO;
	void	*WE;
	void	*EA;
};

struct	s_lect
{
	int		fd;
	char	*tmp;
};

// --------------- get_next_line.c  ---------------
int		get_next_line(int fd, char **line, int reset);
// --------------- get_next_line_utils.c  ---------------
int		ft_backslash_n(char *str);
int		ft_strclen(char *str, char c);
char	*ft_strjoin(char *s1, char *s2);
// --------------- tmp.c  ---------------
int		rempli_tmp(char *av, char **tmp);
// --------------- map.c  ---------------
void	prepa_map(t_map *map);
int		add_map(t_map *map, char *line);
int		rempli_map(char *av, t_map *map);
// --------------- param_verif_map.c  ---------------
int		verif_carac(t_map *map, char c);
int		verif_composant(t_map *map);
// --------------- tool.c  ---------------
void	ft_putstr_fd(char *s, int fd);
int		ft_strlen(char *s);
int		ft_maplen(char **s);
void	ft_putnbr(int i);
// --------------- tool2.c  ---------------
void	affichage(t_file *file, int i);
int		verif_map(t_map *map);
// --------------- error.c  ---------------
int		gest_error(t_map *map, int code, t_file *file);
void	gest_error_map(t_map *map);
// --------------- file.c  ---------------
int		load_img(t_file *file);
int		charg_file(t_file *file);
// --------------- gest_close.c  ---------------
void	destroy_img(t_file *file);
void	free_map(t_file *file);
int		gest_close(t_file *file);

#endif