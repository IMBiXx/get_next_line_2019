/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Valentin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 01:49:33 by Valentin          #+#    #+#             */
/*   Updated: 2019/04/02 15:33:13 by valecart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		if (((const unsigned char*)s1)[i] == ((const unsigned char*)s2)[i])
			i++;
		else
			return (((const unsigned char*)s1)[i] - \
					((const unsigned char*)s2)[i]);
	}
	return (0);
}
