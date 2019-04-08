/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Valentin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 15:27:08 by Valentin          #+#    #+#             */
/*   Updated: 2019/03/06 15:29:01 by Valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int		i;
	unsigned int		j;
	unsigned int		max;
	int					initialdest;

	initialdest = ft_strlen(dest);
	i = 0;
	j = 0;
	max = 0;
	while (dest[max])
		max++;
	i = max;
	while (src[j] && j + initialdest < size - 1 && (size != 0))
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (size > max)
		dest[i] = '\0';
	i = ft_strlen(src);
	if ((int)size < initialdest)
		return (i + size);
	return (i + initialdest);
}
