/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_figure_coordinates.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaveric <emaveric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 17:04:58 by emaveric          #+#    #+#             */
/*   Updated: 2019/07/25 21:42:39 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int 	**new_arr()
{
	int **new_arr;
	int i;

	i = 0;
	new_arr = (int**)malloc(sizeof(int*) * 4);
	while (i < 4)
	{
		new_arr[i] = (int*)malloc(sizeof(int) * 2);
		i++;
	}
	return (new_arr);
}

static tet_list		*new_tet_list()
{
	tet_list *new;

	new = malloc(sizeof(tet_list));
	new->coord = new_arr();
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void		ft_cord_search(const char *buf, tet_list *temp)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < 20)
	{
		if (*(buf + i) == '#')
		{
			printf("%d (y) %d (x)\n", (i / 5), (i % 5));
			temp->coord[j][0] = i / 5;
			temp->coord[j][1] = i % 5;
			j++;
		}
		i++;
	}

}

int 		ft_figure_coordinates(const char *buf)
{
	int 		i;
	tet_list	*temp;
	tet_list	*div;

	i = 0;
	temp = new_tet_list();
	while (buf[i] != '\0')
	{
		temp->next = new_tet_list();
		div = temp;
		ft_cord_search(buf + i, temp);
		temp = temp->next;
		temp->prev = div;
		i += 21;
	}
	return (0);
}