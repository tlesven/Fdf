/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rainbow_line_draw.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlesven <tlesven@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 17:35:05 by tlesven           #+#    #+#             */
/*   Updated: 2015/01/30 15:40:09 by tlesven          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>
#include "fdf.h"

static void			h_draw(t_mlx *mlx, t_line *line)
{
	int		i;
	int		cumul;
	int		lvl;

	i = 1;
	cumul = line->dx / 2;
	lvl = line->next_lvl;
	mlx_pixel_put(mlx->mlx, mlx->win, line->x, line->y, color_lvl(line->z));
	while (i <= line->dx)
	{
		line->x += line->xinc;
		cumul += line->dy;
		if (cumul >= line->dx)
		{
			cumul -= line->dx;
			line->y += line->yinc;
		}
		mlx_pixel_put(mlx->mlx, mlx->win, line->x, line->y, color_lvl(line->z));
		if (i == lvl)
		{
			lvl += line->next_lvl;
			line->z += line->zinc;
		}
		i++;
	}
}

static void			v_draw(t_mlx *mlx, t_line *line)
{
	int		i;
	int		cumul;
	int		lvl;

	i = 1;
	cumul = line->dy / 2;
	lvl = line->next_lvl;
	mlx_pixel_put(mlx->mlx, mlx->win, line->x, line->y, color_lvl(line->z));
	while (i <= line->dy)
	{
		line->y += line->yinc;
		cumul += line->dx;
		if (cumul >= line->dy)
		{
			cumul -= line->dy;
			line->x += line->xinc;
		}
		mlx_pixel_put(mlx->mlx, mlx->win, line->x, line->y, color_lvl(line->z));
		if (i == lvl)
		{
			lvl += line->next_lvl;
			line->z += line->zinc;
		}
		i++;
	}
}

static int			ft_abs(int nb)
{
	if (nb < 0)
		nb *= -1;
	return (nb);
}

static void			lvl(t_line *line, t_point p1, t_point p2)
{
	line->z = p1.z;
	line->dz = p1.z - p2.z;
	line->zinc = (p1.z < p2.z) ? 1 : -1;
	line->dz = ft_abs(line->dz);
	if (p1.z == p2.z)
		line->dz = -1;
}

void				line_draw(t_mlx *mlx, t_point p1, t_point p2)
{
	t_line	*line;

	line = malloc(sizeof(t_line));
	line->x = p1.x;
	line->y = p1.y;
	line->dx = p2.x - p1.x;
	line->dy = p2.y - p1.y;
	line->xinc = (line->dx > 0) ? 1 : -1;
	line->yinc = (line->dy > 0) ? 1 : -1;
	line->dx = ft_abs(line->dx);
	line->dy = ft_abs(line->dy);
	lvl(line, p1, p2);
	if (line->dx > line->dy)
	{
		line->next_lvl = line->dx / line->dz;
		h_draw(mlx, line);
	}
	else
	{
		line->next_lvl = line->dy / line->dz;
		v_draw(mlx, line);
	}
	free(line);
}
