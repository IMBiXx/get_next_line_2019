/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valecart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 20:20:49 by valecart          #+#    #+#             */
/*   Updated: 2019/04/08 10:33:36 by valecart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	char	tmp;
	int		max;
	int		i;

	max = 0;
	i = 0;
	while (str[max])
		max++;
	max--;
	while (i < max)
	{
		tmp = str[max];
		str[max] = str[i];
		str[i] = tmp;
		max--;
		i++;
	}
	return (str);
}
