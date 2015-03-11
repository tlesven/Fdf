/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_down.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlesven <tlesven@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 17:12:31 by tlesven           #+#    #+#             */
/*   Updated: 2015/02/02 17:13:33 by tlesven          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"

void	find_down_point(t_ground *map)
{
	t_ground	*l1;
	t_ground	*l2;

	l1 = map->next;
	while (l1 != map)
	{
		l2 = l1->next;
		while (l2 != l1)
		{
			if ((l2->y == l1->y + 1) && (l2->x == l1->x))
			{
				l1->down = l2;
				break ;
			}
			l2 = l2->next;
		}
		l1 = l1->next;
	}
}
