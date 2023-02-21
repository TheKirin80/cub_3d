/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:28:43 by akefeder          #+#    #+#             */
/*   Updated: 2023/02/21 00:20:47 by akefeder         ###   ########.fr       */
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
# define NOTFULL 0
# define FULL 1
# define FIND 1
# define CONTINUE 1
# define SIZEPIC 36
# define KEY_W 119
# define KEY_S 115
# define KEY_A 97
# define KEY_D 100
# define KEY_ECHAP 65307
# define CARACT_OK "01NOSEAW\n "

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
	int		find_F;
	int		find_C;
	int		F;
	int		C;
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	int		full;
	char	**tmp;
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
int		is_printable(char c);
int		check_carac(char buf[BUFFER_SIZE + 1]);
// --------------- tmp.c  ---------------
int		rempli_tmp(char *av, t_file *file);
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
// void	affichage(t_file *file, int i);
// int		verif_map(t_map *map);
int		is_present(char src, char *src_verif);
int		is_num(char src);
int		ft_atoi_color(char *color);
// --------------- tool3.c  ---------------
void	rempli_zero(int *tab, int size);
// --------------- error.c  ---------------
int		gest_error(int code, t_file *file);
// --------------- file.c  ---------------
// int		load_img(t_file *file);
// int		charg_file(t_file *file);
// --------------- gest_close.c  ---------------
void	destroy_img(t_file *file);
void	free_direction(t_file *file);
void	free_map(t_file *file);
void	free_file(t_file *file);
int		gest_close(t_file *file);
// --------------- check_line.c  ---------------
int		north(char *line, t_file *file);
int		south(char *line, t_file *file);
int		east(char *line, t_file *file);
int		west(char *line, t_file *file);
int		color(char *line, t_file *file);
// --------------- check_line_copy.c  ---------------
char	*ft_i_cpt_strcopy(char *line, int deb, int cpt);
int		ft_strlen_num(char *str, int i);
int		check_etat(char *line, int deb, int cpt);
int		ft_i_cpt_intcopy(char *line, int deb, int cpt);
// --------------- param_verif_background.c  ---------------
int		line_full_space(char *line);
int		fill_param(char *param, t_file *file, char c);
int		find_param(char *param, t_file *file);
int		check_background(t_file *file);
// --------------- utils_param_verif_background.c  ---------------
int		is_full(t_file *file);
int		already_up(char c, t_file *file);
// --------------- free.c  ---------------
void	free_tmp(char **tmp);
// --------------- printer.c  ---------------
void	print_part_tab(char *tab, int deb);
void	print_tab(char **tab);
void	print_file(t_file *file);
// --------------- parsing.c  ---------------
int		parsing(char *path_to_file, t_file *file);
#endif