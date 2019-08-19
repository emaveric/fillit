/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaveric <emaveric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 21:03:30 by emaveric          #+#    #+#             */
/*   Updated: 2019/08/18 15:48:24 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

static int 	ft_is_file_valid(int argc, char **argv, char *buf, int *sharp_num)
{
	int		fd;
	int		read_ch;

	if (argc != 2)
		return (-1);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0 || (read_ch = read(fd, buf, BUFF_SIZE)) > 545 || (read_ch) < 20)
		return (-1);
	if (ft_is_figure_valid(buf, sharp_num) == -1)
		return (-1);
	printf("%d simv\n\n", read_ch);
	printf("%s\n", buf);
	return (0);
}

/*static int 	**new_arr()
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

static tet_list		*ft_new_tet_list()
{
	tet_list *new;

	new = malloc(sizeof(tet_list));
	new->coord = ft_new_arr();
	new->next = NULL;
	new->prev = NULL;
	return (new);
}*/

int			main(int argc, char **argv)
{
	int 		sharp_num;
	char		buf[BUFF_SIZE + 1];
	tet_list	*head;

	sharp_num = 0;
	head = NULL;
	if (ft_is_file_valid(argc, argv, buf, &sharp_num) == -1)
	{
		ft_putstr("error\n");
		return (-1);
	}
	//printf ("\n\nNUM_SHARP %d\n\n", sharp_num);
	ft_figure_coordinates(buf, &head);
	printf ("NUM_SHARP %d\n\n", sharp_num);
	ft_new_field(buf, &head, sharp_num);
	return (0);
}