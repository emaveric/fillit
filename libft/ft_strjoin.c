/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaveric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 22:15:01 by emaveric          #+#    #+#             */
/*   Updated: 2019/04/13 14:46:33 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = -1;
	j = -1;
	if (s1 != NULL && s2 != NULL)
	{
		str = (char *)malloc(sizeof(char) *
			(ft_strlen(s1) + ft_strlen(s2) + 1));
		if (str == NULL)
			return (0);
		while (s1[++i] != '\0')
			str[i] = s1[i];
		while (s2[++j] != '\0')
			str[i++] = s2[j];
		str[i] = '\0';
		return (str);
	}
	else
		return (0);
}
