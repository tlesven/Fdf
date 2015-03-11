/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlesven <tlesven@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 17:35:11 by tlesven           #+#    #+#             */
/*   Updated: 2015/01/21 17:42:34 by tlesven          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"

t_ground	*init_ground(void)
{
	t_ground	*l;

	l = ft_memalloc(sizeof(t_ground));
	l->next = l;
	l->prev = l;
	l->down = NULL;
	l->p = NULL;
	l->x = 0;
	l->y = 0;
	l->z = 0;
	return (l);
}

void		add_to_map(char *z, int x, int y, t_ground *map)
{
	t_ground	*new;
	t_ground	*l;

	l = map;
	new = ft_memalloc(sizeof(t_ground));
	new->x = x;
	new->y = y;
	new->z = ft_atoi(z);
	new->down = NULL;
	new->p = NULL;
	while (l->next != map)
		l = l->next;
	l->next = new;
	new->prev = l;
	new->next = map;
	map->prev = new;
}
