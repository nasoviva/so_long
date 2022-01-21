/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   steps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hverda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:40:56 by hverda            #+#    #+#             */
/*   Updated: 2021/10/05 14:40:59 by hverda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_step_to_the_left(t_s *s, int i, int j)
{
	s->step = ft_step(s);
	mlx_put_image_to_window(s->mlx, s->win, s->back, j * 50 - 50, i * 50);
	mlx_put_image_to_window(s->mlx, s->win, s->back, j * 50, i * 50);
	mlx_put_image_to_window(s->mlx, s->win, s->pl, j * 50 - 50, i * 50);
	s->pl_x = j - 1;
	s->pl_y = i;
	if (s->v[i][j - 1] == 'C' && s->check_egg > 0)
	{
		s->check_egg--;
		s->v[i][j - 1] = '0';
	}
}

void	ft_step_to_the_right(t_s *s, int i, int j)
{
	s->step = ft_step(s);
	mlx_put_image_to_window(s->mlx, s->win, s->back, j * 50 + 50, i * 50);
	mlx_put_image_to_window(s->mlx, s->win, s->back, j * 50, i * 50);
	mlx_put_image_to_window(s->mlx, s->win, s->pl, j * 50 + 50, i * 50);
	s->pl_x = j + 1;
	s->pl_y = i;
	if (s->v[i][j + 1] == 'C' && s->check_egg > 0)
	{
		s->check_egg--;
		s->v[i][j + 1] = '0';
	}
}

void	ft_step_to_the_up(t_s *s, int i, int j)
{
	s->step = ft_step(s);
	mlx_put_image_to_window(s->mlx, s->win, s->back, j * 50, i * 50 - 50);
	mlx_put_image_to_window(s->mlx, s->win, s->back, j * 50, i * 50);
	mlx_put_image_to_window(s->mlx, s->win, s->pl, j * 50, i * 50 - 50);
	s->pl_x = j;
	s->pl_y = i - 1;
	if (s->v[i - 1][j] == 'C' && s->check_egg > 0)
	{
		s->check_egg--;
		s->v[i - 1][j] = '0';
	}
}

void	ft_step_to_the_down(t_s *s, int i, int j)
{
	s->step = ft_step(s);
	mlx_put_image_to_window(s->mlx, s->win, s->back, j * 50, i * 50 + 50);
	mlx_put_image_to_window(s->mlx, s->win, s->back, j * 50, i * 50);
	mlx_put_image_to_window(s->mlx, s->win, s->pl, j * 50, i * 50 + 50);
	s->pl_x = j;
	s->pl_y = i + 1;
	if (s->v[i + 1][j] == 'C' && s->check_egg > 0)
	{
		s->check_egg--;
		s->v[i + 1][j] = '0';
	}
}

void	ft_step_to_the_pig(t_s *s)
{
	s->step = ft_step(s);
	ft_back(s);
	s->pl = mlx_xpm_file_to_image(s->mlx, s->img_back, &s->i_w, &s->i_h);
	s->pig = mlx_xpm_file_to_image(s->mlx, s->img_pig, &s->i_w, &s->i_h);
	ft_game_over(s);
	s->tabl = mlx_xpm_file_to_image(s->mlx, s->img_back, &s->i_w, &s->i_h);
	s->done++;
}
