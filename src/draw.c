/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlesven <tlesven@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 17:34:51 by tlesven           #+#    #+#             */
/*   Updated: 2015/02/02 19:29:16 by tlesven          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"
#include "libft.h"

t_image	*init_image(t_mlx *mlx)
{
	t_image		*img;

	img = ft_memalloc(sizeof(t_image));
	img->endian = 0;
	img->bpp = 0;
	img->size_line = 0;
	img->ptr = mlx_new_image(mlx->mlx, WINX * 2, WINY * 2);
	img->data = mlx_get_data_addr(img->ptr, &img->bpp, &img->size_line,
			&img->endian);
	return (img);
}

void	draw_img(t_ground *map)
{
	t_ground	*l;
	t_image		*img;

	l = map->next;
	img = init_image(map->mlx);
	while (l != map)
	{
		if (l->next != map && l->y == l->next->y)
			line_draw_img(img, *l->p, *l->next->p);
		if (l->down)
			line_draw_img(img, *l->p, *l->down->p);
		l = l->next;
	}
	singleton_img(img->ptr);
}

void	start_draw(t_ground *map)
{
	draw_img(map);
	mlx_expose_hook(map->mlx->win, expose_func, 0);
	mlx_loop(map->mlx->mlx);
}
