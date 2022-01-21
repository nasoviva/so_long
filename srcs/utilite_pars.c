/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilite_pars.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hverda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:41:05 by hverda            #+#    #+#             */
/*   Updated: 2021/10/05 14:41:07 by hverda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	get_next_line(int fd, char **line)
{
	static char	*remain;
	char		*buf;
	int			i;
	char		*enter;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0 || !line || (read(fd, 0, 0) == -1))
		return (-1);
	buf = malloc(BUFFER_SIZE + 1);
	if (buf == NULL)
		return (-1);
	i = 1;
	enter = NULL;
	*line = ft_strdup("");
	ft_if_remain(line, &enter, &remain);
	while (!enter && i > 0)
	{		
		i = read(fd, buf, BUFFER_SIZE);
		buf[i] = '\0';
		ft_if_enter(&buf, &enter, &remain);
		tmp = *line;
		*line = ft_strjoin(*line, buf);
		ft_free(&tmp);
	}
	return (ft_result(i, &buf, &remain));
}

char	*get_char_next_line(int fd, char **line)
{
	static char	*remain;
	char		*buf;
	int			i;
	char		*enter;
	char		*tmp;

	buf = malloc(BUFFER_SIZE + 1);
	i = 1;
	enter = NULL;
	*line = ft_strdup("");
	ft_if_remain(line, &enter, &remain);
	while (!enter && i > 0)
	{		
		i = read(fd, buf, BUFFER_SIZE);
		buf[i] = '\0';
		ft_if_enter(&buf, &enter, &remain);
		tmp = *line;
		*line = ft_strjoin(*line, buf);
		ft_free(&tmp);
	}
	i = ft_result(i, &buf, &remain);
	return (*line);
}

int	ft_count_of_worlds(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_height(char *file)
{
	char	*line;
	int		fd;
	int		h;

	fd = open(file, O_RDONLY, 0);
	h = 0;
	while (get_next_line(fd, &line) > 0)
	{
		free(line);
		h++;
	}
	close(fd);
	free(line);
	return (h);
}

int	ft_width(char *file)
{
	char	*line;
	int		fd;
	int		w;

	fd = open(file, O_RDONLY, 0);
	get_next_line(fd, &line);
	free(line);
	w = ft_count_of_worlds(line);
	while (get_next_line(fd, &line) > 0)
	{
		if (ft_count_of_worlds(line) != w)
		{
			free(line);
			return (-1);
		}
		free(line);
	}	
	if (ft_count_of_worlds(line) != w)
	{
		free(line);
		return (-1);
	}
	close(fd);
	free(line);
	return (w);
}
