/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Valentin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 16:56:41 by Valentin          #+#    #+#             */
/*   Updated: 2019/04/05 12:36:02 by valecart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*parsing_trim(const char *s, char *new, int size)
{
	size_t		i;

	i = 0;
	if (size > 0)
	{
		if (!(new = ft_memalloc(size + 1)))
			return (NULL);
	}
	else
	{
		while ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n') && s[i])
			i++;
		if (i == ft_strlen(s))
		{
			if (!(new = ft_memalloc(1)))
				return (NULL);
			new[0] = '\0';
			return (new);
		}
	}
	i = 0;
	return (new);
}

char			*ft_strtrim(char const *s)
{
	char	*new;
	int		min;
	int		max;
	size_t	i;

	new = NULL;
	if (!s)
		return (NULL);
	i = 0;
	min = 0;
	max = ft_strlen(s) - 1;
	while ((s[min] == ' ' || s[min] == '\t' || s[min] == '\n') && s[min])
		min++;
	while ((s[max] == ' ' || s[max] == '\t' || s[max] == '\n') && max > min)
		max--;
	if (!(new = parsing_trim(s, new, max - min + 1)))
		return (NULL);
	while (min <= max)
	{
		new[i] = s[min];
		i++;
		min++;
	}
	new[i] = '\0';
	return (new);
}
