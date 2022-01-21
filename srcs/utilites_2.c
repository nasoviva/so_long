/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilites_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hverda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:41:24 by hverda            #+#    #+#             */
/*   Updated: 2021/10/05 14:41:26 by hverda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_nbr(long int nbr)
{
	int			j;
	long int	n;

	j = 1;
	n = nbr;
	while (n >= 10)
	{
		j++;
		n = n / 10;
	}
	return (j);
}

char	*ft_str(long int n, char *str, int i)
{
	if (str == 0)
		return (0);
	str[i + 1] = '\0';
	while (i >= 0)
	{
		str[i] = n % 10 + '0';
		i--;
		n = n / 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			i;
	int			j;

	i = 0;
	j = ft_nbr(n);
	str = malloc(sizeof(*str) * (j + 1));
	if (str == 0)
		return (0);
	while (i < j - 1)
		i++;
	str = ft_str(n, str, i);
	return (str);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr_n(char *s, int c)
{
	int		i;
	char	*dst;

	dst = s;
	if (!dst)
		return (NULL);
	i = 0;
	while (dst[i])
	{
		if (dst[i] == (char)c)
			return ((char *)(dst + i));
		i++;
	}
	if (dst[i] == (char)c)
		return ((char *)(dst + i));
	return (NULL);
}
