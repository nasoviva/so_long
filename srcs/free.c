/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hverda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:40:26 by hverda            #+#    #+#             */
/*   Updated: 2021/10/05 14:40:28 by hverda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_free_values(t_s *s)
{	
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i <= s->h)
	{
		while (j <= s->w)
		{
			free(&s->v[i][j]);
			j++;
		}
		j = 0;
		i++;
	}
}

void	ft_free_string(t_s s)
{	
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i <= s.h)
	{
		free(s.v[i]);
		i++;
	}
	free(s.v);
}

void	ft_free(char **s1)
{
	if (*s1)
	{
		free(*s1);
		*s1 = NULL;
	}
}
