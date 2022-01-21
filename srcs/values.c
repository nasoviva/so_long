/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   values.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hverda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:41:35 by hverda            #+#    #+#             */
/*   Updated: 2021/10/05 14:41:37 by hverda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_wall(t_s *s)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	s->wl = mlx_xpm_file_to_image(s->mlx, s->img_wl, &s->i_w, &s->i_h);
	while (i <= s->h)
	{
		while (j < s->w)
		{
			if (s->v[i][j] == '1')
				mlx_put_image_to_window(s->mlx, s->win, s->wl, j * 50, i * 50);
			j++;
		}
		j = 0;
		i++;
	}
}

void	ft_exit(t_s *s)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	s->ex = mlx_xpm_file_to_image(s->mlx, s->img_ex, &s->i_w, &s->i_h);
	while (i <= s->h)
	{
		while (j < s->w)
		{
			if (s->v[i][j] == 'E')
				mlx_put_image_to_window(s->mlx, s->win, s->ex, j * 50, i * 50);
			j++;
		}
		j = 0;
		i++;
	}
}

void	ft_coin(t_s *s)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	s->check_egg = s->c;
	s->egg = mlx_xpm_file_to_image(s->mlx, s->img_egg, &s->i_w, &s->i_h);
	while (i <= s->h)
	{
		while (j < s->w)
		{
			if (s->v[i][j] == 'C')
				mlx_put_image_to_window(s->mlx, s->win, s->egg, j * 50, i * 50);
			j++;
		}
		j = 0;
		i++;
	}
}

void	ft_player(t_s *s)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	s->pl = mlx_xpm_file_to_image(s->mlx, s->img_pl, &s->i_w, &s->i_h);
	while (i <= s->h)
	{
		while (j < s->w)
		{
			if (s->v[i][j] == 'P')
			{
				mlx_put_image_to_window(s->mlx, s->win, s->pl, j * 50, i * 50);
				s->pl_x = j;
				s->pl_y = i;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	ft_pig(t_s *s)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	s->pig = mlx_xpm_file_to_image(s->mlx, s->img_pig, &s->i_w, &s->i_h);
	while (i <= s->h)
	{
		while (j < s->w)
		{
			if (s->v[i][j] == 'W')
				mlx_put_image_to_window(s->mlx, s->win, s->pig, j * 50, i * 50);
			j++;
		}
		j = 0;
		i++;
	}
}
