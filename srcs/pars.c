/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hverda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:40:41 by hverda            #+#    #+#             */
/*   Updated: 2021/10/05 14:40:42 by hverda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_check_wall(t_s s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i <= s.h)
	{
		while (j < s.w)
		{
			if (s.v[i][0] != '1' || s.v[0][j] != '1')
				return (-1);
			if (s.v[s.h][j] != '1' || s.v[i][s.w - 1] != '1')
				return (-1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int	ft_check_symbol(t_s s)
{
	int	i;
	int	j;
	int	check;

	i = 0;
	j = 0;
	check = 0;
	while (i <= s.h)
	{
		while (j < s.w)
		{
			if (s.v[i][j] == 'P' || s.v[i][j] == 'W' || s.v[i][j] == 'C' \
			|| s.v[i][j] == 'E' || s.v[i][j] == '1' || s.v[i][j] == '0')
				check++;
			else
				return (-1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int	ft_check_map(t_s *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i <= s->h)
	{
		while (j < s->w)
		{
			if (ft_check_wall(*s) == -1)
				return (-1);
			if (s->v[i][j] == 'P')
				s->p++;
			if (s->v[i][j] == 'C')
				s->c++;
			if (s->v[i][j] == 'E')
				s->e++;
			if (ft_check_symbol(*s) == -1)
				return (-1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int	ft_error(t_s *s)
{
	if (s->w == -1)
		return (-1);
	if (ft_check_map(s) == -1)
		return (-1);
	if (s->p != 1 || s->e == 0 || s->c == 0)
		return (-1);
	return (0);
}

int	ft_map(char *file, t_s *s)
{
	char	*line;
	int		fd;
	int		i;
	int		d;

	i = 0;
	d = 0;
	s->h = ft_height(file);
	s->w = ft_width(file);
	fd = open(file, O_RDONLY, 0);	
	s->v = (char **)malloc(sizeof(char *) * (s->h + 1));
	while (i <= s->h)
	{
		s->v[i] = get_char_next_line(fd, &line);
		i++;
	}
	ft_initiation(s);
	d = ft_error(s);
	close(fd);
	return (d);
}
