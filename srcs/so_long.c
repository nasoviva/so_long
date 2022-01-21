/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hverda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:40:48 by hverda            #+#    #+#             */
/*   Updated: 2021/10/05 14:40:50 by hverda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	key_hook(t_s *s)
{
	(void)s;
	exit (0);
}

void	ft_initiation(t_s *s)
{
	s->step = 0;
	s->done = 0;
	s->p = 0;
	s->c = 0;
	s->e = 0;
	s->img_back = "sprite/back.XPM";
	s->img_pl = "sprite/player.XPM";
	s->img_pig = "sprite/pig.XPM";
	s->img_wl = "sprite/wall.XPM";
	s->img_tabl = "sprite/tabl.XPM";
	s->img_ex = "sprite/exit.XPM";
	s->img_egg = "sprite/egg.XPM";
	s->img_npig = "sprite/new_pig.XPM";
}

void	ft_so_long(t_s s)
{
	s.mlx = mlx_init();
	s.win = mlx_new_window(s.mlx, s.w * 50, (s.h + 1) * 50, "so_long");
	ft_back(&s);
	ft_wall(&s);
	ft_player(&s);
	ft_coin(&s);
	ft_pig(&s);
	ft_tabl(&s);
	ft_exit(&s);
	mlx_string_put(s.mlx, s.win, 58, 33, 0xFFFFFF, "STEPS");
	mlx_string_put(s.mlx, s.win, 71, 43, 0xFFFFFF, "0");
	mlx_hook (s.win, 2, 0, key_press, &s);
	mlx_hook (s.win, 17, 0, key_hook, &s);
	mlx_loop_hook (s.mlx, render_next_frame, &s);
	mlx_loop(s.mlx);
}

int	ft_checkname(char *argv)
{
	FILE	*file;

	file = NULL;
	printf("%s\n", argv);
	if (!(file = fopen(argv, "r")))
	{
		write(1, "error\n", 6);
		return(-1);
	}
	else
		return (0);
}

int	main(int argc, char **argv)
{
	t_s	*s;
	int	i;

	if (argc == 2 && ft_checkname(argv[1]) == 0)
	{
		i = 0;
		s = (t_s *)malloc(sizeof(t_s));
		if (!s)
		{
			write(1, "error\n", 6);
			return (-1);
		}
		i = ft_map(argv[1], s);
		if (i < 0)
		{
			write(1, "error\n", 6);
			ft_free_string(*s);
			free(s);
			return (-1);
		}
		ft_so_long(*s);
		ft_free_values(s);
		free(s);
	}
	return (0);
}
