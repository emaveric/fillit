/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaveric <emaveric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 21:03:30 by emaveric          #+#    #+#             */
/*   Updated: 2019/07/24 17:02:29 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

static int 	ft_is_file_valid(int argc, char **argv)
{
	int		fd;
	int		read_ch;
	char	buf[BUFF_SIZE + 1];

	if (argc != 2)
		return (-1);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0 || (read_ch = read(fd, buf, BUFF_SIZE)) > 545 || (read_ch) < 20)
		return (-1);
	ft_is_figure_valid(buf);
	printf("%d simv\n\n", read_ch);
	printf("%s\n", buf);
	return (0);
}

int			main(int argc, char **argv)
{

	ft_is_file_valid(argc, argv);
	return (0);
}