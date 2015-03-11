/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_lvl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlesven <tlesven@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 17:34:39 by tlesven           #+#    #+#             */
/*   Updated: 2015/01/21 17:47:34 by tlesven          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		color_tab(int lvl)
{
	int		tab[21];

	tab[0] = 0x0000FF;
	tab[1] = 0x0033FF;
	tab[2] = 0x0066FF;
	tab[3] = 0x0099FF;
	tab[4] = 0x00CCFF;
	tab[5] = 0x00FFFF;
	tab[6] = 0x33FFFF;
	tab[7] = 0x66FFFF;
	tab[8] = 0x99FFFF;
	tab[9] = 0xCCFFFF;
	tab[10] = 0xFFFFFF;
	tab[11] = 0xFFFFCC;
	tab[12] = 0xFFFF99;
	tab[13] = 0xFFFF66;
	tab[14] = 0xFFFF33;
	tab[15] = 0xFFFF00;
	tab[16] = 0xFFCC00;
	tab[17] = 0xFF9900;
	tab[18] = 0xFF6600;
	tab[19] = 0xFF3300;
	tab[20] = 0xFF0000;
	return (tab[lvl]);
}

int		color_lvl(int lvl)
{
	if (lvl > 10)
		return (color_tab(20));
	else if (lvl < -10)
		return (color_tab(0));
	else
		return (color_tab(lvl + 10));
}
