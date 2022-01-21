/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hverda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:40:34 by hverda            #+#    #+#             */
/*   Updated: 2021/10/05 14:40:36 by hverda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_keycode_0(t_s *s, int j, int i)
{
	if (ft_no_1_or_w(s, i, j - 1) == 0 && ft_check_e(s, i, j - 1) == 0)
		ft_step_to_the_left(s, i, j);
	else if (ft_no_1_or_w(s, i, j - 1) == 0 && ft_check_e(s, i, j - 1) == 1)
	{
		s->step = ft_step(s);
		mlx_put_image_to_window(s->mlx, s->win, s->back, j * 50 - 50, i * 50);
		mlx_put_image_to_window(s->mlx, s->win, s->back, j * 50, i * 50);
		mlx_put_image_to_window(s->mlx, s->win, s->pl, j * 50 - 50, i * 50);
		ft_back(s);
		s->pl = mlx_xpm_file_to_image(s->mlx, s->img_back, &s->i_w, &s->i_h);
		s->pl = mlx_xpm_file_to_image(s->mlx, s->img_pl, &s->i_w, &s->i_h);
		ft_you_win(s);
		s->tabl = mlx_xpm_file_to_image(s->mlx, s->img_back, &s->i_w, &s->i_h);
		s->done++;
	}
	else if (s->v[i][j - 1] == 'W')
		ft_step_to_the_pig(s);
}

void	ft_keycode_2(t_s *s, int j, int i)
{
	if (ft_no_1_or_w(s, i, j + 1) == 0 && ft_check_e(s, i, j + 1) == 0)
		ft_step_to_the_right(s, i, j);
	else if (ft_no_1_or_w(s, i, j + 1) == 0 && ft_check_e(s, i, j + 1) == 1)
	{	
		s->step = ft_step(s);
		mlx_put_image_to_window(s->mlx, s->win, s->back, j * 50, i * 50 - 50);
		mlx_put_image_to_window(s->mlx, s->win, s->back, j * 50, i * 50);
		ft_back(s);
		s->pl = mlx_xpm_file_to_image(s->mlx, s->img_back, &s->i_w, &s->i_h);
		s->pl = mlx_xpm_file_to_image(s->mlx, s->img_pl, &s->i_w, &s->i_h);
		ft_you_win(s);
		s->tabl = mlx_xpm_file_to_image(s->mlx, s->img_back, &s->i_w, &s->i_h);
		s->done++;
	}
	else if (s->v[i][j + 1] == 'W')
		ft_step_to_the_pig(s);
}

void	ft_keycode_13(t_s *s, int j, int i)
{
	if (ft_no_1_or_w(s, i - 1, j) == 0 && ft_check_e(s, i - 1, j) == 0)
		ft_step_to_the_up(s, i, j);
	else if (ft_no_1_or_w(s, i - 1, j) == 0 && ft_check_e(s, i - 1, j) == 1)
	{	
		s->step = ft_step(s);
		mlx_put_image_to_window(s->mlx, s->win, s->back, j * 50, i * 50 - 50);
		mlx_put_image_to_window(s->mlx, s->win, s->back, j * 50, i * 50);
		ft_back(s);
		s->pl = mlx_xpm_file_to_image(s->mlx, s->img_back, &s->i_w, &s->i_h);
		s->pl = mlx_xpm_file_to_image(s->mlx, s->img_pl, &s->i_w, &s->i_h);
		ft_you_win(s);
		s->tabl = mlx_xpm_file_to_image(s->mlx, s->img_back, &s->i_w, &s->i_h);
		s->done++;
	}
	else if (s->v[i - 1][j] == 'W')
		ft_step_to_the_pig(s);
}

void	ft_keycode_1(t_s *s, int j, int i)
{
	if (ft_no_1_or_w(s, i + 1, j) == 0 && ft_check_e(s, i + 1, j) == 0)
		ft_step_to_the_down(s, i, j);
	else if (ft_no_1_or_w(s, i + 1, j) == 0 && ft_check_e(s, i + 1, j) == 1)
	{		
		s->step = ft_step(s);
		mlx_put_image_to_window(s->mlx, s->win, s->back, j * 50, i * 50 - 50);
		mlx_put_image_to_window(s->mlx, s->win, s->back, j * 50, i * 50);
		ft_back(s);
		s->pl = mlx_xpm_file_to_image(s->mlx, s->img_back, &s->i_w, &s->i_h);
		s->pl = mlx_xpm_file_to_image(s->mlx, s->img_pl, &s->i_w, &s->i_h);
		ft_you_win(s);
		s->tabl = mlx_xpm_file_to_image(s->mlx, s->img_back, &s->i_w, &s->i_h);
		s->done++;
	}
	else if (s->v[i + 1][j] == 'W')
		ft_step_to_the_pig(s);
}

int	key_press(int keycode, t_s *s)
{
	int	i;
	int	j;

	j = s->pl_x;
	i = s->pl_y;
	if (keycode == 53)
		exit (0);
	if (keycode == 0 && s->done == 0)
		ft_keycode_0(s, j, i);
	if (keycode == 2 && s->done == 0)
		ft_keycode_2(s, j, i);
	if (keycode == 13 && s->done == 0)
		ft_keycode_13(s, j, i);
	if (keycode == 1 && s->done == 0)
		ft_keycode_1(s, j, i);
	return (0);
}
