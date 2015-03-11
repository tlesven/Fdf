/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlesven <tlesven@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 17:35:01 by tlesven           #+#    #+#             */
/*   Updated: 2015/02/02 17:49:31 by tlesven          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>
#include "libft.h"
#include "fdf.h"

int			key(int key)
{
	static int x = -(WINX / 2) + 100;
	static int y = -(WINY / 2) + 100;

	if (key == 0xFF1B)
		exit(0);
	if (key == 0xFF52)
		y -= 5;
	if (key == 0xFF54)
		y += 5;
	if (key == 0xFF53)
		x += 5;
	if (key == 0xFF51)
		x -= 5;
	if (key == 0x72)
	{
		singleton_ang(1);
		find(singleton_map(NULL));
		draw_img(singleton_map(NULL));
	}
	if (key == 0x74)
	{
		singleton_ang(-1);
		find(singleton_map(NULL));
		draw_img(singleton_map(NULL));
	}
	mlx_put_image_to_window(singleton_mlx(NULL), singleton_win(NULL),
				singleton_img(NULL), x, y);
	return (0);
}

int			expose_func(void)
{
	key(0);
	return (0);
}

t_mlx		*ft_init_mlx(int winx, int winy, char *title)
{
	t_mlx	*mlx;

	mlx = malloc(sizeof(t_mlx));
	if (!(mlx->mlx = mlx_init()))
	{
		ft_putstr("mlx_init fail");
		return (NULL);
	}
	if (!(mlx->win = mlx_new_window(mlx->mlx, winx, winy, title)))
	{
		ft_putstr("mlx_new_window fail");
		return (NULL);
	}
	singleton_mlx(mlx->mlx);
	singleton_win(mlx->win);
	mlx_key_hook(mlx->win, key, 0);
	return (mlx);
}
