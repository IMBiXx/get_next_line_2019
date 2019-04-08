/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Valentin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 17:38:30 by Valentin          #+#    #+#             */
/*   Updated: 2019/04/03 13:02:18 by valecart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dest;
	char	*source;

	dest = dst;
	source = (void*)src;
	if (dest <= source)
		return (ft_memcpy(dst, src, len));
	while (len > 0)
	{
		len--;
		dest[len] = source[len];
	}
	return (dst);
}
