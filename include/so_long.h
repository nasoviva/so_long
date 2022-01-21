/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hverda <hverda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 18:23:59 by hverda            #+#    #+#             */
/*   Updated: 2021/10/05 14:48:11 by hverda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <mlx.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_s
{
	char	**v;
	int		h;
	int		w;
	int		i_w;
	int		i_h;
	int		pl_x;
	int		pl_y;
	int		done;
	int		render;
	int		p;
	int		c;
	int		e;
	int		check_egg;
	int		step;
	char	*steps;

	char	*img_pl;
	char	*img_back;
	char	*img_wl;
	char	*img_pig;
	char	*img_npig;
	char	*img_ex;
	char	*img_egg;
	char	*img_tabl;

	void	*pl;
	void	*back;
	void	*wl;
	void	*pig;
	void	*np;
	void	*ex;
	void	*egg;
	void	*tabl;

	void	*mlx;
	void	*win;
}	t_s;

int		ft_nbr(long int nbr);
char	*ft_str(long int n, char *str, int i);
char	*ft_itoa(int n);
int		ft_strlen(char *str);
char	*ft_strchr_n(char *s, int c);

char	*ft_strdup(char *s1);
char	*ft_strjoin(char *s1, char *s2);
int		ft_result(int i, char **buf, char **remain);
void	ft_if_remain(char **line, char **enter, char **remain);
void	ft_if_enter(char **buf, char **enter, char **remain);

int		get_next_line(int fd, char **line);
char	*get_char_next_line(int fd, char **line);
int		ft_count_of_worlds(const char *str);
int		ft_height(char *file);
int		ft_width(char *file);

void	ft_back(t_s *s);
void	ft_tabl(t_s *s);
void	ft_new(t_s *s);
void	ft_block(t_s *s);
int		render_next_frame(t_s *s);

int		ft_step(t_s *s);
void	ft_game_over(t_s *s);
void	ft_you_win(t_s *s);
int		ft_no_1_or_w(t_s *s, int i, int j);
int		ft_check_e(t_s *s, int i, int j);

void	ft_step_to_the_left(t_s *s, int i, int j);
void	ft_step_to_the_right(t_s *s, int i, int j);
void	ft_step_to_the_up(t_s *s, int i, int j);
void	ft_step_to_the_down(t_s *s, int i, int j);
void	ft_step_to_the_pig(t_s *s);

void	ft_keycode_0(t_s *s, int j, int i);
void	ft_keycode_2(t_s *s, int j, int i);
void	ft_keycode_13(t_s *s, int j, int i);
void	ft_keycode_1(t_s *s, int j, int i);
int		key_press(int keycode, t_s *s);

void	ft_wall(t_s *s);
void	ft_exit(t_s *s);
void	ft_coin(t_s *s);
void	ft_player(t_s *s);
void	ft_pig(t_s *s);

int		ft_check_wall(t_s s);
int		ft_check_symbol(t_s s);
int		ft_check_map(t_s *s);
int		ft_error(t_s *s);
int		ft_map(char *file, t_s *s);

void	ft_free_values(t_s *s);
void	ft_free_string(t_s s);
void	ft_free(char **s1);

int		key_hook(t_s *s);
void	ft_initiation(t_s *s);
void	ft_so_long(t_s s);
int		ft_checkname(char *argv);
int		main(int argc, char **argv);

#endif
