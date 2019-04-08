/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valecart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 11:57:54 by valecart          #+#    #+#             */
/*   Updated: 2019/04/08 11:24:08 by valecart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstprint(t_list *li)
{
	if (!li)
	{
		ft_putendl("liste vide");
	}
	else
	{
		while (li)
		{
			ft_putendl(li->content);
			li = li->next;
		}
	}
}
