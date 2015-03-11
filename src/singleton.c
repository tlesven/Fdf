/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singleton.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlesven <tlesven@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 16:21:15 by tlesven           #+#    #+#             */
/*   Updated: 2015/02/02 17:52:23 by tlesven          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"
#include "libft.h"

int		singleton_ang(int i)
{
	static int	angle = 0;

	if (i)
		angle += i;
	else
		return (angle);
	return (0);
}

void	*singleton_map(t_ground *map)
{
	static t_ground *static_map;

	if (map)
		static_map = map;
	else
		return (static_map);
	return (NULL);
}

void	*singleton_img(void *img)
{
	static void *static_img;

	if (img == NULL)
		return (static_img);
	else
		static_img = img;
	return (NULL);
}

void	*singleton_mlx(void *mlx)
{
	static void *static_mlx;

	if (mlx == NULL)
		return (static_mlx);
	else
		static_mlx = mlx;
	return (NULL);
}

void	*singleton_win(void *win)
{
	static void *static_win;

	if (win == NULL)
		return (static_win);
	else
		static_win = win;
	return (NULL);
}
