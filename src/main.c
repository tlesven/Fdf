/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlesven <tlesven@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 17:35:15 by tlesven           #+#    #+#             */
/*   Updated: 2015/02/05 18:55:59 by tlesven          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "libft.h"
#include "fdf.h"
#include "get_next_line.h"

void	parsing(int fd, t_ground *map)
{
	char	*line;
	char	**tab;
	int		i;
	int		y;

	y = 1;
	while (get_next_line(fd, &line))
	{
		i = 0;
		tab = ft_strsplit(line, ' ');
		while (tab[i])
		{
			add_to_map(tab[i], i + 1, y, map);
			free(tab[i]);
			i++;
		}
		free(tab);
		free(line);
		y++;
	}
}

void	find(t_ground *map)
{
	find_down_point(map);
	map->mapy = mapy(map);
	map->mapx = mapx(map);
	find_real_point(map);
	if (singleton_ang(0))
		rotation(map);
	find_real_pointz(map);
	singleton_map(map);
}

int		main(int argc, char **argv)
{
	int			fd;
	t_ground	*map;

	map = NULL;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			ft_putstr("File error\n");
			return (0);
		}
		map = init_ground();
		parsing(fd, map);
		find(map);
		map->mlx = ft_init_mlx(WINX, WINY, "fdf");
		start_draw(map);
	}
	return (0);
}
