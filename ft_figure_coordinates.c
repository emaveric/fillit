/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_figure_coordinates.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaveric <emaveric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 17:04:58 by emaveric          #+#    #+#             */
/*   Updated: 2019/08/20 14:47:25 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int 			**ft_new_arr()
{
	int		**new_arr;
	int		i;

	i = 0;
	if (!(new_arr = (int**)malloc(sizeof(int*) * 4)))
		return (-1);
	while (i < 4)
	{
		if (!(new_arr[i] = (int*)malloc(sizeof(int) * 2)))
			return (-1);
		i++;
	}
	return (new_arr);
}

static tet_list		*ft_new_tet_list(char letter)
{
	tet_list *new;

	if (!(new = malloc(sizeof(tet_list))))
		return (-1);
	if (!(new->coord = ft_new_arr()))
		return (-1);
	new->letter = letter;
	new->next = NULL;
	new->prev = NULL;
	new->x_map = 0;
	new->y_map = 0;
	new->x_loc = 0;
	new->y_loc = 0;
	return (new);
}

void				ft_coord_search(const char *buf, tet_list *temp)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < 20)
	{
		if (*(buf + i++) == '#')
		{
			if (temp->y_min > i / 5)
				temp->y_min = i / 5;
			if (temp->x_min > i % 5)
				temp->x_min = i % 5;
		}
	}
	printf("X_MIN %d Y_MIN %d\n",temp->x_min, temp->y_min);
	i = 0;
	while (i < 20)
	{
		if (*(buf + i++) == '#')
		{
			printf("%d (y) %d (x)\n", (i / 5), (i % 5));
		/*	temp->coord[j][0] = i / 5;
			temp->coord[j][1] = i % 5;*/
			temp->coord[j][0] = i / 5 - temp->y_min;
			temp->coord[j][1] = i % 5 - temp->x_min;
			printf("NEW %d (y) %d (x)\n", (i / 5 - temp->y_min), (i % 5 - temp->x_min));
			j++;
		}
	}
	printf("\n");
}

int 				ft_figure_coordinates(const char *buf, tet_list	**head)
{
	int 		i;
	char 		letter;
	tet_list	*temp;
	tet_list	*div;

	i = 0;
	letter = 'A';
	if (!(temp = ft_new_tet_list(letter)))
		return (-1);
	*head = temp;
	while (buf[i] != '\0')
	{
		letter++;
		if (!(temp->next = ft_new_tet_list(letter)))
			return (-1);
		div = temp;
		temp->x_min = 3;
		temp->y_min = 3;
		ft_coord_search(buf + i, temp);
		temp = temp->next;
		temp->prev = div;
		i += 21;
	}
	return (0);
}