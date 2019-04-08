/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valecart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 14:08:36 by valecart          #+#    #+#             */
/*   Updated: 2019/04/05 15:31:27 by valecart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list		*li;
	t_list		*nxt;

	li = *alst;
	while (li)
	{
		nxt = li->next;
		del(li->content, li->content_size);
		free(li);
		li = nxt;
	}
	*alst = NULL;
}
