/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hverda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:40:18 by hverda            #+#    #+#             */
/*   Updated: 2021/10/05 14:40:20 by hverda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_back(t_s *s)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	s->back = mlx_xpm_file_to_image(s->mlx, s->img_back, &s->i_w, &s->i_h);
	while (i <= s->h)
	{
		while (j < s->w)
		{
			mlx_put_image_to_window(s->mlx, s->win, s->back, j * 50, i * 50);
			j++;
		}
		j = 0;
		i++;
	}
}

void	ft_tabl(t_s *s)
{
	s->tabl = mlx_xpm_file_to_image(s->mlx, s->img_tabl, &s->i_w, &s->i_h);
	mlx_put_image_to_window(s->mlx, s->win, s->tabl, 50, 0);
}

void	ft_new(t_s *s)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	s->np = mlx_xpm_file_to_image(s->mlx, s->img_npig, &s->i_w, &s->i_h);
	while (i <= s->h)
	{
		while (j < s->w)
		{
			if (s->v[i][j] == 'W')
				mlx_put_image_to_window(s->mlx, s->win, s->np, j * 50, i * 50);
			j++;
		}
		j = 0;
		i++;
	}
}

void	ft_block(t_s *s)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	s->pig = mlx_xpm_file_to_image(s->mlx, s->img_back, &s->i_w, &s->i_h);
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

int	render_next_frame(t_s *s)
{
	s->render++;
	if (s->done == 0 && s->render == 4000)
	{
		ft_block(s);
		ft_new(s);
	}
	else if (s->done == 0 && s->render == 8000)
	{
		ft_block(s);
		ft_pig(s);
		s->render = 0;
	}
	if (s->done != 0)
		s->pig = mlx_xpm_file_to_image(s->mlx, s->img_back, &s->i_w, &s->i_h);
	return (0);
}
