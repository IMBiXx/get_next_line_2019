/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Valentin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 02:43:44 by Valentin          #+#    #+#             */
/*   Updated: 2019/03/09 02:50:36 by Valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	unsigned int	numb;

	numb = n;
	if (n < 0)
		ft_putchar('-');
	numb = (n < 0) ? -n : n;
	if (numb > 9)
		ft_putnbr(numb / 10);
	ft_putchar(numb % 10 + '0');
}
