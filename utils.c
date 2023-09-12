/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amargiac <amargiac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:23:17 by amargiac          #+#    #+#             */
/*   Updated: 2023/09/12 18:24:58 by amargiac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

char	*rev_string(char *s)
{
	int		i;
	int		k;
	char	*d;

	d = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	i = ft_strlen(s);
	k = 0;
	while (--i >= 0)
	{
		d[k] = s[i];
		k++;
	}
	return (d);
}


