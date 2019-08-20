/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_field.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaveric <emaveric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 15:50:35 by emaveric          #+#    #+#             */
/*   Updated: 2019/08/20 14:54:33 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	ft_map_search(tet_list *temp, char **map, int map_size, tet_list **head);
static char **algoritm(tet_list *temp, char **map, int map_size, tet_list **head);

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

static void	ft_map_rebuild(tet_list *temp, char **map, int map_size, tet_list **head)
{
	int 	i;
	int 	j;

	i = 0;
	j = 0;
	temp->x_loc = 0;
	temp->y_loc = 0;
	temp->x_map = 0;
	temp->y_map = 0;
	temp = temp->prev;
	if (temp == NULL)
	{
		while (j < map_size)
		{
			ft_strdel(&map[j]);
			j++;
		}
		ft_new_field(head, ++map_size);
	/*	map = ft_new_map(++map_size);
		algoritm(*head, map, map_size, head);*/
	}
	while (j < map_size)
	{
		while (i < map_size)
		{
			if (map[j][i] == temp->letter)
				map[j][i] = '.';
			i++;
		}
		i = 0;
		j++;
	}
	algoritm(temp, map, map_size, head);
}

static void	ft_map_search(tet_list *temp, char **map, int map_size, tet_list **head)
{
	int 	i;
	int 	j;

	i = temp->x_loc;
	j = temp->y_loc;
	while (j < map_size)
	{
		while (i < map_size)
		{
			if (map[j][i] == '.')
			{
				temp->x_map = i;
				temp->y_map = j;
				break;
			}
			i++;
		}
		if (i < map_size)
			break;
		i = 0;
		j++;
	}
	if (j == map_size)
		ft_map_rebuild(temp, map, map_size, head);
	printf("\nLOC Y %d LOC X %d\n",temp->y_loc, temp->x_loc);
	printf("J %d I %d\n", j, i);
	temp->x_loc = temp->x_map + 1;
	temp->y_loc = temp->y_map;
}

static char **algoritm(tet_list *temp, char **map, int map_size, tet_list **head)
{
	int 	j;

	j = 0;
	ft_map_search(temp, map, map_size, head);
	/*printf("\nX_MAP %d Y_MAP %d\n",temp->x_map, temp->y_map);
	printf("%d %d\n", temp->x_map, temp->y_map);*/
	while (j < 4)
	{
		printf("\nX_MAP %d Y_MAP %d\n",temp->x_map, temp->y_map);
		printf("%d %d\n", temp->x_map, temp->y_map);
		if (map[temp->y_map][temp->x_map] == '.')
		{
			if (j == 3)
				break;
			if (temp->coord[j + 1][0] > temp->coord[j][0])
				temp->y_map += 1;
			if (temp->coord[j + 1][1] > temp->coord[j][1])
				temp->x_map += 1;
			else if (temp->coord[j + 1][1] < temp->coord[j][1])
				temp->x_map -= temp->coord[j][1] - temp->coord[j + 1][1];
			j++;
			if (temp->y_map == map_size || temp->x_map == map_size)
			{
				ft_map_search(temp, map, map_size, head);
				j = 0;
			}
		}
		else
		{
			ft_map_search(temp, map, map_size, head);
			j = 0;
		}
	}
	printf("X %d Y %d\n", temp->x_map, temp->y_map);
	if (j == 3)
	{
		map[temp->y_map][temp->x_map] = temp->letter;
		while (j > 0)
		{
			j--;
			if (temp->coord[j][1] < temp->coord[j + 1][1])
				temp->x_map -= 1;
			else if (temp->coord[j][1] > temp->coord[j + 1][1])
				temp->x_map += temp->coord[j][1] - temp->coord[j + 1][1];
			if (temp->coord[j][0] < temp->coord[j + 1][0])
				temp->y_map -= 1;
			map[temp->y_map][temp->x_map] = temp->letter;
		}
	}
	j = 0;
	while (j < map_size)
	{
		printf("%s", map[j]);
		j++;
	}
	return(map);
}

int			ft_new_field(tet_list **head, int map_size)
{
	tet_list	*temp;
	char 		**map;

	temp = *head;
	map = ft_new_map(map_size);
	while (temp->next != NULL)
	{
		map = algoritm(temp, map, map_size, head);
		temp = temp->next;
	}
	return (0);
}