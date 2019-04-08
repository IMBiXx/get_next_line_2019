/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Valentin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 02:50:45 by Valentin          #+#    #+#             */
/*   Updated: 2019/03/09 02:51:19 by Valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	numb;

	numb = n;
	if (n < 0)
		ft_putchar_fd('-', fd);
	numb = (n < 0) ? -n : n;
	if (numb > 9)
		ft_putnbr_fd(numb / 10, fd);
	ft_putchar_fd(numb % 10 + '0', fd);
}
