/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:28:43 by akefeder          #+#    #+#             */
/*   Updated: 2023/10/23 13:34:43 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_3D_H
# define CUB_3D_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "./mlx_linux/mlx.h"
# include <X11/X.h>
# include <math.h>
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
# define SIZEPIC_WIDTH 1024
# define SIZEPIC_HEIGHT 768
# define ROTATE_LEFT	65361
# define ROTATE_RIGHT	65363
# define KEY_W 119
# define KEY_S 115
# define KEY_A 97
# define KEY_D 100
# define KEY_ECHAP 65307
# define CARACT_OK "01NOSEAW\n "

typedef struct s_map	t_map;
typedef struct s_img	t_img;
typedef struct s_file	t_file;
typedef struct s_lect	t_lect;
typedef struct s_pos	t_pos;
typedef struct s_player	t_player;
typedef struct s_ray	t_ray;

struct s_map
{
	char	**map;
	int		orient_find;
	char	orient;
	int		len;
	int		maplen;
};

struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
};

struct s_pos
{
	int	x;
	int	y;
};

struct s_player
{
	double posx;
	double posy;
	double dirx;
	double diry;
	double planx;
	double plany;
	char orient;
	double moovespeed;
	double rotspeed;
};

struct	s_ray
{
	int	mapx;
	int	mapy;
	double camerax;
	double raydirx;
	double raydiry;
	double deltastepx;
	double deltastepy;
	double stepx;
	double stepy;
	double sidestepx;
	double sidestepy;
	int	hit;
	int	side;
	double perpwalldist;
	int	heightline;
	int drawstart;
	int	drawend; 
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
	t_img	img_north;
	char	*south;
	t_img	img_south;
	char	*west;
	t_img	img_west;
	char	*east;
	t_img	img_east;
	int		full;
	char	**tmp;
	t_img	img_minimap;
	t_player	*player;
	t_ray	*ray;
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
int		filter_char(char *src, char *filter);
char	*ft_strcopy(char *src);
// --------------- tool3.c  ---------------
void	rempli_zero(int *tab, int size);
char	is_present_char(char src, char *src_verif);
// --------------- error.c  ---------------
int		gest_error(int code, t_file *file);
// --------------- file.c  ---------------
int		load_img(t_file *file);
int		charg_file(t_file *file);
void	my_mlx_pixel_put(t_img *data, int x, int y, int color);
//void	affiche_img(int i, int j, char obj, t_file *file);
void	affiche_map(t_file *file);
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
void	print_tab(char **tab, char *msg);
void	print_file(t_file *file, char *descriptor);
void	print_ray(t_file *file, char *descriptor);
// --------------- parsing.c  ---------------
int		parsing(char *path_to_file, t_file *file);
// --------------- old_map.c  ---------------
int		rempli_map(t_file *file, int i);
// --------------- verif_map.c  ---------------
int		verif_single_pos(t_file *file);
int		modif_for_traitment(t_file *file, int i);
int		verif_map(t_file *file);
// --------------- verif_map_tool_1.c  ---------------
void	sizing_map(t_file *file);
void	change_two_occurence(t_file *file);
// --------------- moove.c  ---------------
int	gest_moove(int keycode, t_file *file);
// --------------- raycasting.c  ---------------
void raycasting(t_file *file);
// --------------- raycasting_init.c  ---------------
void	init_dir_plan(t_file *file);
void	init_component(t_file *file);
// --------------- rotate.c  ---------------
void	rotate_right(t_file *file);
void	rotate_left(t_file *file);
#endif