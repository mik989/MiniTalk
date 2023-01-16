/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 17:52:56 by mgirardi          #+#    #+#             */
/*   Updated: 2022/10/21 15:01:09 by mgirardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdint.h>
#include <stdio.h>
#include <stdarg.h>

int	printf_logic(char c, va_list args)
{
	int	count;

	if (c == 'c')
		return (ft_print_c((va_arg(args, int))));
	else if (c == 's')
		return (ft_print_s((va_arg(args, char *))));
	else if (c == 'p')
		return (ft_print_p((va_arg(args, unsigned long int)), 1));
	else if (c == 'i' || c == 'd')
		return (printf_putnbr_fd((va_arg(args, int)), 1));
	else if (c == 'u')
		return (ft_putnbr_baseu_fd((va_arg(args, unsigned int)), 1));
	else if (c == 'x')
		return (ft_putnbr_basex_fd((va_arg(args, unsigned int)), 1, 1));
	else if (c == 'X')
		return (ft_putnbr_basex_fd((va_arg(args, unsigned int)), 1, 0));
	else if (c == '%')
		return (printf_putchar_fd(c, 1));
	else
	{
		count = printf_putchar_fd('%', 1);
		return (count + printf_putchar_fd(c, 1));
	}
}

int	ft_printf_internal(const char *str, va_list args)
{
	int						count;

	count = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			count += printf_logic(*str, args);
		}
		else
			count += printf_putchar_fd(*str, 1);
		str++;
	}
	return (count);
}

int	ft_printf(const char *str, ...)

{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, str);
	if (!str)
		return (0);
	count = ft_printf_internal(str, args);
	va_end(args);
	return (count);
}
