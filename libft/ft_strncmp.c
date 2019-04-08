/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Valentin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 17:54:21 by Valentin          #+#    #+#             */
/*   Updated: 2019/04/03 15:57:21 by valecart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (0);
	n--;
	while ((s1[i] == s2[i] && (s1[i] && s2[i])) && i < n)
		i++;
	return (((unsigned char*)s1)[i] - ((unsigned char*)s2)[i]);
}
