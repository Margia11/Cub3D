/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andreamargiacchi <andreamargiacchi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:23:17 by amargiac          #+#    #+#             */
/*   Updated: 2023/09/18 10:07:58 by andreamargi      ###   ########.fr       */
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

void	free_mat(char **mat)
{
	int	i;

	i = 0;
	while (mat[i] != NULL)
		free(mat[i++]);
	free(mat);
}

