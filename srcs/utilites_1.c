/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilites_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hverda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:41:19 by hverda            #+#    #+#             */
/*   Updated: 2021/10/05 14:41:21 by hverda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	*ft_strdup(char *s1)
{
	int		j;
	char	*dst;

	dst = malloc(ft_strlen(s1) + 1);
	if (dst == 0)
		return (NULL);
	j = 0;
	while (s1[j] != '\0')
	{
		dst[j] = s1[j];
		j++;
	}
	dst[j] = '\0';
	return (dst);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dst;
	int		i;
	int		j;

	i = 0;
	j = 0;
	dst = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (dst == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		dst[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		dst[i + j] = s2[j];
		j++;
	}
	dst[i + j] = '\0';
	s1 = dst;
	return (s1);
}

int	ft_result(int i, char **buf, char **remain)
{
	if (i && *remain)
	{
		ft_free(buf);
		return (1);
	}
	if (!i)
	{
		ft_free(buf);
		ft_free(remain);
	}
	return (0);
}

void	ft_if_remain(char **line, char **enter, char **remain)
{
	char	*tmp;

	if (*remain)
	{
		*enter = ft_strchr_n(*remain, '\n');
		if (*enter)
		{			
			**enter = '\0';
			tmp = *line;
			*line = ft_strdup(*remain);
			ft_free(&tmp);
			(*enter)++;
			tmp = *remain;
			*remain = ft_strdup(*enter);
			ft_free(&tmp);
		}
		else
		{			
			tmp = *line;
			*line = ft_strdup(*remain);
			ft_free(&tmp);
			ft_free(remain);
		}
	}
}

void	ft_if_enter(char **buf, char **enter, char **remain)
{
	*enter = ft_strchr_n(*buf, '\n');
	if (*enter)
	{
		**enter = '\0';
		(*enter)++;
		*remain = ft_strdup(*enter);
	}
}
