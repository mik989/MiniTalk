/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 17:53:41 by mgirardi          #+#    #+#             */
/*   Updated: 2022/10/21 16:50:54 by mgirardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_putnbr_fd(int nb, int fd)
{
	int	nbr;
	int	n_char;

	if (nb < 0)
	{
		printf_putchar_fd('-', fd);
		nbr = (unsigned int)(nb * -1);
		n_char = 1;
	}
	else
	{
		nbr = (unsigned int)nb;
		n_char = 0;
	}
	n_char += ft_putnbr_baseu_fd(nbr, fd);
	return (n_char);
}
