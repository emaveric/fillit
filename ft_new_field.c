/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_field.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaveric <emaveric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 15:50:35 by emaveric          #+#    #+#             */
/*   Updated: 2019/08/15 17:24:49 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char	**ft_new_map(int map_size)
{
	int		i;
	int		j;
	char	**map;

	i = 0;
	j = 0;
	map = (char**)malloc(sizeof(char*) * map_size);
	while (i < map_size)
	{
		map[i] = ft_memalloc(map_size + 1);
		i++;
	}
	i = 0;
	while (j < map_size)
	{
		while (i < map_size + 1)
		{
			if (i == map_size)
				map[j][i] = '\n';
			else
				map[j][i] = '.';
			i++;
		}
		i = 0;
		j++;
	}
	return (map);
}

static char **algoritm(tet_list *temp, char **map, int map_size)
{
	int 	i;
	int 	j;

	i = 0;
	j = 0;
	while (j < map_size)
	{
		while (i < map_size)
		{
			if (map[j][i] == '#' && j <= temp->y_min)
			{
				temp->x_min = i + 1;
				temp->y_min = j;
			}
			i++;
		}
		i = 0;
		j++;
	}
	printf("\nX_MIN %d Y_MIN %d\n",temp->x_min, temp->y_min);
	j = 0;
	if (temp->x_min < map_size && temp->y_min < map_size)
	{
		j++;
		temp->x_min += temp->coord[j][1];
		temp->y_min += temp->coord[j][0];
	}
	printf("%d %d\n", temp->x_min, temp->y_min);
	while (j < 3)
	{
		if (map[temp->y_min][temp->x_min] == '.')
		{
			j++;
			if (temp->coord[j][0] > temp->coord[j - 1][0])
				temp->y_min += 1;
			if (temp->coord[j][1] > temp->coord[j - 1][1])
				temp->x_min += 1;
			else if (temp->coord[j][1] < temp->coord[j - 1][1])
				temp->x_min = temp->coord[j - 1][1] - temp->coord[j][1];
		}
	}
	printf("X %d Y %d\n", temp->x_min, temp->y_min);
	if (j == 3)
		while (j >= 0)
		{
			map[temp->y_min][temp->x_min] = '#';
			j--;
			if (temp->coord[j][1] < temp->coord[j + 1][1])
				temp->x_min -= 1;
			else if (temp->coord[j][1] > temp->coord[j + 1][1])
				temp->x_min = temp->coord[j][1] + temp->coord[j + 1][1];
			if (temp->coord[j][0] < temp->coord[j + 1][0])
				temp->y_min -= 1;
		}
	j = 0;
	while (j < map_size)
	{
		printf("%s", map[j]);
		j++;
	}
	return(map);
}

int 		ft_new_field(const char *buf, tet_list **head, int sharp_num)
{
	int			i;
	int 		k;
	int 		map_size;
	tet_list	*temp;
	char 		**map;

	i = 0;
	k = 0;
	map_size = 2;
	temp = *head;
	while (map_size * map_size <= sharp_num)
		map_size++;
	map = ft_new_map(map_size);
/*	while (temp->next != NULL)
	{
		while (j < 4)
		{
			while (i < 5)
			{
				if (k != 4 && temp->coord[k][0] == j && temp->coord[k][1] == i)
				{
					map[j][i] = '#';
					k++;
				}
				else if (i == 4)
					map[j][i] = '\n';
				else
					map[j][i] = '.';
				i++;

			}
			printf("%s", map[j]);
			i = 0;
			j++;
		}
		printf("\n");
		j = 0;
		k = 0;
		temp = temp->next;
	}*/
		while (i < map_size)
		{
			if (map[temp->coord[k][0]][temp->coord[k][1]] == '.')
				k++;
			i++;
		}
		if (k == map_size)
		{
			k = 0;
			while (k < 4)
			{
				map[temp->coord[k][0]][temp->coord[k][1]] = '#';
				k++;
			}
		}
		k = 0;
		while (k < map_size)
		{
			printf("%s", map[k]);
			k++;
		}
		k = 0;
		i = 0;
		temp = temp->next;
		while (temp->next != NULL)
		{
			map = algoritm(temp, map, map_size);
			temp = temp->next;
		}
	return (0);
}