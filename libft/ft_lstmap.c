/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valecart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 19:16:15 by valecart          #+#    #+#             */
/*   Updated: 2019/04/05 19:48:24 by valecart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*new;
	t_list		*ret;
	t_list		*start;

	if (!lst || !f)
		return (NULL);
	new = f(lst);
	if (!(ret = ft_lstnew(new->content, new->content_size)))
		return (NULL);
	lst = lst->next;
	start = ret;
	while (lst)
	{
		new = f(lst);
		if (!(ret->next = ft_lstnew(new->content, new->content_size)))
			return (NULL);
		lst = lst->next;
		ret = ret->next;
	}
	return (start);
}
