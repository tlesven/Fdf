/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlesven <tlesven@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 17:35:44 by tlesven           #+#    #+#             */
/*   Updated: 2015/02/05 15:23:14 by tlesven          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WINX 1920
# define WINY 1080
# define RATIO 1.2

typedef struct			s_mlx
{
	void				*mlx;
	void				*win;
}						t_mlx;

typedef struct			s_img
{
	void				*ptr;
	char				*data;
	int					endian;
	int					bpp;
	int					size_line;
}						t_image;

typedef struct			s_point
{
	int					x;
	int					y;
	int					z;
}						t_point;

typedef struct			s_ground
{
	t_mlx				*mlx;
	int					x;
	int					y;
	int					z;
	int					mapx;
	int					mapy;
	t_point				*p;
	struct s_ground		*next;
	struct s_ground		*prev;
	struct s_ground		*down;
}						t_ground;

typedef struct			s_line
{
	int					x;
	int					y;
	int					z;
	int					dz;
	int					dx;
	int					dy;
	int					xinc;
	int					yinc;
	int					zinc;
	int					next_lvl;
}						t_line;

t_mlx					*ft_init_mlx(int winx, int winy, char *title);
t_ground				*init_ground(void);
void					add_to_map(char *z, int x, int y, t_ground *map);
void					find_down_point(t_ground *map);
void					find_real_point(t_ground *map);
void					find_real_pointz(t_ground *map);
int						mapy(t_ground *map);
int						mapx(t_ground *map);
void					start_draw(t_ground *map);
void					line_draw(t_mlx *mlx, t_point p1, t_point p2);
int						color_lvl(int lvl);
int						expose_func(void);
void					pixel_on_image(t_image *i, int x, int y, int color);
void					line_draw_img(t_image *img, t_point p1, t_point p2i);
void					*singleton_img(void *img);
void					*singleton_map(t_ground *map);
void					*singleton_mlx(void *mlx);
void					*singleton_win(void *win);
int						singleton_ang(int i);
void					find(t_ground *map);
void					draw_img(t_ground *map);
void					rotation(t_ground *map);
#endif
