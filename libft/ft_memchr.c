/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaveric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 22:06:05 by emaveric          #+#    #+#             */
/*   Updated: 2019/04/19 21:06:52 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*new;

	i = 0;
	new = (char *)s;
	while (i < n)
	{
		if ((unsigned char)new[i] == (unsigned char)c)
			return (new + i);
		i++;
	}
	return (0);
}
