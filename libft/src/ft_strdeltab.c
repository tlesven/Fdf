/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdeltab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlesven <tlesven@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/18 20:04:59 by tlesven           #+#    #+#             */
/*   Updated: 2014/02/18 21:32:58 by tlesven          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void		ft_strdeltabl(char **tab, int nb)
{
	int		i;

	i = 0;
	while (i < nb)
	{
		ft_strdel(tab + i);
		i++;
	}
}
