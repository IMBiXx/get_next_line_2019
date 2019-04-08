/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valecart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 13:52:24 by valecart          #+#    #+#             */
/*   Updated: 2019/04/08 11:28:04 by valecart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_str_is_printable(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 32 && str[i] <= 126)
			i++;
		else
			return (0);
	}
	return (1);
}

static void		ft_putnbr_base_print(long int nbr, int len, char *base)
{
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr = nbr * -1;
	}
	if (nbr < len)
		ft_putchar(base[nbr]);
	else
	{
		ft_putnbr_base_print(nbr / len, len, base);
		ft_putnbr_base_print(nbr % len, len, base);
	}
}

static int		ft_check_base(char *base)
{
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 1;
	len = ft_strlen(base);
	while (base[i])
	{
		while (base[i] != base[j] && base[j])
			j++;
		if (j != len)
			return (0);
		i++;
		j = i + 1;
	}
	return (1);
}

void			ft_putnbr_base(int nbr, char *base)
{
	int			len;
	int			i;
	long int	lnbr;

	lnbr = nbr;
	i = 0;
	if ((len = ft_strlen(base)) > 1)
	{
		while (base[i])
		{
			if (base[i] == '+' || base[i] == '-' || \
					ft_str_is_printable(base) == 0)
				return ;
			i++;
		}
		if (ft_check_base(base) == 1)
			ft_putnbr_base_print(lnbr, len, base);
	}
}
