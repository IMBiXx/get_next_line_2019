/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valecart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 11:13:56 by valecart          #+#    #+#             */
/*   Updated: 2019/04/04 13:23:50 by valecart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count_str(char const *s, char c)
{
	int			i;
	int			words;

	i = 0;
	words = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i - 1] == c || i == 0))
			words++;
		i++;
	}
	return (words);
}

static char		*write_str(char const *s, char c, int *current, char *str)
{
	int			i;
	int			wlen;

	wlen = 0;
	while (s[(*current)] == c && s[(*current)])
		(*current)++;
	while (s[wlen + *current] != c && s[*current + wlen])
		wlen++;
	str = ft_strnew(wlen + 1);
	if (!str)
		return (0);
	i = 0;
	while (s[(*current)] != c && s[(*current)])
	{
		str[i] = s[(*current)];
		(*current)++;
		i++;
	}
	str[i] = 0;
	return (str);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**tab;
	int			i;
	int			j;
	int			words;

	i = 0;
	j = 0;
	tab = 0;
	if (s)
	{
		words = count_str(s, c);
		tab = (char**)malloc(sizeof(char*) * (words + 1));
	}
	if (!tab)
		return (0);
	while (i < words)
	{
		tab[i] = write_str(s, c, &j, tab[i]);
		i++;
	}
	tab[i] = 0;
	return (tab);
}
