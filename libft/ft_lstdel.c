/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaveric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 19:46:06 by emaveric          #+#    #+#             */
/*   Updated: 2019/04/21 16:24:50 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	if (del && alst)
	{
		if (*alst)
		{
			if ((*alst)->next)
				ft_lstdel((&(*alst)->next), del);
			ft_lstdelone(&(*alst), del);
		}
	}
}
