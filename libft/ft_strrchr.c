/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Valentin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 15:45:40 by Valentin          #+#    #+#             */
/*   Updated: 2019/04/02 17:47:29 by valecart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	find;
	int				i;

	i = ft_strlen(s);
	find = c;
	if (find == '\0')
		return ((char*)&s[i]);
	while (i >= 0)
	{
		if (s[i] == find)
			return ((char*)&s[i]);
		i--;
	}
	return (NULL);
}
