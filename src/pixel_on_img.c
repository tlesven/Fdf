/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_on_img.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlesven <tlesven@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 18:40:57 by tlesven           #+#    #+#             */
/*   Updated: 2015/02/02 19:29:21 by tlesven          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		pixel_on_image(t_image *i, int x, int y, int color)
{
	if ((x < (WINX * 2)) && (y < (WINY * 2)))
	{
		i->data[i->size_line * y + x * (i->bpp / 8)] =
			(char)(color & 255);
		i->data[i->size_line * y + x * (i->bpp / 8) + 1] =
			(char)(color >> 8 & 255);
		i->data[i->size_line * y + x * (i->bpp / 8) + 2] =
			(char)(color >> 16 & 255);
	}
}
