/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valecart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 22:20:02 by valecart          #+#    #+#             */
/*   Updated: 2019/04/08 11:30:31 by valecart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_strlenspace(char *str)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
		i++;
	return (i);
}

static int		ft_count_words(char *str)
{
	int		i;
	int		words;

	words = 1;
	i = 0;
	while (str[i])
	{
		if (((str[i] == ' ' || str[i] == '\t' || str[i] == '\n') && str[i + 1]\
					&& (str[i + 1] != ' ' && str[i + 1] != '\t' && \
						str[i + 1] != '\n')) || (str[i] == '\t' && \
						str[i + 1] != ' ' && str[i + 1] != '\t' && \
						str[i + 1] != '\n' && str[i + 1]) || (str[i] == '\n' \
							&& str[i + 1] != ' ' && str[i + 1] != '\t' && \
							str[i + 1] != '\n' && str[i + 1]))
		{
			words++;
		}
		i++;
	}
	if (str[0] == ' ' || str[0] == '\t' || str[0] == '\n')
		words--;
	return (words);
}

static char		*rostring(char *str)
{
	size_t	i;
	int		j;
	char	*dest;

	i = 0;
	j = 0;
	dest = (char*)malloc(sizeof(dest) * ft_strlen(str) + 1);
	while (str && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
		i++;
	if (i == ft_strlen(str))
		return (dest);
	while (str && str[i])
	{
		if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		{
			dest[j++] = ' ';
			while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
				i++;
		}
		else
			dest[j++] = str[i++];
	}
	dest[j - 1] == ' ' ? dest[j - 1] = '\0' : 1;
	dest[j] = '\0';
	return (dest);
}

char			**ft_split_whitespaces(char *str)
{
	char	**tab;
	int		i;
	int		k;
	int		j;
	char	*new;

	i = 0;
	j = 0;
	k = 0;
	new = ft_strdup(rostring(str));
	tab = (char **)malloc(sizeof(char**) * ft_count_words(str) + 1);
	while (i < ft_count_words(str))
	{
		tab[i] = (char*)malloc(sizeof(tab[i]) * ft_strlenspace(&new[k]));
		while (new[k] != ' ' && new[k])
			tab[i][j++] = new[k++];
		tab[i][j] = '\0';
		j = 0;
		i++;
		k++;
	}
	tab[i] = 0;
	return (tab);
}
