/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaveric <emaveric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 21:11:40 by emaveric          #+#    #+#             */
/*   Updated: 2019/07/25 20:03:26 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_FILLIT_H
#define FILLIT_FILLIT_H

# define BUFF_SIZE 545
# include <fcntl.h>
# include "libft/libft.h"

typedef struct	tetrimo_list
{
	int 				frog;
	int 				jaba;
	int 				**coord;
	struct tetrimo_list	*next;
	struct tetrimo_list	*prev;
}						tet_list;

int		ft_is_figure_valid(char *buf);
int 	ft_figure_coordinates(const char *buf);
int 	test();

#endif //FILLIT_FILLIT_H
