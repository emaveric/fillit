/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_field.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaveric <emaveric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 15:50:35 by emaveric          #+#    #+#             */
/*   Updated: 2019/08/02 16:55:35 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int 	ft_new_field(const char *buf, tet_list **head)
{
	int			i;
	int 		j;
	int 		k;
	tet_list	*temp;
	char 		**map;

	i = 0;
	j = 0;
	k = 0;
	temp = *head;
	map = (char**)malloc(sizeof(char*) * 4);
	while (i < 4)
	{
		map[i] = ft_memalloc(5);
		i++;
	}
	i = 0;
	while (temp->next != NULL)
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
	}
	return (0);
}