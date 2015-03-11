/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_down_point.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlesven <tlesven@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 17:34:57 by tlesven           #+#    #+#             */
/*   Updated: 2015/02/05 20:33:02 by tlesven          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>
#include "libft.h"
#include "fdf.h"

int		mapx(t_ground *map)
{
	t_ground	*l;
	int			i;

	i = 0;
	l = map->next;
	while (l != map)
	{
		if (l->x > i)
			i = l->x;
		l = l->next;
	}
	return (i);
}

int		mapy(t_ground *map)
{
	t_ground	*l;
	int			i;

	i = 0;
	l = map->next;
	while (l != map)
	{
		if (l->y > i)
			i = l->y;
		l = l->next;
	}
	return (i);
}

void	find_real_pointz(t_ground *map)
{
	t_ground	*l;

	l = map->next;
	while (l != map)
	{
		l->p->z = l->z;
		if (l->z)
		{
			l->p->x -= l->z + ((WINX / 4) / (RATIO)) / (map->mapx - 1);
			l->p->y -= l->z + ((WINY / 4) / (RATIO)) / (map->mapy - 1);
		}
		l = l->next;
	}
}

void	rotation(t_ground *map)
{
	t_ground	*l;
	int			i;
	int			j;

	i = singleton_ang(0);
	j = singleton_ang(0);
	l = map->next;
	while(l != map)
	{
		if (l->y != l->prev->y)
		{
			i = singleton_ang(0);
			j += singleton_ang(0);
		}
		l->p->x -= j;
		l->p->y += i;
		i += singleton_ang(0);
		l = l->next;
	}
}

void	find_real_point(t_ground *map)
{
	t_ground	*l;
	int			i;

	i = 0;
	l = map->next;
	l->p = ft_memalloc(sizeof(t_point));
	l->p->x = WINX / 2;
	l->p->y = WINY / 2;
	while (l != map)
	{
		if (l->y == l->prev->y)
		{
			l->p = ft_memalloc(sizeof(t_point));
			l->p->x = (l->prev->p->x + (((WINX / (RATIO))) / (map->mapx - 1)));
			l->p->y = l->prev->p->y;
		}
		else if (l->down)
		{
			l->down->p = ft_memalloc(sizeof(t_point));
			l->down->p->x = l->p->x;
			l->down->p->y = l->p->y + ((WINY / RATIO) / (map->mapy - 1));
		}
		l = l->next;
	}
	i++;
}
