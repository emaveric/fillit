/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaveric <emaveric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 21:11:40 by emaveric          #+#    #+#             */
/*   Updated: 2019/08/25 17:48:01 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_FILLIT_H
#define FILLIT_FILLIT_H

# define BUFF_SIZE 545
# include <fcntl.h>
# include "libft/libft.h"
# include <stdio.h>

typedef struct	tetrimo_list
{
	int 				x_map;
	int 				y_map;
	int 				x_min;
	int 				y_min;
	int 				x_loc;
	int 				y_loc;
	int 				**coord;
	char 				letter;
	struct tetrimo_list	*next;
	struct tetrimo_list	*prev;
}						tet_list;

int		ft_is_figure_valid(char *buf, int *sharp_num);
int 	ft_figure_coordinates(const char *buf, tet_list	**head);
int 	ft_new_field(tet_list **head, int map_size);

#endif //FILLIT_FILLIT_H
