/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlesven <tlesven@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 14:48:49 by tlesven           #+#    #+#             */
/*   Updated: 2014/04/16 12:51:18 by tlesven          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char		*ft_strtrim_end(char *s, int j)
{
	char	*sret;

	if (s[j - 1] == ' ' || s[j - 1] == '\n' || s[j - 1] == ','
		|| s[j - 1] == '\t')
		j--;
	{
		while (j)
		{
			if (s[j] == ' ' || s[j] == '\n' || s[j] == ',' || s[j] == '\t')
				j--;
			else
				break ;
		}
		s[j + 1] = '\0';
	}
	sret = ft_strdup(s);
	free(s);
	return (sret);
}

char			*ft_strtrim(char const *s)
{
	char	*str;
	int		i;
	int		j;

	str = (char *)malloc((ft_strlen(s) + 1) * sizeof(*str));
	if (str == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] == ' ' || s[i] == '\n' || s[i] == ',' || s[i] == '\t')
			i++;
		else
			break ;
	}
	while (s[i] != '\0')
	{
		str[j] = s[i];
		j++;
		i++;
	}
	return (ft_strtrim_end(str, j));
}
