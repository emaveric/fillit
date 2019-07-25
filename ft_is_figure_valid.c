/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_figure_valid.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaveric <emaveric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 16:48:28 by emaveric          #+#    #+#             */
/*   Updated: 2019/07/24 20:03:54 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int 	ft_sum_valid(const char *buf)
{
	int		sum_dot;
	int 	sum_sharp;
	int 	sum_n;
	int		i;

	sum_dot = 0;
	sum_sharp = 0;
	sum_n = 0;
	i = 0;
	while (i < 20)
	{
		if (*(buf + i) == '.')
			sum_dot++;
		if (*(buf + i) == '#')
			sum_sharp++;
		if (*(buf + i) == '\n')
			sum_n++;
		i++;
	}
	if (sum_sharp != 4 || sum_dot != 12 || sum_n != 4)
		return (-1);
	printf("%d %d %d\n",sum_dot, sum_sharp, sum_n);
	return (0);
}

static int 	ft_sum_con(const char *buf)
{
	int 	i;
	int 	sum_con;

	i = 0;
	sum_con = 0;
	while (i < 20)
	{
		if (*(buf + i) == '#' && *(buf + i - 1) == '#')
			sum_con++;
		if (*(buf + i) == '#' && *(buf + i + 1) == '#')
			sum_con++;
		if (*(buf + i) == '#' && *(buf + i - 5) == '#')
			sum_con++;
		if (*(buf + i) == '#' && *(buf + i + 5) == '#')
			sum_con++;
		i++;
	}
	printf("%d (svazi)\n", sum_con);
	if (sum_con == 6 || sum_con == 8)
		return (0);
	return (-1);
}

static int 	ft_is_gap_valid(const char *buf)
{

	if ((*(buf - 1) == '\n' && *buf != '\n') || *(buf - 1) == '\0')
		return (0);
	return (-1);
}

int 		ft_is_figure_valid(char *buf)
{
	int 	i;

	i = 0;
	while (buf[i] != '\0')
	{
		if (ft_sum_valid(buf + i) == -1 || ft_sum_con(buf + i) == -1 ||
			ft_is_gap_valid(buf + i + 21))
			return (-1);
		i += 21;
		printf("%d i\n", i);
	}
	return (0);
}