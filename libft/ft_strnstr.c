/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Valentin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 16:07:55 by Valentin          #+#    #+#             */
/*   Updated: 2019/04/05 20:02:19 by valecart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	j;
	unsigned int	i;
	char			*ptr;

	ptr = (char*)haystack;
	j = 0;
	i = 0;
	if (needle[j] == '\0')
		return (ptr);
	while (*ptr != '\0' && i < len)
	{
		while (ptr[j] == needle[j])
		{
			if (i + j > len)
				return (0);
			j++;
			if (needle[j] == '\0')
				return (ptr);
		}
		ptr++;
		j = 0;
		i++;
	}
	return (0);
}
