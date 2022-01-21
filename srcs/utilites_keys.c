/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilites_keys.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hverda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:41:12 by hverda            #+#    #+#             */
/*   Updated: 2021/10/05 14:41:14 by hverda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_check_e(t_s *s, int i, int j)
{
	if (s->v[i][j] != 'E' && s->check_egg >= 0)
		return (0);
	else if (s->v[i][j] == 'E' && s->check_egg == 0)
		return (1);
	else
		return (-1);
}

void	ft_game_over(t_s *s)
{
	int	i;
	int	j;

	i = s->w / 2 * 50;
	j = s->h / 2 * 50;
	mlx_put_image_to_window(s->mlx, s->win, s->pig, i, j);
	mlx_string_put(s->mlx, s->win, i - 5, j + 70, 0xFF0000, "GAME OVER");
}

void	ft_you_win(t_s *s)
{
	int	i;
	int	j;

	i = s->w / 2 * 50;
	j = s->h / 2 * 50;
	mlx_put_image_to_window(s->mlx, s->win, s->pl, i, j);
	mlx_string_put(s->mlx, s->win, i, j + 70, 0xFFF000, "YOU WIN");
}

int	ft_no_1_or_w(t_s *s, int i, int j)
{
	if (s->v[i][j] != '1' && s->v[i][j] != 'W')
		return (0);
	else
		return (1);
}

int	ft_step(t_s *s)
{
	s->step++;
	s->steps = ft_itoa(s->step);
	write(1, "step = ", 7);
	write(1, s->steps, 5);
	write(1, "\n", 1);
	mlx_put_image_to_window(s->mlx, s->win, s->tabl, 50, 0);
	mlx_string_put(s->mlx, s->win, 58, 33, 0xFFFFFF, "STEPS");
	mlx_string_put(s->mlx, s->win, 71, 43, 0xFFFFFF, s->steps);
	free(s->steps);
	return (s->step);
}
